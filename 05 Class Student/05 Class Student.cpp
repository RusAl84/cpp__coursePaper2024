#include <iostream>
#include <Windows.h>
#include "StudentClass.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	cout << "05 Class Student\n";
	
	StudentClass* st = new StudentClass();
	StudentNode* sn = new StudentNode();
	st->addDefaultStudent(sn);
	st->editStudent(sn);
}

