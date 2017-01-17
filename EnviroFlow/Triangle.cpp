#include "Triangle.h"



Triangle::Triangle()
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f, 1.0f, 0.0f);
	v[2] = Vertex(1.0f, 1.0f, 0.0f);

	for (int i = 0; i < 3; i++) {
		pos[i] = 0.0f;
		for(int c = 0;c<3;c++){
			vertices.push_back(v[i].getCoordinates(c));
			num_indices += 1;
		}
		for (int c = 0; c < num_indices; c++)
			indices.push_back(c);
	}
	for (int i = 0; i < 4; i++)
		rgba[i] = 0.0f;
	
	CreateBuffers();
}

Triangle::Triangle(GLfloat sx, GLfloat sy, GLfloat sz)
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f, sy, 0.0f);
	v[2] = Vertex(sx, sy, 0.0f);

	for (int i = 0; i < 3; i++) {
		pos[i] = 0.0f;
		for (int c = 0; c<3; c++) {
			vertices.push_back(v[i].getCoordinates(c));
			num_indices += 1;
		}
		for (int c = 0; c < num_indices; c++)
			indices.push_back(c);
	}
	for (int i = 0; i < 4; i++)
		rgba[i] = 0.0f;

	Triangle::CreateBuffers();
}

void Triangle::CreateBuffers() {
	glCreateBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], 0);


	glCreateBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLfloat), &indices[0], 0);
}

GLuint Triangle::getVBO()
{
	return vbo;
}

GLuint Triangle::getVIO()
{
	return vio;
}

Triangle::~Triangle()
{
}

