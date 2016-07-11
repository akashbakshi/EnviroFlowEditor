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
	SecWin[0] = CreateDialog(hInst, MAKEINTRESOURCE(IDD_PROPERTIES), MainWindow, (DLGPROC)PropertiesToolbar);
}
