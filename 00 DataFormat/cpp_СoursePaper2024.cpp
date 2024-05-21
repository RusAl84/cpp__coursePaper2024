#include <iostream>
#include <Windows.h>
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
	float avrMark; // средний балл по оценкам (удобно для некоторых заданий)
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	StudentNode st1;
    cout << "Размер записи студента\n" << sizeof(st1) << endl << sizeof(StudentNode);
}

