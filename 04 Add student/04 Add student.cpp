#include <iostream>
#include <Windows.h>
#include "../03 ExamsResultsClass/ExamsResultsClass.h"
#define lenName 20
#define sesCount 11 // данные о сессиях 5,5 лет для БИСО 
// для БИСО 11 семестров, 
// для БББО 8 семестров - 4 года
#define namesCount 10

using namespace std;

struct ExamsRecords {
	char name[lenName]; // Название дисциплины
	int mark;
	// 0 - не зачтено
	// 1 - зачтено  
	// 2,3,4,5 - оценки
	bool isEmpty; // флаг о том, что ячейка массива пуста (ячейка пуста? да или нет)
};

struct StudentNode
{
	char surName[20]; // Фамилия
	char name[20]; // Имя
	char middleName[20]; // Отчество
	char faculty[30]; // Факультет (название института)
	char department[30]; // Название кафедры
	char group[16]; // шифр группы кафедры
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


void addDefaultStudent(StudentNode *st) {
	sn->id = 0;
	sn->surName = "Русаков";
	sn->name = "Алексей";
	sn->middleName = "Михайлович";
	sn->faculty = "10.05.04 Информационно-аналитические системы безопасности";
	sn->department = "Институт комплексной безопасности и специального приборостроения";
	sn->group = "БИСО-01-21";
	sn->recordСardNumber = "20Б0857";
	sn->sex = true;
	sn->startYear = 2021;
	sn->birthDateString = "27.12.1984";
	ExamsResultsClass* er = new ExamsResultsClass();
	er->add(0, "Яыки программирования 1", 5);
	er->add(0, "Математика 1", 5);
	er->add(0, "Физкультура 1", true);
	er->add(1, "Яыки программирования 2", 5);
	er->add(1, "Математика 2", 5);
	er->add(1, "Физкультура 2", true);
	setExamsResultsData(er, sn);
}



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251);
    cout << "04 Add student\n";
    //ExamsResultsClass* erc = new ExamsResultsClass();
    //erc->editExamsResults();

	StudentNode* st = new StudentNode();
	addDefaultStudent
}

