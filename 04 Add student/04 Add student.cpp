﻿#include <iostream>
#include <Windows.h>
#include "ExamsResultsClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    cout << "04 Add student\n";
    ExamsResultsClass* erc = new ExamsResultsClass();
    erc->editExamsResults();
}

