#pragma once

#include "stb_image.h"

#include "Shader.h"

class Material
{
private:
	Shader* m_pShader;
	
public:
	Material(Shader::Type type);
	~Material();

	// GETTERS
	Shader* GetShader()
	{
		return m_pShader;
	}
};

