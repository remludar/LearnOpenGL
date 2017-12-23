#include "InputManager.h"
#include "Camera.h"

Camera::Camera()
{
	this->GetTransform()->SetPosition(glm::vec3(0.0f, 0.0f, 3.0f));
	m_vec3Front = glm::vec3(0.0f, 0.0f, -1.0f);
	m_vec3Up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_fFOV = 45.0f;
	m_fNearPlane = 0.01f;
	m_fFarPlane = 100.0f;
	m_fSpeed = 0.05f;
}

Camera::~Camera() = default;

void Camera::Update()
{	
	auto inputManager = InputManager::Instance();
	if (inputManager->IsW())
		GetTransform()->Translate(m_fSpeed * m_vec3Front);
	if (inputManager->IsS())
		GetTransform()->Translate(-m_fSpeed * m_vec3Front);
	if (inputManager->IsA())
		GetTransform()->Translate(-glm::normalize(glm::cross(m_vec3Front, m_vec3Up)) * m_fSpeed);
	if (inputManager->IsD())
		GetTransform()->Translate(glm::normalize(glm::cross(m_vec3Front, m_vec3Up)) * m_fSpeed);
	if (inputManager->IsE())
		GetTransform()->Translate(m_fSpeed * m_vec3Up);
	if (inputManager->IsQ())
		GetTransform()->Translate(-m_fSpeed * m_vec3Up);
}