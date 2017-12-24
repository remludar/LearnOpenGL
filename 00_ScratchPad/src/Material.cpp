#include "Material.h"

Material::Material(Shader::Type type)
{
	unsigned int texture;
	int width, height, nrChannels;
	unsigned char* data;

	switch (type)
	{
	case Shader::COLOR:
		m_pShader = new Shader("res/shaders/defaultVertex.shader", "res/shaders/defaultFragment.shader");
		break;
	case Shader::TEXTURE:
		m_pShader = new Shader("res/shaders/textureVertex.shader", "res/shaders/textureFragment.shader");
		
		stbi_set_flip_vertically_on_load(true);
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		data = stbi_load("res/img/container.jpg", &width, &height, &nrChannels, 0);
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

		m_pShader->setInt("texture1", 0);
		break;
	case Shader::MIXED:
		m_pShader = new Shader("res/shaders/mixedVertex.shader", "res/shaders/mixedFragment.shader");

		stbi_set_flip_vertically_on_load(true);
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		data = stbi_load("res/img/container.jpg", &width, &height, &nrChannels, 0);
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

		m_pShader->setInt("texture1", 0);
		break;

	}
}

Material::~Material()
{}
