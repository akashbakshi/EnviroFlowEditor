#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <glew.h>
#include <sstream>
#include "wglext.h"
#include "resource.h"


//boolean to keep loop going
extern bool running;

//MainWindow declaration 
extern HWND MainWindow;
extern HWND RenderWindow;


extern HINSTANCE hInst;
extern HGLRC hRC;
extern HDC hDC;
extern bool GetKey[256];

extern GLuint LoadTGATexture(char *TexName);

//view type bools
extern bool v_textured;
extern bool v_solid;
extern bool v_wireframe;

//Universal selection variable to keep track of selected meshes index.
extern int uni_sel;
extern bool quad_uni_sel;
extern bool selection;
extern bool init_quad;
extern bool sel_scale, sel_trans;
extern bool get_coord;
extern bool xaxis, yaxis, zaxis;
extern int init_mouse_x,init_mouse_y,current_mouse_x,current_mouse_y;
extern GLfloat camY;

//
extern void CalcXYZPos();
extern void WMCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
extern LRESULT CALLBACK CreateCubeDialog(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);