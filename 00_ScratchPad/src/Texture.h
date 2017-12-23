#pragma once

#include <glad/glad.h>
#include <stb_image.h>

#include <iostream>

class Texture
{
private:
	unsigned int m_uintTextureID;
public:
	Texture();
	~Texture();

	void Generate(const char* path);
	unsigned int GetID();
};

