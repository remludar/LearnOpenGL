#include "Game.h"

Game* Game::m_pInstance = nullptr;

// Singleton Constructor
Game* Game::Instance()
{
	if (!m_pInstance)
	{
		m_pInstance = new Game;
	}
	return m_pInstance;
}

void Game::Init()
{
	// GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Managers and Game-Wide objects
	m_pGameWindow = GameWindow::Instance();
	m_pGameWindow->Create(1600, 900, "ScratchPad");
	m_pInputManager = InputManager::Instance();
	m_pMainCamera = new Camera;

	// GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	// OpenGL
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // enable for wireframe

}

void Game::AddGameObject(GameObject* gameObject)
{
	m_vpGameObjects.push_back(gameObject);
}

void Game::Run()
{
	while (!glfwWindowShouldClose(m_pGameWindow->GetGLFWWindow()))
	{
		m_pInputManager->ProcessInput();
		m_pGameWindow->Render();
		m_pMainCamera->Update();
		for each (GameObject* gameObject in m_vpGameObjects)
		{
			gameObject->Render();
		}
		
		m_pGameWindow->Update();
	}
}


