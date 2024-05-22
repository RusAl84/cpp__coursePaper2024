#include <iostream>
#include "ClassMenu.h"


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
			return true; // мужской
			resultSelectedItem = exitItem;
			break;
		case 1:
			return false; // женский
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
    cout << "Эксперименты с вводом пола и меню!" << endl;

	bool sex;
	sex = editSex();

	string sexString;
	if (sex)
		sexString = "мужской";
	else
		sexString = "женский";

	cout << endl << "Вы ввели \"" << sexString << "\" пол";

}

