#pragma once
#include "main.h"
#include "EFCreationSystem.h"
#include "EFRender.h"


class AppGUI
{
public:
	AppGUI();
	~AppGUI();

	void CreateToolbars();
	void UpdateMeshProperties();
	void ClearMeshProperties();
	void CalcMouseTrans(bool x, bool y, bool z, int mouse_x, int mouse_y);
	void CalcMouseScale(bool x, bool y, bool z, int mouse_x, int mouse_y);

	int getWindowHeight(string window);
	int getWindowWidth(string window);
private:
	int render_window_height, render_window_width;
	int prop_toolbar_height, prop_toolbar_width;
};

extern HWND Toolbar[2];