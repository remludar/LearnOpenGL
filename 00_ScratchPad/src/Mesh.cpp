#include "Mesh.h"

Mesh::Mesh()
{}

Mesh::~Mesh()
{}


void Mesh::Generate(std::vector<float> vertices, Shader::Type shaderType)
{
	m_vfVertices = vertices;
	m_pMaterial = new Material(shaderType);

	std::vector<int> attributeStrides;
	switch (shaderType)
	{
	case Shader::COLOR:
		attributeStrides.push_back(3);
		attributeStrides.push_back(3);
		break;
	case Shader::TEXTURE:
		attributeStrides.push_back(3);
		attributeStrides.push_back(2);
		break;
	case Shader::MIXED:
		attributeStrides.push_back(3);
		attributeStrides.push_back(3);
		attributeStrides.push_back(2);
		break;
	}

	for (int i = 0; i < attributeStrides.size(); i++)
	{
		m_iVertexSize += attributeStrides[i];
	}

	m_iVertexCount = vertices.size() / m_iVertexSize;

	glGenVertexArrays(1, &m_uintVAO);
	glGenBuffers(1, &m_uintVBO);

	// bind to vao
	glBindVertexArray(m_uintVAO);

	// bind to vbo and fill buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_uintVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

	int startLocation = 0;
	for (int i = 0; i < attributeStrides.size(); i++)
	{
		int currentAttributeStride = attributeStrides[i];
		int startLocationModifier = (i > 0) ? attributeStrides[i - 1] : 0;
		startLocation += startLocationModifier;

		glVertexAttribPointer(i, currentAttributeStride, GL_FLOAT, GL_FALSE, m_iVertexSize * sizeof(float), (void*)(startLocation * sizeof(float)));
		glEnableVertexAttribArray(i);
	}

	// unbind from vbo and vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
void Mesh::Render()
{
	glBindVertexArray(m_uintVAO);
	glDrawArrays(GL_TRIANGLES, 0, m_iVertexCount);
}
