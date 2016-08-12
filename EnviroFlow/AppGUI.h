#pragma once
#include "main.h"
#include "EFCreationSystem.h"

class AppGUI
{
public:
	AppGUI();
	~AppGUI();

	void CreateToolbars();
	void UpdateMeshProperties();
	void ClearMeshProperties();
};

extern HWND Toolbar[2];