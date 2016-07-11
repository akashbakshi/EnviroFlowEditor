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

	return (0);
}
void AppGUI::CreateToolbars()
{
	// Code to turn IDD_Properites Dialog as a child windows in Main Window.
	SecWin[0] = CreateDialog(hInst, MAKEINTRESOURCE(IDD_PROPERTIES), MainWindow, (DLGPROC)PropertiesToolbar);
	
	//Set Child Window Position
	SetWindowPos(SecWin[0], HWND_TOPMOST,1546,50,352,300,SWP_SHOWWINDOW);
	//Make Window Visible  and set parent window.
	ShowWindow(SecWin[0], SW_SHOW);
	SetParent(SecWin[0], MainWindow);

	//Change Background color of Window to a light gray.
	//SetClassLongPtr(SecWin[0], GCLP_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(72,72,72)));
}
