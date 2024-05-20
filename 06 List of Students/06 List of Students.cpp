#include <iostream>
#include <Windows.h>
#include "../05 Class Student/StudentClass.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	cout << "06 List of Students\n";

	StudentClass* st = new StudentClass();
	//StudentNode* sn = new StudentNode();
	//st->addDefaultStudent(sn);
	//st->editStudent(sn);
	st->mainMenu();
}

