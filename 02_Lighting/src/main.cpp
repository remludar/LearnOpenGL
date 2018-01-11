#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

#include <iostream>
#include <time.h>

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0, 1.0f, 0.0f);

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
unsigned int loadTexture(const char* path);

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
		//positions				//normals				//texture coords
		-0.5f, -0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,	+0.0f, +0.0f,
		+0.5f, -0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,	+1.0f, +0.0f,
		+0.5f, +0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,	+1.0f, +1.0f,
		+0.5f, +0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,	+1.0f, +1.0f,
		-0.5f, +0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,	+0.0f, +1.0f,
		-0.5f, -0.5f, -0.5f,	+0.0f, +0.0f, -1.0f,	+0.0f, +0.0f,

		-0.5f, -0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,	+0.0f, +0.0f,
		+0.5f, -0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,	+1.0f, +0.0f,
		+0.5f, +0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,	+1.0f, +1.0f,
		+0.5f, +0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,	+1.0f, +1.0f,
		-0.5f, +0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,	+0.0f, +1.0f,
		-0.5f, -0.5f, +0.5f,	+0.0f, +0.0f, +1.0f,	+0.0f, +0.0f,

		-0.5f, +0.5f, +0.5f, 	-1.0f, +0.0f, +0.0f,	+1.0f, +0.0f,
		-0.5f, +0.5f, -0.5f, 	-1.0f, +0.0f, +0.0f,	+1.0f, +1.0f,
		-0.5f, -0.5f, -0.5f, 	-1.0f, +0.0f, +0.0f,	+0.0f, +1.0f,
		-0.5f, -0.5f, -0.5f, 	-1.0f, +0.0f, +0.0f,	+0.0f, +1.0f,
		-0.5f, -0.5f, +0.5f, 	-1.0f, +0.0f, +0.0f,	+0.0f, +0.0f,
		-0.5f, +0.5f, +0.5f, 	-1.0f, +0.0f, +0.0f,	+1.0f, +0.0f,

		+0.5f, +0.5f, +0.5f,	+1.0f, +0.0f, +0.0f,	+1.0f, +0.0f,
		+0.5f, +0.5f, -0.5f,	+1.0f, +0.0f, +0.0f,	+1.0f, +1.0f,
		+0.5f, -0.5f, -0.5f,	+1.0f, +0.0f, +0.0f,	+0.0f, +1.0f,
		+0.5f, -0.5f, -0.5f,	+1.0f, +0.0f, +0.0f,	+0.0f, +1.0f,
		+0.5f, -0.5f, +0.5f,	+1.0f, +0.0f, +0.0f,	+0.0f, +0.0f,
		+0.5f, +0.5f, +0.5f,	+1.0f, +0.0f, +0.0f,	+1.0f, +0.0f,

		-0.5f, -0.5f, -0.5f,	+0.0f, -1.0f, +0.0f,	+0.0f, +1.0f,
		+0.5f, -0.5f, -0.5f,	+0.0f, -1.0f, +0.0f,	+1.0f, +1.0f,
		+0.5f, -0.5f, +0.5f,	+0.0f, -1.0f, +0.0f,	+1.0f, +0.0f,
		+0.5f, -0.5f, +0.5f,	+0.0f, -1.0f, +0.0f,	+1.0f, +0.0f,
		-0.5f, -0.5f, +0.5f,	+0.0f, -1.0f, +0.0f,	+0.0f, +0.0f,
		-0.5f, -0.5f, -0.5f,	+0.0f, -1.0f, +0.0f,	+0.0f, +1.0f,

		-0.5f, +0.5f, -0.5f,	+0.0f, +1.0f, +0.0f,	+0.0f, +1.0f,
		+0.5f, +0.5f, -0.5f,	+0.0f, +1.0f, +0.0f,	+1.0f, +1.0f,
		+0.5f, +0.5f, +0.5f,	+0.0f, +1.0f, +0.0f,	+1.0f, +0.0f,
		+0.5f, +0.5f, +0.5f,	+0.0f, +1.0f, +0.0f,	+1.0f, +0.0f,
		-0.5f, +0.5f, +0.5f,	+0.0f, +1.0f, +0.0f,	+0.0f, +0.0f,
		-0.5f, +0.5f, -0.5f,	+0.0f, +1.0f, +0.0f,	+0.0f, +1.0f
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// unbind from vbo and vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// light stuff
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// uncomment for wireframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//setup texture data
	//------------------
	unsigned int diffuseMap = loadTexture("res/img/container.png");
	unsigned int specularMap = loadTexture("res/img/container_specular.png");

	ourShader.use();
	ourShader.setInt("material.diffuse", 0);
	ourShader.setInt("material.specular", 1);

	srand(time(NULL));
	glm::vec3 cubePositions[] = {
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
		glm::vec3(rand() % 10 - 5, rand() % 10 - 5, -rand() % 10 - 5),
	};

	glm::vec3 pointLightPositions[] = {
		glm::vec3(+0.7f, rand() % 8 - 4, rand() % 8 - 4),
		glm::vec3(+2.3f, rand() % 8 - 4, rand() % 8 - 4),
		glm::vec3(-4.0f, rand() % 8 - 4, rand() % 8 - 4),
		glm::vec3(+0.0f, rand() % 8 - 4, rand() % 8 - 4)
	};

	float angles[] = {
		rand() % 100 - 200,
		rand() % 100 - 200,
		rand() % 100 - 200,
		rand() % 100 - 200
	};

	float angleDeltas[] = {
		rand() % 4 + (-2),
		rand() % 4 + (-2),
		rand() % 4 + (-2),
		rand() % 4 + (-2)
	};

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window);

		glClearColor(0.075f, 0.075f, 0.075f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//BLOCKS
		ourShader.use();


		ourShader.setVec3("viewPos", cameraPos);
		ourShader.setFloat("material.shininess", 64.0f);

		ourShader.setVec3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
		ourShader.setVec3("dirLight.ambient", glm::vec3(0.2f, 0.2f, 0.2f));
		ourShader.setVec3("dirLight.diffuse", glm::vec3(0.5f, 0.5f, 0.5f));
		ourShader.setVec3("dirLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));


		for (int i = 0; i < 4; i++)
		{
			ourShader.setVec3("pointLights[" + std::to_string(i) + "].position", pointLightPositions[i]);

			ourShader.setVec3("pointLights[" + std::to_string(i) + "].ambient", glm::vec3(0.2f, 0.2f, 0.2f));
			ourShader.setVec3("pointLights[" + std::to_string(i) + "].diffuse", glm::vec3(0.5f, 0.5f, 0.5f));
			ourShader.setVec3("pointLights[" + std::to_string(i) + "].specular", glm::vec3(1.0f, 1.0f, 1.0f));

			ourShader.setFloat("pointLights[" + std::to_string(i) + "].constant", 1.0f);
			ourShader.setFloat("pointLights[" + std::to_string(i) + "].linear", 0.09f);
			ourShader.setFloat("pointLights[" + std::to_string(i) + "].quadratic", 0.032f);
		}

		glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		ourShader.setMat4("projection", projection);
		ourShader.setMat4("view", view);
		glm::mat4 model;


		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularMap);

		for (unsigned int i = 0; i < 10; i++)
		{
			float angle = 20.0f * i;
			model = glm::translate(model, cubePositions[i]);
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 1.0f, 1.0f));

			ourShader.setMat4("model", model);

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
		}



		//LAMP
		lampShader.use();
		lampShader.setMat4("projection", projection);
		lampShader.setMat4("view", view);

		for (unsigned int i = 0; i < 4; i++)
		{
			angles[i] += angleDeltas[i] * deltaTime;
			pointLightPositions[i].x = sin(angles[i]) * 5;
			pointLightPositions[i].z = cos(angles[i]) * 5;

			model = glm::mat4();
			model = glm::translate(model, pointLightPositions[i]);
			model = glm::scale(model, glm::vec3(0.2f));
			lampShader.setMat4("model", model);
			glBindVertexArray(lightVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		
		

		

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

unsigned int loadTexture(const char* path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	// grab texture image data
	int width, height, nrChannels;
	unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data)
	{
		GLenum format;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;

		// generate the texture2d object and mipmap
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		stbi_image_free(data);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}