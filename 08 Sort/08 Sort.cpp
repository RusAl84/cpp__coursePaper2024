#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include "../05 Class Student/StudentClass.h"
//#include "../07 ClassFileWraper/ClassFileWraper.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	cout << "08 Sort \n";
	StudentClass* st = new StudentClass();
	st->mainMenu();
}

