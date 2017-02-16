#pragma once
#include "main.h"
#include "AppLog.h"

class Vertex
{
public:
	Vertex();
	Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z);
	~Vertex();

	void setXYZ(GLfloat x, GLfloat y, GLfloat z);
	void setPos(GLfloat x, GLfloat y, GLfloat z);
	void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	GLfloat getCoordinates(int num);
private:
	GLfloat xyz[3];
	GLfloat pos[3];
	GLfloat rgba[4];

};

