#include "Triangle.h"



Triangle::Triangle()
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f, 1.0f, 0.0f);
	v[2] = Vertex(1.0f, 1.0f, 0.0f);

	for (int i = 0; i < 3; i++) {
		pos[i] = 0.0f;
		scale[i] = 1.0f;
		for(int c = 0;c<3;c++){
			vertices.push_back(v[i].getCoordinates(c));
			num_indices += 1;
		}
		for (int c = 0; c < num_indices; c++)
			indices.push_back(c);
	}
	for (int i = 0; i < 4; i++)
		rgba[i] = 0.0f;
	

	header.numVertices += 3;
}

Triangle::Triangle(GLfloat sx, GLfloat sy, GLfloat sz)
{
	v[0] = Vertex(0.0f, 0.0f, 0.0f);
	v[1] = Vertex(0.0f, sy, 0.0f);
	v[2] = Vertex(sx, sy, 0.0f);
	num_indices = 0;
	
	for (int i = 0; i < 3; i++) {
		pos[i] = 0.0f;
		scale[i] = 1.0f;
		for (int c = 0; c<3; c++) {
			vertices.push_back(v[i].getCoordinates(c));
			num_indices += 1;
		}
		
	}
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	for (int i = 0; i < 4; i++)
		rgba[i] = 0.0f;

	header.numVertices += 3;
}

void Triangle::CreateBuffers() {
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertices.size() , &vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)* indices.size(), &indices[0], GL_STATIC_DRAW);
}

GLuint Triangle::getVBO()
{
	return vbo;
}

GLuint Triangle::getVIO()
{
	return vio;
}

GLfloat Triangle::getPos(char axis)
{
	GLfloat val = 0.0f;
	if (axis == 'x' || axis == 'X')
		val = pos[0];
	else if (axis == 'y' || axis == 'Y')
		val = pos[1];
	else if (axis == 'z' || axis == 'Z')
		val = pos[2];

	return val;
}

GLfloat Triangle::getScale(char axis) {
	GLfloat val = 0.0f;
	if (axis == 'x' || axis == 'X')
		val = scale[0];
	else if (axis == 'y' || axis == 'Y')
		val = scale[1];
	else if (axis == 'z' || axis == 'Z')
		val = scale[2];

	return val;
}
void Triangle::setPos(GLfloat x, GLfloat y, GLfloat z) {
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

Triangle::~Triangle()
{
}

