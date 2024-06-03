#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include "../05 Class Student/StudentClass.h"
#include "ClassFileWraper.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	cout << "07 ClassFileWraper\n";
	ClassFileWraper* cfw = new ClassFileWraper();
	strcpy_s(cfw->filename, sizeof(cfw->filename), "dataBinary.txt");
	//cfw->mode = true; // Binary
	cfw->mode = false; // text
	//StudentClass* st = new StudentClass();
	//StudentNode* sn = new StudentNode();
	//st->addItem();
	//st->addItem();
	//st->addItem();
 //   cfw->saveData(st->myHead);
	cfw->loadData();
}

