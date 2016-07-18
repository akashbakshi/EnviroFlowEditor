#include "AppWindow.h"
#include "EFRender.h"
#include "AppGUI.h"
#include "EFCreationSystem.h"

#include <CommCtrl.h>
#include <shlobj.h>   
#include <windowsx.h>

using namespace std;

PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;

bool running=true;

//GUI Varibales plus Device Context stuf
HWND MainWindow;
HWND RenderWindow;
HINSTANCE hInst;
HDC hDC;
HGLRC hRC;

// pointers for classes
EFRender *Draw = NULL;
AppGUI *GUI = NULL;
HMENU Menu;

int uni_sel = 0;
unsigned char pixel[4];
bool xaxis = false, yaxis = false, zaxis = false;
bool init_click = false;
bool get_coord = false;
int init_mouse_x = 0;
int init_mouse_y = 0;

int current_mouse_x = 0;
int current_mouse_y = 0;
AppWindow::AppWindow()
{
}


AppWindow::~AppWindow()
{
}

void CalcArrowsMouse(bool x, bool y, bool z, int mouse_x, int mouse_y) {

	if (xaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			get_coord = false;
			cout << "init";
		}
		current_mouse_x = mouse_x;
		int tempx = current_mouse_x - init_mouse_x;
		cout << "initx:" << init_mouse_x << endl;
		cout << "currentx" << current_mouse_x << endl;
		cout << "x: " << tempx << endl;

		if (tempx > 0) {

			mesh[uni_sel].pos[0] += 0.06;
			arrow[0].pos[0] += 0.06;
			arrow[1].pos[0] += 0.06;
			arrow[2].pos[0] += 0.06;

		}
		if (tempx < 0) {
			mesh[uni_sel].pos[0] -= 0.06;
			arrow[0].pos[0] -= 0.06;
			arrow[1].pos[0] -= 0.06;
			arrow[2].pos[0] -= 0.06;
		}
	}
	if (yaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			init_mouse_y = mouse_y;
			get_coord = false;
			cout << "init";
		}
		current_mouse_x = mouse_x;
		current_mouse_y = mouse_y;
		int tempx = current_mouse_x - init_mouse_x;
		int tempy = current_mouse_y - init_mouse_y;
		cout << "initx:" << init_mouse_x << endl;
		cout << "currentx" << current_mouse_x << endl;
		cout << "x: " << tempx << endl;
		cout << "y: " << tempy << endl;

		if (tempy < 0 ) {

			mesh[uni_sel].pos[1] += 0.045;
			arrow[0].pos[1] += 0.045;
			arrow[1].pos[1] += 0.045;
			arrow[2].pos[1] += 0.045;
		}
		if (tempy > 0 ) {

			mesh[uni_sel].pos[1] -= 0.045;
			arrow[0].pos[1] -= 0.045;
			arrow[1].pos[1] -= 0.045;
			arrow[2].pos[1] -= 0.045;
		}
	}

	if (zaxis == true) {
		if (get_coord == true) {
			init_mouse_x = mouse_x;
			init_mouse_y = mouse_y;
			get_coord = false;
			cout << "init";
		}
		current_mouse_x = mouse_x;
		current_mouse_y = mouse_y;
		int tempx = current_mouse_x - init_mouse_x;
		int tempy = current_mouse_y - init_mouse_y;
		cout << "initx:" << init_mouse_x << endl;
		cout << "currentx" << current_mouse_x << endl;
		cout << "x: " << tempx << endl;
		cout << "y: " << tempy << endl;

		if (tempy > 0) {

			mesh[uni_sel].pos[2] += 0.045;
			arrow[0].pos[2] += 0.045;
			arrow[1].pos[2] += 0.045;
			arrow[2].pos[2] += 0.045;
		}
		if (tempy < 0) {

			mesh[uni_sel].pos[2] -= 0.045;
			arrow[0].pos[2] -= 0.045;
			arrow[1].pos[2] -= 0.045;
			arrow[2].pos[2] -= 0.045;
		}
	}
}
void Selection(HWND hWnd)
{
	GLubyte bg[3];
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;
	POINT mouse;                        // Stores The X And Y Coords For The Current Mouse Position
	GetCursorPos(&mouse);                   // Gets The Current Cursor Coordinates (Mouse Coordinates)
	ScreenToClient(hWnd, &mouse);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	bg[0] = 51;
	bg[1] = 51;
	bg[2] = 51;
	winX = (float)mouse.x;
	winY = (float)viewport[3] - (float)mouse.y;
	glReadPixels(mouse.x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	glReadPixels(mouse.x, 900 - 1 - mouse.y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel[0]);
	cout << "r:" << (int)pixel[0] << endl;
	cout << "g:" << (int)pixel[1] << endl;
	cout << "b:" << (int)pixel[2] << endl;

	for (int i = 0; i < objects; i++)
	{
		//ResetInfo();
		if (mesh[i].rgba[0] == pixel[0] && mesh[i].rgba[1] == pixel[1] && mesh[i].rgba[2] == pixel[2])
		{
			uni_sel = i;
			cout << "sel "<<uni_sel;
		}
		if (pixel[0] == 255 && pixel[1] == 0 && pixel[2] == 0) {
			xaxis = true;
			yaxis = false;
			zaxis = false;
			init_click = true;
			get_coord = true;
			uni_sel = 0;
		}
		if (pixel[0] == 0 && pixel[1] == 255 && pixel[2] == 0) {
			xaxis = false;
			yaxis = true;
			zaxis = false;
			init_click = true;
			get_coord = true;
			uni_sel = 0;
		}
		if (pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 255) {
			xaxis = false;
			yaxis = false;
			zaxis = true;
			init_click = true;
			get_coord = true;
			uni_sel = 0;
		}
	}
}

void WMCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (wParam == (WPARAM)ID_FILE_QUIT) {
		PostQuitMessage(0);
	}
	else if (wParam == (WPARAM)ID_TWEAKMODE_FACETWEAK) {
		init_quad = true;
	}
	else if (wParam == (WPARAM)ID_TWEAKMODE_MESHTWEAK) {
		init_quad = false;
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
	
}
int get_x = 0;
int get_y = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {
		case WM_CREATE:
			break;
		case WM_DESTROY:
			running = false;
			PostQuitMessage(0);
			break;
		case WM_COMMAND:
			WMCommand(hWnd, msg, wParam, lParam);
			break;
		case WM_KEYDOWN:
			GetKey[wParam] = true;
			break;
		case WM_KEYUP:
			GetKey[wParam] = false;
			break;
		case WM_LBUTTONDOWN:
		
			Selection(RenderWindow);
			

			break;
		case WM_LBUTTONUP:
			init_click = false;
			xaxis = false;
			init_mouse_x = 0;
			current_mouse_x = 0;
			break;
		case WM_MOUSEMOVE:
			if(init_click == true){

				get_x = GET_X_LPARAM(lParam);
				get_y = GET_Y_LPARAM(lParam);
				CalcArrowsMouse(xaxis, yaxis, zaxis, get_x, get_y);
			}
			break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


void AppWindow::SetupPixelFormat(HDC &hDC)
{
	int PixelFormat = 0;

	PIXELFORMATDESCRIPTOR pfd;

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

	PixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, PixelFormat, &pfd);


}

bool AppWindow::InitAPI(HWND hWnd, HDC &hDC, HGLRC &hRC)
{
	hDC = GetDC(hWnd);


	AppWindow::SetupPixelFormat(hDC);

	int attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 0,
		0
	};

	HGLRC tempContext = wglCreateContext(hDC);
	wglMakeCurrent(hDC, tempContext);

	wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

	if (!wglCreateContextAttribsARB)
	{
		MessageBox(MainWindow, "ERROR: Cannot Create Context Attributes", "ERROR!", MB_OK);
		hRC = tempContext;
		running = false;
	}
	else
	{
		hRC = wglCreateContextAttribsARB(hDC, 0, attribs);


		wglDeleteContext(tempContext);

	}
	wglMakeCurrent(hDC, hRC);
	glewInit();

	glewExperimental = TRUE;
	Draw->Init();


	return true;
}

bool AppWindow::DisableAPI(HWND hWnd, HDC &hDC, HGLRC &hRC)
{
	wglMakeCurrent(hDC, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hWnd, hDC);

	return true;
}

int AppWindow::CreateClass()
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	wc.hInstance = hInst;
	wc.lpszClassName = "EF";
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(hInst, IDC_ARROW);
	wc.hIcon = LoadIcon(hInst, IDI_APPLICATION);
	wc.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Fatal Error: Cannot Register Windows Class, Reboot Application", "FATAL ERROR!", MB_OK);
		return 1;
	}
	return 0;
}
   
int AppWindow::CreateWindows(string name, int width, int height)
{
	//Create Main Outer Window For Application.
	MainWindow = CreateWindowEx(WS_EX_APPWINDOW, "EF", name.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, width, height, NULL, NULL, hInst, NULL);
	if (!MainWindow) {
		MessageBox(NULL, "Fatal Error: Cannot Create Main Window, Try Restarting The Application", "FATAL ERROR!", MB_OK);
		return 1;
	}

	//Create Child Window inside Main Window to render to
	RenderWindow = CreateWindow("STATIC", " ", WS_CHILD | WS_VISIBLE, 100, 50, 1440, 900, MainWindow, NULL, hInst, NULL);

	if (!RenderWindow) {
		MessageBox(NULL, "Fatal Error: Cannot Create Render Window, Try Restarting The Application", "FATAL ERROR!", MB_OK);
		return 1;
	}

	//Initialize OpenGL by calling function Refer to InitAPI
	if (!AppWindow::InitAPI(RenderWindow, hDC, hRC)) {
		MessageBox(NULL, "Fatal Error: Cannot Initialize OpenGL Context! Restart Application", "FATAL ERROR!", MB_OK);
		return 1;
	}

	//Function To create Extra GUI such as Child dialog windows and toolbars etc...
	GUI->CreateToolbars();
	
	Menu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
	SetMenu(MainWindow, Menu);
	return 0;
}

int AppWindow::WinLoop(MSG msg)
{
	while (running)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			//Render Loop plus swapping buffers
			Draw->Render();
			SwapBuffers(hDC);
		}
	}

	return 0;
}

