#include "Material.h"

Material::Material()
{
	m_pShader = new Shader("res/shaders/defaultVertex.shader", "res/shaders/defaultFragment.shader");
}


Material::~Material()
{}
