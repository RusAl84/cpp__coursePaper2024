#include <iostream>

struct ExamsRecords {
	char name[20];
	int mark;
	// 0 - не зачтено
	// 1 - зачтено  
	// 2,3,4,5 - оценки
	bool isEmpty; // флаг о том, что ячейка массива пуста?
};

struct StudentNode
{
	char surName[20];
	char name[20];
	char middleName[20];
	char faculty[20];
	char department[20];
	char group[20];
	char recordCardNumber[20];
	char birthDateString[20];
	bool sex[20]; // true - мальчик
	// false - девочка
	int startYear;

	ExamsRecords examsRecordsData[9][10];
	StudentNode* next;
	int id;
};

int main()
{
    std::cout << "Hello World!\n";
}

