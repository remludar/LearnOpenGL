#pragma once

#include "GameWindow.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Camera.h"
#include <vector>

class Game
{
// SINGLETON
public:
	static Game* Instance();
private:
	Game(){};
	Game(Game const&){};
	Game& operator=(Game const&){};
	static Game* m_pInstance;

public:
	void Init();
	void AddGameObject(GameObject* gameObject);
	void Run();

	//GETTERS
	GameWindow* GetGameWindow()
	{
		return m_pGameWindow;
	}
	InputManager* GetInputManager()
	{
		return m_pInputManager;
	}
	Camera* GetMainCamera()
	{
		return m_pMainCamera;
	}

private:
	GameWindow* m_pGameWindow;
	InputManager* m_pInputManager;
	Camera* m_pMainCamera;
	std::vector<GameObject*> m_vpGameObjects;

};

