#pragma once
#include "main.h"


class AppWindow
{
public:
	AppWindow();
	~AppWindow();

	void SetupPixelFormat(HDC &hDC);
	bool InitAPI(HWND hWnd, HDC &hDC, HGLRC &hRC);
	bool DisableAPI(HWND hWnd, HDC &hDC, HGLRC &hRC);
	int CreateClass();
	int CreateWindows(std::string name, int width, int height);
	int WinLoop(MSG msg);
};

