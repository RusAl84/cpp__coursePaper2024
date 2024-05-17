#include <iostream>
#include "ClassEdit.h"


bool editSex() {
	ClassMenu* sexMenu = new ClassMenu();
	int resultSelectedItem = 1;
	const int exitItem = 3;
	sexMenu->addTitleItem("Выберите пол: ");
	sexMenu->addItem("мужской");
	sexMenu->addItem("женский");
	while (resultSelectedItem != exitItem) {
		sexMenu->run();
		resultSelectedItem = sexMenu->getSelectedItem();
		switch (resultSelectedItem) {
		case 0:
			return true;
			resultSelectedItem = exitItem;
			break;
		case 1:
			return false;
			resultSelectedItem = exitItem;
			break;
		default:
			break;
		}
	}
}

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
    day = ce->setDataInt(1, 31, 17);

    int year;
    ce->setLabel("Введите год рождения. ");
    year = ce->setDataInt(1900, 2012, 1984);

    delete ce;

    cout << endl << "Введенная фамилия: " << surName << endl;
    cout << "Введенный день рождения: " << day << endl;
    cout << "Введенный год рождения: " << year << endl;
}

