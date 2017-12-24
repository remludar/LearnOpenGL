#include "Game.h"
#include "GameObject.h"

struct GameObject::Impl
{
	Game* m_pGame;
	Transform* m_pTransform;
	Mesh* m_pMesh;
};

//CONSTRUCTORS
GameObject::GameObject()
	: m_pImpl(new Impl())
{
	m_pImpl->m_pTransform = new Transform();
	m_pImpl->m_pGame = Game::Instance();
}
GameObject::~GameObject()
{
	delete m_pImpl->m_pGame;
	delete m_pImpl->m_pTransform;
	delete m_pImpl->m_pMesh;
}
GameObject::GameObject(const GameObject& other): m_pImpl(new Impl(*other.m_pImpl))
{}
GameObject& GameObject::operator=(GameObject rhs)
{
	swap(m_pImpl, rhs.m_pImpl);
	return *this;
}

void GameObject::Update()
{

}
void GameObject::Render()
{
	//Local pointer variables
	Camera* camera = m_pImpl->m_pGame->GetMainCamera();
	glm::vec3 cameraPosition = camera->GetTransform()->GetPosition();

	GameWindow* gameWindow = m_pImpl->m_pGame->GetGameWindow();
	float width = gameWindow->GetWidth();
	float height = gameWindow->GetHeight();

	Shader* shader = m_pImpl->m_pMesh->GetMaterial()->GetShader();
	shader->use();

	//Projection Matrix
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(camera->GetFOV()), width / height, camera->GetNearPlane(), camera->GetFarPlane());
	shader->setMat4("projection", projection);

	//View matrix
	glm::mat4 view;
	view = glm::lookAt(cameraPosition, cameraPosition + camera->GetFront(), camera->GetUp());
	shader->setMat4("view", view);

	//Model matrix
	glm::mat4 model;
	model = glm::translate(model, m_pImpl->m_pTransform->GetPosition());
	model = glm::rotate(model, m_pImpl->m_pTransform->GetRotationDegrees(), m_pImpl->m_pTransform->GetRotationAxis());
	model = glm::scale(model, m_pImpl->m_pTransform->GetScale());
	shader->setMat4("model", model);

	m_pImpl->m_pMesh->Render();
}
void GameObject::AddNewMesh()
{
	m_pImpl->m_pMesh = new Mesh;
}

//GETTERS
Transform* GameObject::GetTransform()
{
	return m_pImpl->m_pTransform;
}
Mesh* GameObject::GetMesh()
{
	return m_pImpl->m_pMesh;
}







