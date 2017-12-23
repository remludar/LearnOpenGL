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
}

void GameWindow::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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

void GameWindow::Close()
{
	
}
