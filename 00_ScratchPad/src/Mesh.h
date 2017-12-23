#pragma once

#include <glad/glad.h>

#include "Material.h"

#include <vector>

class Mesh
{
private:
	unsigned int m_uintVAO, m_uintVBO;
	Material* m_pMaterial;
	std::vector<float> m_vfVertices;
public:
	Mesh();
	~Mesh();

	void Generate(std::vector<float> vertices);
	void Render();

	// GETTER
	Material* GetMaterial()
	{
		return m_pMaterial;
	}

};

