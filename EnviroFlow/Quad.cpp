#include "Quad.h"


Quad::Quad()
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f,1.0f, 0.0f);
	v[2] = Vertex(1.0f, 1.0f, 0.0f);
	v[3] = Vertex(1.0f, 0.0f, 0.0f);

	for (int i = 0; i < 4; i++) {
		for (int c = 0; c < 3; c++)
			vertices.push_back(v[i].getCoordinates(c));
		rgba[i] = 0;
		rot[i] = 0.0f;
		indices_num += 1;
	}

	for (int i = 0; i < indices_num; i++)
		indices.push_back(i);

	for (int i = 0; i < 3; i++) {
		pos[i] = 0.0f;
		scale[i] = 1.0f;
	}
}

Quad::Quad(GLfloat sx, GLfloat sy,GLfloat sz) {
	v[0] = Vertex(0.0f, 0.0f, sz);
	v[1] = Vertex(sx, 0.0f, sz);
	v[2] = Vertex(sx, sy, sz);
	v[3] = Vertex(0.0f, sy, sz);
	indices_num = 0;
	for (int i = 0; i < 4; i++) {
		for (int c = 0; c < 3; c++)
			vertices.push_back(v[i].getCoordinates(c));
		rgba[i] = 0;
		rot[i] = 0.0f;
		indices_num += 1;
	}

	for (int i = 0; i < indices_num; i++)
		indices.push_back(i);

	for (int i = 0; i < 3; i++) {
		pos[i] = 0.0f;
		scale[i] = 1.0f;
		
	}

}

Quad::~Quad()
{
}

GLuint Quad::getVIO() {
	return vio;
}

GLuint Quad::getVBO() {
	return vbo;
}

GLfloat Quad::getPos(char axis) {
	GLfloat val = 0.0f;
	if (axis == 'x' || axis == 'X')
		val = pos[0];
	else if (axis == 'y' || axis == 'Y')
		val = pos[1];
	else if (axis == 'z' || axis == 'Z')
		val = pos[2];

	return val;
}

GLfloat Quad::getScale(char axis) {
	GLfloat val = 0.0f;
	if (axis == 'x' || axis == 'X')
		val = scale[0];
	else if (axis == 'y' || axis == 'Y')
		val = scale[1];
	else if (axis == 'z' || axis == 'Z')
		val = scale[2];

	return val;
}

GLubyte Quad::getColor(char section)
{
	GLubyte val;
	if (section == 'r' || section == 'R')
		val = rgba[0];
	else if (section == 'g' || section == 'G')
		val = rgba[1];
	else if (section == 'b' || section == 'B')
		val = rgba[2];
	else if (section == 'a' || section == 'A')
		val = rgba[3];

	std::cout << val << std::endl;
	return val;
}

void Quad::setPos(GLfloat x, GLfloat y, GLfloat z)
{
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;

}

void Quad::setScale(GLfloat x, GLfloat y, GLfloat z)
{
	scale[0] = x;
	scale[1] = y;
	scale[2] = z;

}

void Quad::setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
	rgba[3] = a;

}

void Quad::CreateBuffers() {

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertices.size(), &vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indices.size(), &indices[0], GL_STATIC_DRAW);
}