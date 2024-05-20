#include <iostream>
#include <Windows.h>
#include "../03 ExamsResultsClass/ExamsResultsClass.h"


using namespace std;

//struct ExamsRecords {   // !!!описание структуры находится в "../03 ExamsResultsClass/ExamsResultsClass.h"
// !!! Всё в одном месте

struct StudentNode
{
	char surName[20]; // Фамилия
	char name[20]; // Имя
	char middleName[20]; // Отчество
	char faculty[60]; // Факультет (название института)
	char department[60]; // Название кафедры
	char group[20]; // шифр группы кафедры
	char recordCardNumber[20]; // номер зачетной книжки
	// int recordCardNumber; // для некоторых вариантов заданий допустимо 
							 // и удобнее использовать целочисленное значение зачетной книжки
	char birthDateString[20]; // дата рождения 
	// int birthDay;
	// int birthMonth;
	// int birthYear;
	bool sex; // Флаг пола true - мальчик
	// false - девочка
// Предполагается бинарный пол
	int startYear; // Год начала обучения
	ExamsRecords examsRecordsData[sesCount][namesCount]; // данные о сессиях 5,5 лет для БИСО 
	// для БИСО 11 семестров, 
	// для БББО 8 семестров - 4 года
	StudentNode* next; // указатель на следующий элемент для динамического списка
	// заранее его здесь создам, чтобы получить оценку хорошо и выше
	// можно добавить позже
// int id; // id вспомогательная переменная (удобно для некоторых заданий) 
// float avrMark; // средний балл по оценкам (удобно для некоторых заданий)
};



void addDefaultStudent(StudentNode *sn) {
	//sn->id = 0;

	strcpy_s(sn->surName, sizeof(sn->surName), "Русаков");
	strcpy_s(sn->name, sizeof(sn->name), "Алексей");
	strcpy_s(sn->middleName, sizeof(sn->middleName), "Михайлович");
	strcpy_s(sn->faculty, sizeof(sn->faculty), "10.05.04 Информационно-аналитические системы безопасности");
	strcpy_s(sn->department, sizeof(sn->department), "Институт кибербезопасности и цифровых технологий");
	strcpy_s(sn->group, sizeof(sn->group), "БИСО-03-23");
	strcpy_s(sn->recordCardNumber, sizeof(sn->recordCardNumber), "20Б0857");
	sn->sex = true;
	sn->startYear = 2021;
	strcpy_s(sn->birthDateString, sizeof(sn->birthDateString), "27.12.1984");
	ExamsResultsClass* er = new ExamsResultsClass();
	er->add(0, "Яыки программирования 1", 5);
	er->add(0, "Математика 1", 5);
	er->add(0, "Физкультура 1", true);
	er->add(1, "Яыки программирования 2", 5);
	er->add(1, "Математика 2", 5);
	er->add(1, "Физкультура 2", true);
	for (int i = 0; i < sesCount; i++)
		for (int j = 0; j < namesCount; j++) {
			sn->examsRecordsData[i][j].isEmpty = er->data[i][j].isEmpty;
			if (sn->examsRecordsData[i][j].isEmpty)
			{ 
				sn->examsRecordsData[i][j].mark = 0;
				strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), "");
			}
			else
			{
				sn->examsRecordsData[i][j].mark = er->data[i][j].mark;
				strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), er->data[i][j].name);
			}
		}
	delete er;
}



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

void editStudent(StudentNode* sn)
{
	ClassMenu* studDataMenu = new ClassMenu();
	int resultStudDataMenu = 1;
	const int exitStudDataMenu = 0;
	ClassEdit* ce = new  ClassEdit();
	ExamsResultsClass* erc = new ExamsResultsClass();
	studDataMenu->addItem("Выход");   //0
	studDataMenu->addItem("Добавить/изменить фамилию"); //1
	studDataMenu->addItem("Добавить/изменить имя");   //2
	studDataMenu->addItem("Добавить/изменить отчество");   //3
	studDataMenu->addItem("Добавить/изменить институт");   //4
	studDataMenu->addItem("Добавить/изменить кафедру");   //5
	studDataMenu->addItem("Добавить/изменить группу");   //6
	studDataMenu->addItem("Добавить/изменить номер зачетной книжки");   //7
	studDataMenu->addItem("Добавить/изменить пол");   //
	studDataMenu->addItem("Добавить/изменить год поступления в ВУЗ");   //8
	studDataMenu->addItem("Добавить/изменить дату рождения");   //9
	studDataMenu->addItem("Добавить/изменить оценки");   //10
	int day, month, year;
	while (resultStudDataMenu != exitStudDataMenu) {
		studDataMenu->eraseTitle();
		studDataMenu->addTitleItem("Изменение/добавление данных о студенте:");
		studDataMenu->addTitleItem("Фамилия: " + string(sn->surName) + " Имя: " + string(sn->name) + " Отчество: " + string(sn->middleName));
		string sexString = "";
		if (sn->sex) 
			sexString = "мужской";
		else { sexString = "женский"; }
		studDataMenu->addTitleItem("пол: " + sexString + " дата рождения: " + string(sn->birthDateString) + " год поступления:" + std::to_string(sn->startYear));
		studDataMenu->addTitleItem("Номер зачетной книжки: " + string(sn->recordCardNumber) + " Группа: " + string(sn->group));
		studDataMenu->addTitleItem("Институт: " + string(sn->faculty));
		studDataMenu->addTitleItem("Кафедра: " + string(sn->department));
		studDataMenu->run();
		resultStudDataMenu = studDataMenu->getSelectedItem();
		string tmpString = "";
		int year = 0;
		int startYear = 0;
		switch (resultStudDataMenu) {
		case 0:
			resultStudDataMenu = exitStudDataMenu;
			break;
		case 1:
			ce->setLabel("Введите фамилию. ");
			strcpy_s(sn->surName, sizeof(sn->surName), ce->setDataString(sn->surName).c_str());
			break;
		case 2:
			ce->setLabel("Введите имя. ");
			strcpy_s(sn->name, sizeof(sn->name), ce->setDataString(sn->name).c_str());
			break;
		case 3:
			ce->setLabel("Введите отчество. ");
			strcpy_s(sn->middleName, sizeof(sn->middleName), ce->setDataString(sn->middleName).c_str());
			break;
		case 4:
			ce->setLabel("Введите название института. ");
			strcpy_s(sn->faculty, sizeof(sn->faculty), ce->setDataString(sn->faculty).c_str());
			break;
		case 5:
			ce->setLabel("Введите название кафедры. ");
			strcpy_s(sn->department, sizeof(sn->department), ce->setDataString(sn->department).c_str());
			break;
		case 6:
			ce->setLabel("Введите группу. ");
			strcpy_s(sn->group, sizeof(sn->group), ce->setDataString(sn->group).c_str());
			break;
		case 7:
			ce->setLabel("Введите номер зачетной книжки. ");
			strcpy_s(sn->recordCardNumber, sizeof(sn->recordCardNumber), ce->setDataString(sn->recordCardNumber).c_str());
			break;
		case 8:
			ce->setLabel("Введите пол. ");
			sn->sex = editSex();        ////
			break;
		case 9:
			ce->setLabel("Введите год поступления в ВУЗ. ");
			startYear = ce->setDataInt(1996, 2023, 2023);
			//tmpString = sb->split(sn->birthDateString.c_str(), '.', 3);
			year = atoi(tmpString.c_str());
			if (year == 0)
				sn->startYear = startYear;
			else
			{
				if (startYear - year >= 15) {
					sn->startYear = startYear;
				}
				else
				{
					cout << "Ошибка год поступления в институт должен быть на 15 лет больше чем год рождения";
					_getch();
				}
			}

			break;
		case 10:
			ce->setLabel("Введите день рождения. ");
			day = ce->setDataInt(1, 31, 31);
			ce->setLabel("Введите месяц рождения. ");
			month = ce->setDataInt(1, 12, 12);
			ce->setLabel("Введите год рождения. ");
			year = ce->setDataInt(1900, 2014, 2004);
			if (sn->startYear < 1990) {
				cout << "Ошибка год поступления в институт должен быть не ранее 1990";
				_getch();
			}
			else
			{
				if (sn->startYear - year >= 13) {
					string tmpStr = to_string(day) + "." + to_string(month) + "." + to_string(year);
					strcpy_s(sn->birthDateString, sizeof(sn->birthDateString), tmpStr.c_str());
				}
				else
				{
					cout << "Ошибка год поступления в институт должен быть на 13 лет больше чем год рождения";
					_getch();
				}
			}
			break;
		case 11:
			ce->setLabel("Просмотреть/ изменить оценки.");
			for (int i = 0; i < sesCount; i++)
				for (int j = 0; j < namesCount; j++) {
					erc->data[i][j].isEmpty = sn->examsRecordsData[i][j].isEmpty;
					if (erc->data[i][j].isEmpty)
					{
						erc->data[i][j].mark = 0;
						strcpy_s(erc->data[i][j].name, sizeof(erc->data[i][j].name), "");
					}
					else
					{
						erc->data[i][j].mark = sn->examsRecordsData[i][j].mark;
						strcpy_s(erc->data[i][j].name, sizeof(erc->data[i][j].name), sn->examsRecordsData[i][j].name);
					}
				}
			erc->editExamsResults();
			for (int i = 0; i < sesCount; i++)
				for (int j = 0; j < namesCount; j++) {
					sn->examsRecordsData[i][j].isEmpty = erc->data[i][j].isEmpty;
					if (sn->examsRecordsData[i][j].isEmpty)
					{
						sn->examsRecordsData[i][j].mark = 0;
						strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), "");
					}
					else
					{
						sn->examsRecordsData[i][j].mark = erc->data[i][j].mark;
						strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), erc->data[i][j].name);
					}
				}
			
			break;
		default:
			break;
		}
	}
	delete erc;
	delete studDataMenu;
	delete ce;
}


double getAvrMarks(StudentNode* sn) {
	double sum = 0;
	double count = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 10; j++)
			if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
				sum = sum + sn->examsRecordsData[i][j].mark;
				count++;
			}
	int avr = 0;
	if (count > 0)
		avr = sum / count;
	return avr;
}

double getMarks45(StudentNode* sn) {
	double sum = 0;
	double count = 0;
	for (int i = 0; i < sesCount; i++)
		for (int j = 0; j < namesCount; j++)
			if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
				count++;
				if (sn->examsRecordsData[i][j].mark > 3)
					sum++;
			}
	double proc = 0;
	if (count > 0)
		proc = sum / count;
	return proc;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    cout << "04 Add student\n";
	StudentNode* st = new StudentNode();
	addDefaultStudent(st);
	editStudent(st);
}

