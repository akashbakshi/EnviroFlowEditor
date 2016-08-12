#include "AppGUI.h"

HWND SecWin[3];
HWND Toolbar[2];


EFCreationSystem *Gen = NULL;

AppGUI::AppGUI()
{
}


AppGUI::~AppGUI()
{
}

void AppGUI::CalcMouseTrans(bool x, bool y, bool z, int mouse_x, int mouse_y) {
	// huh??
	// X Axis Calculations
	if (xaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			get_coord = false;
		}
		current_mouse_x = mouse_x;
		int tempx = current_mouse_x - init_mouse_x;

		if (tempx > 0) {
			if (camY < 90.0f && camY > -90.0f) {
				mesh[uni_sel].pos[0] += 0.06f;
				arrow[0].pos[0] += 0.06f;
				arrow[1].pos[0] += 0.06f;
				arrow[2].pos[0] += 0.06f;
			}
			else {
				mesh[uni_sel].pos[0] -= 0.06f;
				arrow[0].pos[0] -= 0.06f;
				arrow[1].pos[0] -= 0.06f;
				arrow[2].pos[0] -= 0.06f;
			}

		}
		if (tempx < 0) {
			if (camY < 90.0f && camY > -90.0f) {
				mesh[uni_sel].pos[0] -= 0.06f;
				arrow[0].pos[0] -= 0.06f;
				arrow[1].pos[0] -= 0.06f;
				arrow[2].pos[0] -= 0.06f;
			}
			else {
				mesh[uni_sel].pos[0] += 0.06f;
				arrow[0].pos[0] += 0.06f;
				arrow[1].pos[0] += 0.06f;
				arrow[2].pos[0] += 0.06f;
			}
		}
	}

	if (yaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			init_mouse_y = mouse_y;
			get_coord = false;
		}
		current_mouse_x = mouse_x;
		current_mouse_y = mouse_y;
		int tempx = current_mouse_x - init_mouse_x;
		int tempy = current_mouse_y - init_mouse_y;

		if (tempy < 0) {
			mesh[uni_sel].pos[1] += 0.045f;
			arrow[0].pos[1] += 0.045f;
			arrow[1].pos[1] += 0.045f;
			arrow[2].pos[1] += 0.045f;
		}

		if (tempy > 0) {

			mesh[uni_sel].pos[1] -= 0.045f;
			arrow[0].pos[1] -= 0.045f;
			arrow[1].pos[1] -= 0.045f;
			arrow[2].pos[1] -= 0.045f;
		}
	}

	if (zaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			init_mouse_y = mouse_y;
			get_coord = false;
		}
		current_mouse_x = mouse_x;
		current_mouse_y = mouse_y;
		int tempx = current_mouse_x - init_mouse_x;
		int tempy = current_mouse_y - init_mouse_y;

		if (tempy > 0) {

			if (camY < 90.0f && camY > -90.0f) {
				mesh[uni_sel].pos[2] += 0.045f;
				arrow[0].pos[2] += 0.045f;
				arrow[1].pos[2] += 0.045f;
				arrow[2].pos[2] += 0.045f;
			}
			else {

				mesh[uni_sel].pos[2] -= 0.045f;
				arrow[0].pos[2] -= 0.045f;
				arrow[1].pos[2] -= 0.045f;
				arrow[2].pos[2] -= 0.045f;
			}
		}
		if (tempy < 0) {

			if (camY < 90.0f && camY > -90.0f) {
				mesh[uni_sel].pos[2] -= 0.045f;
				arrow[0].pos[2] -= 0.045f;
				arrow[1].pos[2] -= 0.045f;
				arrow[2].pos[2] -= 0.045f;
			}
			else {

				mesh[uni_sel].pos[2] += 0.045f;
				arrow[0].pos[2] += 0.045f;
				arrow[1].pos[2] += 0.045f;
				arrow[2].pos[2] += 0.045f;
			}
		}
	}
}

void AppGUI::CalcMouseScale(bool x, bool y, bool z, int mouse_x, int mouse_y) {

	if (xaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			get_coord = false;
		}
		current_mouse_x = mouse_x;
		int tempx = current_mouse_x - init_mouse_x;
		if (tempx > 0) {
			mesh[uni_sel].scale[0] += 0.06f;
		}
		if (tempx < 0) {
			mesh[uni_sel].scale[0] -= 0.06f;
		}
	}
	if (yaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			init_mouse_y = mouse_y;
			get_coord = false;
		}
		current_mouse_x = mouse_x;
		current_mouse_y = mouse_y;
		int tempx = current_mouse_x - init_mouse_x;
		int tempy = current_mouse_y - init_mouse_y;

		if (tempy < 0) {

			mesh[uni_sel].scale[1] += 0.045f;
		}
		if (tempy > 0) {

			mesh[uni_sel].scale[1] -= 0.045f;
		}
	}

	if (zaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			init_mouse_y = mouse_y;
			get_coord = false;
		}

		current_mouse_x = mouse_x;
		current_mouse_y = mouse_y;
		int tempx = current_mouse_x - init_mouse_x;
		int tempy = current_mouse_y - init_mouse_y;

		if (tempy > 0) {

			mesh[uni_sel].scale[2] += 0.045f;
		}
		if (tempy < 0) {

			mesh[uni_sel].scale[2] -= 0.045f;
		}
	}
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


void WMCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (wParam == (WPARAM)ID_FILE_QUIT) {
		PostQuitMessage(0);
	}
	if (wParam == (WPARAM)ID_CREATE_CUBE) {
		DialogBox(hInst, MAKEINTRESOURCE(IDD_CREATE), MainWindow, (DLGPROC)CreateCubeDialog);
		Gen->CreateCube(objects);
	}

	else if (wParam == (WPARAM)ID_TWEAKMODE_FACETWEAK) {
		init_quad = true;
		v_solid = false;
		v_wireframe = false;
		v_textured = false;
	}
	else if (wParam == (WPARAM)ID_TWEAKMODE_MESHTWEAK) {
		init_quad = false;
		v_solid = true;
		v_wireframe = false;
		v_textured = false;
	}
	else if (wParam == (WPARAM)ID_VIEW_TEXTURED) {
		// Enable Texture if selected.
		glEnable(GL_TEXTURE_2D);

		//Disable  other two view modes and enable texturing.
		v_wireframe = false;
		v_solid = false;
		v_textured = true;

		//put in Fill mode since we're not in wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (wParam == (WPARAM)ID_VIEW_SOLID) {
		//Disable texture mode
		glDisable(GL_TEXTURE_2D);

		//Enabled solid mode and disable other modes.
		v_wireframe = false;
		v_solid = true;
		v_textured = false;

		//put in Fill mode since we're not in wireframe
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (wParam == (WPARAM)ID_VIEW_WIREFRAME) {
		glDisable(GL_TEXTURE_2D);

		//Enabled wireframe mode and disable other modes.
		v_wireframe = true;
		v_solid = false;
		v_textured = false;

		//put in Line mode since we're in wireframe mode.
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}


	//Buttons
	if (lParam == (LPARAM)Toolbar[0]) {

		sel_scale = false;
		sel_trans = true;
		//Draw Green Y-axis Arrow

		arrow[0].faces.clear();
		arrow[0].vertices.clear();
		TranslateArrowsXYZ(0);
		arrow[0].rgb[0] = 0;
		arrow[0].rgb[1] = 255;
		arrow[0].rgb[2] = 0;

		arrow[0].pos[1] = 1.1f;
		//Draw Red X-axis Arrow
		arrow[1].faces.clear();
		arrow[1].vertices.clear();
		TranslateArrowsXYZ(1);
		arrow[1].rgb[0] = 255;
		arrow[1].rgb[1] = 0;
		arrow[1].rgb[2] = 0;
		arrow[1].pos[1] = 1.1f;
		//Rotating it so it faces the X-axis.
		arrow[1].rot[0] = 90.0f;
		arrow[1].rot[1] = 0.0f;
		arrow[1].rot[2] = 0.0f;
		arrow[1].rot[3] = -90.0f;

		//Drawing Blue Z-Axis Arrow.
		arrow[2].faces.clear();
		arrow[2].vertices.clear();
		TranslateArrowsXYZ(2);
		arrow[2].rgb[0] = 0;
		arrow[2].rgb[1] = 0;
		arrow[2].rgb[2] = 255;
		arrow[2].pos[1] = 1.1f;
		//Rotating it so it faces the z-axis.
		arrow[2].rot[0] = 90.0f;
		arrow[2].rot[1] = 90.0f;
		arrow[2].rot[2] = 0.0f;
		arrow[2].rot[3] = 0.0f;

		CalcXYZPos();
		SetFocus(MainWindow);
	}
	if (lParam == (LPARAM)Toolbar[1]) {

		sel_scale = true;
		sel_trans = false;

		//Draw Green Y-axis Arrow
		arrow[0].faces.clear();
		arrow[0].vertices.clear();
		ScaleArrowsXYZ(0);
		arrow[0].rgb[0] = 0;
		arrow[0].rgb[1] = 255;
		arrow[0].rgb[2] = 0;

		arrow[0].pos[1] = 1.1f;
		//Draw Red X-axis Arrow
		arrow[1].faces.clear();
		arrow[1].vertices.clear();
		ScaleArrowsXYZ(1);
		arrow[1].rgb[0] = 255;
		arrow[1].rgb[1] = 0;
		arrow[1].rgb[2] = 0;
		arrow[1].pos[1] = 1.1f;
		//Rotating it so it faces the X-axis.
		arrow[1].rot[0] = 90.0f;
		arrow[1].rot[1] = 0.0f;
		arrow[1].rot[2] = 0.0f;
		arrow[1].rot[3] = -90.0f;

		//Drawing Blue Z-Axis Arrow.
		arrow[2].faces.clear();
		arrow[2].vertices.clear();
		ScaleArrowsXYZ(2);
		arrow[2].rgb[0] = 0;
		arrow[2].rgb[1] = 0;
		arrow[2].rgb[2] = 255;
		arrow[2].pos[1] = 1.1f;
		//Rotating it so it faces the z-axis.
		arrow[2].rot[0] = 90.0f;
		arrow[2].rot[1] = 90.0f;
		arrow[2].rot[2] = 0.0f;
		arrow[2].rot[3] = 0.0f;

		CalcXYZPos();
		SetFocus(MainWindow);
	}
}

LRESULT CALLBACK CreateCubeDialog(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		case WM_INITDIALOG: {
			SetDlgItemText(hWnd, IDC_SIZEX, "1.0");
			SetDlgItemText(hWnd, IDC_SIZEY, "1.0");
			SetDlgItemText(hWnd, IDC_SIZEZ, "1.0");
		}break;
		case WM_COMMAND: {
			if (wParam == IDOK) {
				EndDialog(hWnd, 0);
			}
		}break;
	}
	return (0);
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
	SendDlgItemMessage(SecWin[0], IDC_PROP_POSX, WM_SETTEXT, 0, (LPARAM)" ");
	SendDlgItemMessage(SecWin[0], IDC_PROP_POSY, WM_SETTEXT, 0, (LPARAM)" ");
	SendDlgItemMessage(SecWin[0], IDC_PROP_POSZ, WM_SETTEXT, 0, (LPARAM)" ");

	SendDlgItemMessage(SecWin[0], IDC_PROP_SCAX, WM_SETTEXT, 0, (LPARAM)" ");
	SendDlgItemMessage(SecWin[0], IDC_PROP_SCAY, WM_SETTEXT, 0, (LPARAM)" ");
	SendDlgItemMessage(SecWin[0], IDC_PROP_SCAZ, WM_SETTEXT, 0, (LPARAM)" ");
}
