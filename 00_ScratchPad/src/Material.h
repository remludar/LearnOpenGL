#pragma once

#include "Shader.h"

class Material
{
private:
	Shader* m_pShader;
	
public:
	Material();
	~Material();

	// GETTERS
	Shader* GetShader()
	{
		return m_pShader;
	}
};

