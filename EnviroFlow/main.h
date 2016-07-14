#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <glew.h>

#include "wglext.h"
#include "resource.h"


//boolean to keep loop going
extern bool running;

//MainWindow declaration 
extern HWND MainWindow;
extern HWND RenderWindow;

//Main Window variables
extern int mwWidth;
extern int mwHeight;

//Render Window variables
extern int rwWidth;
extern int rwHeight;

extern HINSTANCE hInst;
extern HGLRC hRC;
extern HDC hDC;
extern bool GetKey[256];
