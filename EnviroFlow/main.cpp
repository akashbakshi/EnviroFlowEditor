#include "AppWindow.h"
#include <time.h>

AppWindow *Win = NULL;
MSG msg;
int main() {
	srand(time(NULL));
	Win->CreateClass();
	Win->CreateWindows("EnviroFlow Build UNO", 1920, 1080);
	Win->WinLoop(msg);
}