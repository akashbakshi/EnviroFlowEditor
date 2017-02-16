#pragma once
#include "Quad.h"

class Mesh
{
public:
	Mesh();
	Mesh(GLfloat sx,GLfloat sy, GLfloat sz, int sides);
	~Mesh();

	int num_quads;
	Quad *q;
	
	void CreateBuffers();
	void setScale(GLfloat x, GLfloat y, GLfloat z);
	GLubyte getColor(char section);

	GLuint vbo, vio;
	std::vector<GLfloat> vertices;
	std::vector<GLuint>indices;

	bool quad_mode, mesh_mode;
private:
	int mesh_type;
	bool QuadColorCheck(GLubyte r, GLubyte g, GLubyte b);
	void GenerateQuadColors(int quad);

	void GenerateMeshColors(int mesh);
	GLubyte rgba[4];
};

