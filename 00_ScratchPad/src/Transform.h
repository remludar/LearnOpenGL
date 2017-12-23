#pragma once

#include <glm/glm.hpp>

class Transform
{
private:
	glm::vec3 m_vec3Position;
	glm::vec3 m_vec3RotationAxis;
	float m_fRotationDegrees;
	glm::vec3 m_vec3Scale;

public:
	Transform();
	void Translate(glm::vec3 pos);
	void Rotate(float rotDegrees, glm::vec3 rotationAxis);
	void Scale(glm::vec3 scale);

	//GETTERS
	glm::vec3 GetPosition()
	{
		return m_vec3Position;
	}

	float GetRotationDegrees()
	{
		return m_fRotationDegrees;
	}

	glm::vec3 GetRotationAxis()
	{
		return m_vec3RotationAxis;
	}

	glm::vec3 GetScale()
	{
		return m_vec3Scale;
	}

	//SETTERS
	void SetPosition(glm::vec3 pos)
	{
		m_vec3Position = pos;
	}
};

