#include "Texture.h"



Texture::Texture()
{
	stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &m_uintTextureID);
	glBindTexture(GL_TEXTURE_2D, m_uintTextureID);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	
}


Texture::~Texture()
{}

void Texture::Generate(const char* path)
{
	// grab texture image data
	int width, height, nrChannels;
	unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data)
	{
		// generate the texture2d object and mipmap
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	// free image data memory
	stbi_image_free(data);
}

unsigned int Texture::GetID()
{
	return m_uintTextureID;
}
