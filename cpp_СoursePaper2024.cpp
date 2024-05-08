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
	char name;
	char middleName;
	char faculty;
	char department;
	char group;
	char recordÑardNumber;
	char birthDateString;
	bool sex; // true - ìàëü÷èê
	// false - äåâî÷êà
	int startYear;

	ExamsRecords examsRecordsData[9][10];
	StudentNode* next;
	int id;
};

int main()
{
    std::cout << "Hello World!\n";
}

