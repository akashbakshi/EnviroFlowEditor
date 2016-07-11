#include "AppWindow.h"
#include "EFRender.h"

using namespace std;

PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
bool running=true;
HWND MainWindow;
HWND RenderWindow;
HINSTANCE hInst;

HDC hDC;
HGLRC hRC;

EFRender *Draw = NULL;
AppWindow::AppWindow()
{
}


AppWindow::~AppWindow()
{
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		running = false;
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
		//	running = false;
	}
	else
	{
		hRC = wglCreateContextAttribsARB(hDC, 0, attribs);


		wglDeleteContext(tempContext);

	}
	wglMakeCurrent(hDC, hRC);
	glewInit();
	Draw->Init();
	glewExperimental = TRUE;


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
	MainWindow = CreateWindowEx(WS_EX_APPWINDOW, "EF", name.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, width, height, NULL, NULL, hInst, NULL);
	if (!MainWindow) {
		MessageBox(NULL, "Fatal Error: Cannot Create Main Window, Try Restarting The Application", "FATAL ERROR!", MB_OK);
		return 1;
	}

	RenderWindow = CreateWindow("STATIC", " ", WS_CHILD | WS_VISIBLE, 100, 50, 1440, 900, MainWindow, NULL, hInst, NULL);

	if (!RenderWindow) {
		MessageBox(NULL, "Fatal Error: Cannot Create Render Window, Try Restarting The Application", "FATAL ERROR!", MB_OK);
		return 1;
	}

	AppWindow::InitAPI(RenderWindow, hDC, hRC);
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
			Draw->Render();
			SwapBuffers(hDC);
		}
	}

	return 0;
}

