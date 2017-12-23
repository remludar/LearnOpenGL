#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class GameWindow
{
//SINGLETON
public:
	static GameWindow* Instance();
private:
	GameWindow(){};
	GameWindow(GameWindow const&){};
	GameWindow& operator=(GameWindow const&){};
	static GameWindow* m_pInstance;


public:
	void Create(unsigned int width, unsigned int height, const char* title);
	void Render();
	void Update();
	void Close();

	// GETTERS
	unsigned int GetWidth()
	{
		return m_uiWidth;
	}
	unsigned int GetHeight()
	{
		return m_uiHeight;
	}
	GLFWwindow* GetGLFWWindow()
	{
		return m_pWindow;
	}

private:
	unsigned int m_uiWidth;
	unsigned int m_uiHeight;
	GLFWwindow* m_pWindow;


	
};

