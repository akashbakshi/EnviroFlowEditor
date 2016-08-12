#include "AppGUI.h"

HWND SecWin[3];
HWND Toolbar[2];
AppGUI::AppGUI()
{
}


AppGUI::~AppGUI()
{
}
GLfloat GetDlgItemFloat(HWND hWnd, int DlgItem)
{
	char text[500];

	GLfloat num;


	GetDlgItemText(hWnd, DlgItem, text, 500);
	cout << text << endl;
	istringstream temp(text);
	temp >> num;



	return num;
}

bool SetDlgItemFloat(HWND hWnd, int DlgItem, float num)
{
	stringstream temp;
	string temporary;
	temp << num;
	temporary = temp.str();

	if (!SetDlgItemText(hWnd, DlgItem, temporary.c_str()))
		return false;

	return true;
}
LRESULT CALLBACK PropertiesToolbar(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_INITDIALOG:{

			//Change Background color of Window to a light gray.
			SetClassLongPtr(SecWin[0], GCLP_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(72, 72, 72)));
		}break;

		case WM_COMMAND: {
			switch (LOWORD(wParam))
			{
				case IDC_PROP_POSX: {
					if (EN_CHANGE) {
						if (selection == true) {
							mesh[uni_sel].pos[0] = GetDlgItemFloat(SecWin[0], IDC_PROP_POSX);
							CalcXYZPos();
						}
					}
				}break;

				case IDC_PROP_POSY: {
					if (EN_CHANGE) {
						if (selection == true) {
							mesh[uni_sel].pos[1] = GetDlgItemFloat(SecWin[0], IDC_PROP_POSY);
							CalcXYZPos();
						}
					}
				}break;

				case IDC_PROP_POSZ: {
					if (EN_CHANGE) {
						if (selection == true) {
							mesh[uni_sel].pos[2] = GetDlgItemFloat(SecWin[0], IDC_PROP_POSZ);
							CalcXYZPos();
						}
					}
				}break;

				case IDC_PROP_SCAX: {
					if (EN_CHANGE) {
						if (selection == true) {
							mesh[uni_sel].scale[0] = GetDlgItemFloat(SecWin[0], IDC_PROP_SCAX);
							CalcXYZPos();
						}
					}
				}break;

				case IDC_PROP_SCAY: {
					if (EN_CHANGE) {
						if (selection == true) {
							mesh[uni_sel].scale[1] = GetDlgItemFloat(SecWin[0], IDC_PROP_SCAY);
							CalcXYZPos();
						}
					}
				}break;

				case IDC_PROP_SCAZ: {
					if (EN_CHANGE) {
						if (selection == true) {
							mesh[uni_sel].scale[2] = GetDlgItemFloat(SecWin[0], IDC_PROP_SCAZ);
							CalcXYZPos();
						}
					}
				}break;

			}
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



void AppGUI::UpdateMeshProperties()
{
	SetDlgItemFloat(SecWin[0], IDC_PROP_POSX, mesh[uni_sel].pos[0]);
	SetDlgItemFloat(SecWin[0], IDC_PROP_POSY, mesh[uni_sel].pos[1]);
	SetDlgItemFloat(SecWin[0], IDC_PROP_POSZ, mesh[uni_sel].pos[2]);


	SetDlgItemFloat(SecWin[0], IDC_PROP_SCAX, mesh[uni_sel].scale[0]);
	SetDlgItemFloat(SecWin[0], IDC_PROP_SCAY, mesh[uni_sel].scale[1]);
	SetDlgItemFloat(SecWin[0], IDC_PROP_SCAZ, mesh[uni_sel].scale[2]);
}

void AppGUI::ClearMeshProperties()
{
}
