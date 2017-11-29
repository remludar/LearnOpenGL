#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


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
	
	// setup vertex data
	// -----------------
	float vertices[] = {
		//positions				// text coords
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,
		+0.5f, -0.5f, -0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, +0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,

		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		+0.5f, -0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 1.0f,
		-0.5f, +0.5f, +0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,

		-0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		-0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		-0.5f, +0.5f, +0.5f,	1.0f, 0.0f,

		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, -0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, -0.5f, +0.5f,	1.0f, 0.0f,
		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,

		-0.5f, +0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		-0.5f, +0.5f, +0.5f,	0.0f, 0.0f,
		-0.5f, +0.5f, -0.5f,	0.0f, 1.0f
	};

	glm::vec3 cubePositions[] = {
		glm::vec3(+0.0f, +0.0f, +0.0f),
		glm::vec3(+2.0f, +5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(+2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, +3.0f, -7.5f),
		glm::vec3(+1.3f, -2.0f, -2.5f),
		glm::vec3(+1.5f, +2.0f, -2.5f),
		glm::vec3(+1.5f, +0.2f, -1.5f),
		glm::vec3(-1.3f, +1.0f, -1.5f)
	};

	unsigned int VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);


	// bind to vao
	glBindVertexArray(VAO);
	
	// bind to vbo and fill buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		
	// define the layout of the data in the vbo and enable the vertex attributes for the shader 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// unbind from vbo and vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// uncomment for wireframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	// setup texture data
	// ------------------
	stbi_set_flip_vertically_on_load(true);
	unsigned int texture[2];
	glGenTextures(2, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// grab texture image data
	int width, height, nrChannels;
	unsigned char *data = stbi_load("res/img/container.jpg", &width, &height, &nrChannels, 0);
	if(data)
	{
		// generate the texture2d object and mipmap
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	// free image data memory
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// grab texture image data
	data = stbi_load("res/img/awesomeface.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		// generate the texture2d object and mipmap
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	
	// free image data memory
	stbi_image_free(data);
	
	// activate shader
	ourShader.use();
	ourShader.setInt("texture1", 0);
	ourShader.setInt("texture2", 1);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBindVertexArray(VAO);

		glm::mat4 view;
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		ourShader.setMat4("view", view);

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);

		// render the triangle
		glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 10; i++)
		{
			//transformations
			glm::mat4 model;
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * (i + 1);
			model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			ourShader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);

		}
		

		// swap buffer and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}