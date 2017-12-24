#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

#include <iostream>

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0, 1.0f, 0.0f);
glm::vec3 lightPos(1.2f, 1.0f, -2.0f);

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float lastX = 400, lastY = 300;
float pitch = 0.0f, yaw = -90.0f;
bool firstMouse = true;
float fov = 45.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

int main()
{
	// glfw init and configure
	// -----------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// glad load all OpenGL function pointers
	// --------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// create shader
	Shader ourShader("res/shaders/vertex.shader", "res/shaders/fragment.shader");
	Shader lampShader("res/shaders/lampVertex.shader", "res/shaders/lampFragment.shader");

	// setup vertex data
	// -----------------
	float vertices[] = {
		//positions				//normals
		-0.5f, -0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,
		+0.5f, -0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,
		+0.5f, +0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,
		+0.5f, +0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,
		-0.5f, +0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,

		-0.5f, -0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,
		+0.5f, -0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,
		+0.5f, +0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,
		+0.5f, +0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,
		-0.5f, +0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,
		-0.5f, -0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,

		-0.5f, +0.5f, +0.5f, 	-1.0f, +0.0f, +0.0f,
		-0.5f, +0.5f, -0.5f, 	-1.0f, +0.0f, +0.0f,
		-0.5f, -0.5f, -0.5f, 	-1.0f, +0.0f, +0.0f,
		-0.5f, -0.5f, -0.5f, 	-1.0f, +0.0f, +0.0f,
		-0.5f, -0.5f, +0.5f, 	-1.0f, +0.0f, +0.0f,
		-0.5f, +0.5f, +0.5f, 	-1.0f, +0.0f, +0.0f,

		+0.5f, +0.5f, +0.5f,	+1.0f, +0.0f, +0.0f,
		+0.5f, +0.5f, -0.5f,	+1.0f, +0.0f, +0.0f,
		+0.5f, -0.5f, -0.5f,	+1.0f, +0.0f, +0.0f,
		+0.5f, -0.5f, -0.5f,	+1.0f, +0.0f, +0.0f,
		+0.5f, -0.5f, +0.5f,	+1.0f, +0.0f, +0.0f,
		+0.5f, +0.5f, +0.5f,	+1.0f, +0.0f, +0.0f,

		-0.5f, -0.5f, -0.5f,	+0.0f, -1.0f, +0.0f,
		+0.5f, -0.5f, -0.5f,	+0.0f, -1.0f, +0.0f,
		+0.5f, -0.5f, +0.5f,	+0.0f, -1.0f, +0.0f,
		+0.5f, -0.5f, +0.5f,	+0.0f, -1.0f, +0.0f,
		-0.5f, -0.5f, +0.5f,	+0.0f, -1.0f, +0.0f,
		-0.5f, -0.5f, -0.5f,	+0.0f, -1.0f, +0.0f,

		-0.5f, +0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		+0.5f, +0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
		+0.5f, +0.5f, +0.5f,  0.0f,  1.0f,  0.0f,
		+0.5f, +0.5f, +0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f, +0.5f, +0.5f,  0.0f,  1.0f,  0.0f,
		-0.5f, +0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	};

	unsigned int VAO, lightVAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// bind to vao
	glBindVertexArray(VAO);

	// bind to vbo and fill buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// define the layout of the data in the vbo and enable the vertex attributes for the shader 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// unbind from vbo and vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// light stuff
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// uncomment for wireframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	


	float angle = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		//CONTAINER
		ourShader.use();
		ourShader.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
		ourShader.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
		ourShader.setVec3("lightPos", lightPos);

		glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		ourShader.setMat4("projection", projection);
		ourShader.setMat4("view", view);

		glm::mat4 model;
		ourShader.setMat4("model", model);
		
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//LAMP
		lampShader.use();
		lampShader.setMat4("projection", projection);
		lampShader.setMat4("view", view);
		model = glm::mat4();
		model = glm::translate(model, lightPos);
		model = glm::scale(model, glm::vec3(0.2f));
		lampShader.setMat4("model", model);
		
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//lightPos -= glm::vec3(0.5f, 0.0f, 0.0f) * deltaTime;
		float xPos = glm::cos(angle) * 4.0f;
		float zPos = glm::sin(angle) * 4.0f;
		lightPos = glm::vec3(xPos, 1.5f, zPos);
		angle += 1.0f * deltaTime;
		// swap buffer and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	float cameraSpeed = 5.0f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraUp;
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraUp;
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	if (fov >= 1.0f && fov <= 45.0f)
		fov -= yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
}