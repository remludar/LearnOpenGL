#include "Mesh.h"

Mesh::Mesh()
{}


Mesh::~Mesh()
{}

void Mesh::Generate(std::vector<float> vertices)
{
	glGenVertexArrays(1, &m_uintVAO);
	glGenBuffers(1, &m_uintVBO);

	// bind to vao
	glBindVertexArray(m_uintVAO);

	// bind to vbo and fill buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_uintVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

	// define the layout of the data in the vbo and enable the vertex attributes for the shader 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// unbind from vbo and vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Mesh::Generate(std::vector<float> vertices, std::vector<int> attributeStrides)
{
	int vertexSize = 0;
	for (int i = 0; i < attributeStrides.size(); i++)
	{
		vertexSize += attributeStrides[i];
	}

	glGenVertexArrays(1, &m_uintVAO);
	glGenBuffers(1, &m_uintVBO);

	// bind to vao
	glBindVertexArray(m_uintVAO);

	// bind to vbo and fill buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_uintVBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

	for (int i = 0; i < attributeStrides.size(); i++)
	{
		int currentAttributeStride = attributeStrides[i];
		int startLocation = (i > 0) ? attributeStrides[i-1] : 0;

		glVertexAttribPointer(i, currentAttributeStride, GL_FLOAT, GL_FALSE, vertexSize * sizeof(float), (void*)(startLocation * sizeof(float)));
		glEnableVertexAttribArray(i);
	}

	// unbind from vbo and vao
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);





}
 
void Mesh::Render()
{
	glBindVertexArray(m_uintVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
