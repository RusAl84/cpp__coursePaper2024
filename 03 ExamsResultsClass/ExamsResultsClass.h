#pragma once
#include <string.h>
#define lenName 20
#define sesCount 11
#define namesCount 10

struct ExamsRecords {
	char name[lenName]; // Ќазвание дисциплины
	int mark;
	// 0 - не зачтено
	// 1 - зачтено  
	// 2,3,4,5 - оценки
	bool isEmpty; // флаг о том, что €чейка массива пуста (€чейка пуста? да или нет)
};


class ExamsResultsClass
{
	//private:
	//	 ExamsRecords data[sesCount][namesCount];
public:
	ExamsRecords data[sesCount][namesCount];
	ExamsResultsClass() {
		emptpy();
	}

	void emptpy() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				data[i][j].isEmpty = true;
	}
	bool add(int sess, string item, int mark) {  //ƒл€ оценок
		int firstEmptyRow = getFirstEmptyRow(sess);
		if (firstEmptyRow < 9) {
			data[sess][firstEmptyRow].isEmpty = false;
			// Copy the source string to the destination string.
			// strcpy_s(dest, sizeof(dest), src); https://hatchjs.com/how-to-use-strcpy_s/
			//data[sess][firstEmptyRow].name= item;
			strcpy_s(data[sess][firstEmptyRow].name, sizeof(data[sess][firstEmptyRow].name), item.c_str());
			data[sess][firstEmptyRow].mark = mark;
			return true;
		}
		else
			return false;
	}
	bool add(int sess, string itemName, bool zach) { //ƒл€ зачетов
		int mark = 0;
		if (zach)
			mark = 1;
		else
			mark = 0;
		int firstEmptyRow = getFirstEmptyRow(sess);
		if (firstEmptyRow < 9) {
			data[sess][firstEmptyRow].isEmpty = false;
			data[sess][firstEmptyRow].name = itemName;
			data[sess][firstEmptyRow].mark = mark;
			return true;
		}
		else
			return false;
	}

	int getFirstEmptyRow(int sessNum) {
		for (int i = 0; i < 10; i++)
			if (data[sessNum][i].isEmpty)
				return i;
		return -1;
	}

};

