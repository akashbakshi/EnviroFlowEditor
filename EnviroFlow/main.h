#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <glew.h>
#include "glext.h"
#include "wglext.h"
#include "resource.h"

#define CUSTOM 1
#define CUBE 2
#define PLANE 3
#define TRIANGLE 4

//boolean to keep loop going
extern bool running;

//MainWindow declaration 
extern HWND MainWindow;
extern HWND RenderWindow;


extern HINSTANCE hInst;
extern HGLRC hRC;
extern HDC hDC;
extern bool GetKey[256];

typedef struct MAP_HEADER {
	int version;
	int revision;
	//
	int numVertices;
	int numQuads;
	int numTris;
	int numMesh;
	int numTextures;

};
extern MAP_HEADER header;
extern bool MeshColorCheck(GLubyte r, GLubyte g, GLubyte b);