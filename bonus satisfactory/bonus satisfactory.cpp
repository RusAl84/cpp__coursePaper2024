#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include "StudentClass.h"
//https://learn.microsoft.com/ru-ru/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);

	cout << "Курсовая работа \n";
	StudentClass* st = new StudentClass();
	st->mainMenu();
}