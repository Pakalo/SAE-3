#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32 
#include "app.h"
#include "ui.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32
	ArgReader(argv, argc);
}
