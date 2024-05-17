#include <iostream>
#include "ClassEdit.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    ClassEdit* ce = new  ClassEdit();
    cout << "Эксперименты с вводом данных!\n";

    string surName;
    ce->setLabel("Введите фамилию. ");
    surName = ce->setDataString("Русаков");

    int day;
    ce->setLabel("Введите день рождения. ");
    day = ce->setDataInt(1, 31);
    
    int year;
    ce->setLabel("Введите год рождения. ");
    year = ce->setDataInt(1900, 2012);

    delete ce;




}

