#pragma once

//#include <GLFW/glfw3.h>

#include <memory>

class InputManager
{
//SINGLETON
public:
	static InputManager* Instance();
private:
	InputManager();
	InputManager(const InputManager& other);
	InputManager& operator=(InputManager& rhs);
	static InputManager* m_pInstance;


public:
	~InputManager();

	void ProcessInput();
	bool isEsc();
	bool IsW();
	bool IsA();
	bool IsS();
	bool IsD();
	bool IsE();
	bool IsQ();

	bool IsFirstMouse();
	float GetLastMouseX();
	float GetLastMouseY();
	float GetPitch();
	float GetYaw();

	void SetIsFirstMouse(bool b);
	void SetLastMouseX(float x);
	void SetLastMouseY(float y);
	void SetPitch(float p);
	void SetYaw(float y);

private:
	struct Impl;
	std::unique_ptr<Impl> m_pImpl;
};

