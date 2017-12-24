#include <glm/glm.hpp>

#include "Game.h"
#include "InputManager.h"
#include "GameWindow.h"

GameWindow* GameWindow::m_pInstance = nullptr;

GameWindow* GameWindow::Instance()
{
	if (!m_pInstance)
	{
		return new GameWindow;
	}
	return m_pInstance;
}

void GameWindow::Create(unsigned int width, unsigned int height, const char* title)
{
	m_uiWidth = width;
	m_uiHeight = height;
	m_pWindow = glfwCreateWindow(width, height, "ScratchPad", NULL, NULL);

	if (m_pWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_pWindow);
	glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);
	glfwSetInputMode(m_pWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(m_pWindow, mouse_callback);

	//Center the window
	auto vm = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowPos(m_pWindow, (vm->width / 2) - (m_uiWidth / 2), (vm->height / 2) - (m_uiHeight / 2));
}

void GameWindow::Render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameWindow::Update()
{
	auto inputManager = InputManager::Instance();

	if(inputManager->isEsc())
		glfwSetWindowShouldClose(m_pWindow, true);

	// swap buffer and poll IO events
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
}

void GameWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GameWindow::mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
	auto inputManager = InputManager::Instance();
	auto camera = Game::Instance()->GetMainCamera();
	
	if (inputManager->IsFirstMouse())
	{
		inputManager->SetLastMouseX(xpos);
		inputManager->SetLastMouseY(ypos);
		inputManager->SetIsFirstMouse(false);
	}

	float xoffset = xpos - inputManager->GetLastMouseX();
	float yoffset = inputManager->GetLastMouseY() - ypos;
	inputManager->SetLastMouseX(xpos);
	inputManager->SetLastMouseY(ypos);

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	inputManager->SetYaw(inputManager->GetYaw() + xoffset);
	inputManager->SetPitch(inputManager->GetPitch() + yoffset);

	if (inputManager->GetPitch() > 89.0f)
		inputManager->SetPitch(89.0f);
	if (inputManager->GetPitch() < -89.0f)
		inputManager->SetPitch(-89.0f);

	glm::vec3 front;
	front.x = cos(glm::radians(inputManager->GetYaw())) * cos(glm::radians(inputManager->GetPitch()));
	front.y = sin(glm::radians(inputManager->GetPitch()));
	front.z = sin(glm::radians(inputManager->GetYaw())) * cos(glm::radians(inputManager->GetPitch()));
	camera->SetFront(glm::normalize(front));
}