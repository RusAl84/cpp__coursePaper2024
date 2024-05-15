#include <iostream>
#include <Windows.h>

using namespace std;

struct ExamsRecords {
	char name[20]; // Название дисциплины
	int mark;
	// 0 - не зачтено
	// 1 - зачтено  
	// 2,3,4,5 - оценки
	bool isEmpty; // флаг о том, что ячейка массива пуста?
};

struct StudentNode
{
	char surName[20]; // Фамилия
	char name[20]; // Имя
	char middleName[20]; // Отчество
	char faculty[20]; // Факультет (название института)
	char department[20]; // Название кафедры
	char group[20]; // шифр группы кафедры
	char recordCardNumber[20]; // зачетной книжки
	// int recordCardNumber; // для некоторых вариантов заданий допустимо использовать 
	// целочисленное значение зачетной книжки
	char birthDateString[20]; // дата рождения 
	// int birthDay;
	// int birth;
	// int birthDay;
	bool sex[20]; // Флак пола true - мальчик
	// false - девочка
	// Предполагается бинарный пол
	int startYear; // Год начала обучения
	ExamsRecords examsRecordsData[11][10]; // данные о сессиях 5,5 лет для БИСО 
	// для БИСО 11 семестров, для БББО 8 семестров - 4 года
	StudentNode* next; // указатель на следующий элемент для динамического списка
	// int id; // id вспомогательная переменная (удобно для некоторых заданий) 
	// float avrMark; // средний балл по оценкам (удобно для некоторых заданий)
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	StudentNode st1;
    cout << "Размер записи студента\n" << sizeof(st1) << endl << sizeof(StudentNode);
}

