#pragma once

#include "GameObject.h"

class Camera : public GameObject
{
private:
	glm::vec3 m_vec3Front;
	glm::vec3 m_vec3Up;
	float m_fFOV;
	float m_fNearPlane;
	float m_fFarPlane;
	float m_fSpeed;

public:
	Camera();
	~Camera();

	void Update();

	//GETTERS
	glm::vec3 GetFront()
	{
		return m_vec3Front;
	}
	glm::vec3 GetUp()
	{
		return m_vec3Up;
	}
	float GetFOV()
	{
		return m_fFOV;
	}
	float GetNearPlane()
	{
		return m_fNearPlane;
	}
	float GetFarPlane()
	{
		return m_fFarPlane;
	}
	float GetSpeed()
	{
		return m_fSpeed;
	}
};