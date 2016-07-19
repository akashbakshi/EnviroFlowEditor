#include "AppGUI.h"

HWND SecWin[3];
HWND Toolbar[2];
AppGUI::AppGUI()
{
}


AppGUI::~AppGUI()
{
}

LRESULT CALLBACK PropertiesToolbar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_INITDIALOG:{

		//Change Background color of Window to a light gray.
		SetClassLongPtr(SecWin[0], GCLP_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(72, 72, 72)));
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

	
	Toolbar[0] = CreateWindow("BUTTON", "T", WS_CHILD | WS_VISIBLE, 800, 0, 50, 50, MainWindow, NULL, hInst, NULL);
	Toolbar[1] = CreateWindow("BUTTON", "S", WS_CHILD | WS_VISIBLE, 850, 0, 50, 50, MainWindow, NULL, hInst, NULL);

}
