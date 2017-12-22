#include "Triangle.h"

Triangle CreateTriangle(GLfloat sx, GLfloat sy, GLfloat sz)
{
	Triangle tmp;

	tmp.v[0] = CreateVertex(0.0f, 0.0f, 0.0f);
	tmp.v[1] = CreateVertex(0.0f, sy, 0.0f);
	tmp.v[2] = CreateVertex(sx, sy, 0.0f);
	tmp.num_indices = 0;
	
	for (int i = 0; i < 3; i++) {
		tmp.pos[i] = 0.0f;
		tmp.scale[i] = 1.0f;
		for (int c = 0; c<3; c++) {
			tmp.vertices.push_back(tmp.v[i].xyz[c]);
			
			tmp.num_indices += 1;
		}
		
	}
	tmp.indices.push_back(0);
	tmp.indices.push_back(1);
	tmp.indices.push_back(2);
	for (int i = 0; i < 4; i++)
		tmp.rgba[i] = 0.0f;

	header.numVertices += 3;
	tmp.vbo = CreateVertexBuffers(tmp);
	tmp.vio = CreateIndexBuffer(tmp);
}

GLuint CreateVertexBuffers(Triangle tri) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*tri.vertices.size(), &tri.vertices[0], GL_STATIC_DRAW);

	return vbo;
}
GLuint CreateIndexBuffer(Triangle tri){
	GLuint vio;
	glGenBuffers(1, &vio);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vio);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)* tri.indices.size(), &tri.indices[0], GL_STATIC_DRAW);
}


GLfloat getPos(char axis,Triangle tri)
{
	GLfloat val = 0.0f;
	if (axis == 'x' || axis == 'X')
		val = tri.pos[0];
	else if (axis == 'y' || axis == 'Y')
		val = tri.pos[1];
	else if (axis == 'z' || axis == 'Z')
		val = tri.pos[2];

	return val;
}

GLfloat getScale(char axis,Triangle tri) {
	GLfloat val = 0.0f;
	if (axis == 'x' || axis == 'X')
		val =tri.scale[0];
	else if (axis == 'y' || axis == 'Y')
		val = tri.scale[1];
	else if (axis == 'z' || axis == 'Z')
		val = tri.scale[2];

	return val;
}
void setPos(Triangle tri,GLfloat x, GLfloat y, GLfloat z) {
	tri.pos[0] = x;
	tri.pos[1] = y;
	tri.pos[2] = z;
}
