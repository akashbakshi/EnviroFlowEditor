#include "AppWindow.h"

#include <time.h>

AppWindow *Win = new AppWindow();
MSG msg;
int window_width = 1440;
int window_height = 900;

EFOBJ_HEADER header;
int main() {

	srand(time(NULL));
	Win->CreateClass();
	Win->CreateWindows("EnviroFlow Build UNO", window_width, window_height);
	Win->WinLoop(msg);
}