#include "AppGUI.h"

HWND SecWin[3];

AppGUI::AppGUI()
{
}


AppGUI::~AppGUI()
{
}

LRESULT CALLBACK PropertiesToolbar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_INITDIALOG:{

	}break;

	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
void AppGUI::CreateToolbars()
{
	// Code to turn IDD_Properites Dialog as a child windows in Main Window.
	SecWin[0] = CreateDialog(hInst, MAKEINTRESOURCE(IDD_PROPERTIES), MainWindow, (DLGPROC)PropertiesToolbar);
	SetWindowPos(SecWin[0], HWND_TOPMOST,1550,50,370,285,SWP_SHOWWINDOW);
	ShowWindow(SecWin[0], SW_SHOW);
	SetParent(SecWin[0], MainWindow);
}
