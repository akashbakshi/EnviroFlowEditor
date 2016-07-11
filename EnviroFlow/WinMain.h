#pragma once

#include "main.h"


class WinMain
{
public:
	WinMain();
	~WinMain();

	void CreateClass();
	void CreateWindows(std::string name, int width, int height);
	void WinLoop();
};

