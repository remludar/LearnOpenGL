#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Transform.h"
#include "Mesh.h"
#include "Texture.h"

#include <vector>
#include <memory>

class GameObject
{

public:
	//CONSTRUCTORS
	GameObject();
	~GameObject();
	GameObject(const GameObject& other);
	GameObject& operator=(GameObject rhs);

	void Update();
	void Render();

	//GETTERS
	Transform* GetTransform();

	//SETTERS
	void SetMesh(Mesh* mesh);

private:
	struct Impl;
	std::unique_ptr<Impl> m_pImpl;

};

