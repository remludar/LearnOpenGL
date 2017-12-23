#include "Game.h"
#include "InputManager.h"

InputManager* InputManager::m_pInstance = nullptr;

InputManager* InputManager::Instance()
{
	if (!m_pInstance)
	{
		m_pInstance = new InputManager;
	}
	return m_pInstance;
}

struct InputManager::Impl
{
	bool m_bIsEsc;
	bool m_bIsW;
	bool m_bIsA;
	bool m_bIsS;
	bool m_bIsD;
	bool m_bIsE;
	bool m_bIsQ;
};

//CONSTRUCTORS
InputManager::InputManager()
	: m_pImpl(new Impl())
{}
InputManager::~InputManager() = default;
InputManager::InputManager(const InputManager& other): m_pImpl(new Impl(*other.m_pImpl)){}
InputManager& InputManager::operator=(InputManager& rhs)
{
	swap(m_pImpl, rhs.m_pImpl);
	return *this;
}

void InputManager::ProcessInput()
{	
	GameWindow* gameWindow = Game::Instance()->GetGameWindow();
	GLFWwindow* window = gameWindow->GetGLFWWindow();
	Camera* camera = Game::Instance()->GetMainCamera();

	m_pImpl->m_bIsEsc = glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
	m_pImpl->m_bIsW = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
	m_pImpl->m_bIsA = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
	m_pImpl->m_bIsS = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
	m_pImpl->m_bIsD = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
	m_pImpl->m_bIsE = glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS;
	m_pImpl->m_bIsQ = glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS;

	

}

bool InputManager::isEsc()
{
	return m_pImpl->m_bIsEsc;
}
bool InputManager::IsW()
{
	return m_pImpl->m_bIsW;
}
bool InputManager::IsA()
{
	return m_pImpl->m_bIsA;
}
bool InputManager::IsS()
{
	return m_pImpl->m_bIsS;
}
bool InputManager::IsD()
{
	return m_pImpl->m_bIsD;
}
bool InputManager::IsE()
{
	return m_pImpl->m_bIsE;
}
bool InputManager::IsQ()
{
	return m_pImpl->m_bIsQ;
}
