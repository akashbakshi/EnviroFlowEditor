#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <glew.h>

#include "wglext.h"

//boolean to keep loop going
extern bool running;

//MainWindow declaration 
extern HWND MainWindow;
extern HWND RenderWindow;


extern HINSTANCE hInst;
extern HGLRC hRC;
extern HDC hDC;