#include "Transform.h"



Transform::Transform()
{
	m_vec3Position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_vec3RotationAxis = glm::vec3(1.0f, 1.0f, 1.0f);
	m_fRotationDegrees = 0.0f;
	m_vec3Scale = glm::vec3(1.0f, 1.0f, 1.0f);
}


void Transform::Translate(glm::vec3 pos)
{
	m_vec3Position += pos;
}

void Transform::Rotate(float rotDegrees, glm::vec3 rotationAxis)
{
	m_fRotationDegrees = rotDegrees;
	m_vec3RotationAxis = rotationAxis;
}

void Transform::Scale(glm::vec3 scale)
{
	m_vec3Scale = scale;
}