#include <iostream>
#include <Windows.h>
#include "../03 ExamsResultsClass/ExamsResultsClass.h"
#include "StudentClass.h"


using namespace std;

//struct ExamsRecords {   // !!!описание структуры находится в "../03 ExamsResultsClass/ExamsResultsClass.h"
// !!! Всё в одном месте






int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	cout << "04 Add student\n";
	
	StudentClass* st = new StudentClass();
	StudentNode* sn = new StudentNode();
	st->addDefaultStudent(sn);
	st->editStudent(sn);
}

