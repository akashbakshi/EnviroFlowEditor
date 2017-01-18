#pragma once
#include "Triangle.h"

class Quad
{
public:
	Quad();
	Quad(GLfloat sx, GLfloat sy, GLfloat sz);
	~Quad();


	void CreateBuffers();

	GLuint getVBO();
	GLuint getVIO();
	GLfloat getPos(char axis);
	GLfloat getScale(char axis);
	GLubyte getColor(char section);
	GLfloat getRot(char axis);
	//
	void setPos(GLfloat x, GLfloat y, GLfloat z);
	void setRotation(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void setScale(GLfloat x, GLfloat y, GLfloat z);
	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a);

	std::vector<GLfloat>vertices;
	std::vector<GLuint>indices;
private:
	Vertex v[4];
	GLfloat pos[3];
	GLfloat scale[3];
	GLfloat rot[4];
	GLubyte rgba[4];
	GLuint vbo, vio;
	//
	int indices_num;
	
	//Methods

};

