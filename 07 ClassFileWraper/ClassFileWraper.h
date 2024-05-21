#pragma once
#include <iostream>
#include <Windows.h>
#include "../05 Class Student/StudentClass.h"
#include "stdio.h"

class ClassFileWraper
{
public:
	bool mode; // True - Binary, False - Text
	char filename[100];

	void saveData(StudentNode* sn) {
		struct StudentNode* current = sn;
		FILE* binaryFile;
		fopen_s(&binaryFile, filename, "w");
		while (current) {
			fwrite(current, sizeof(current), 1, binaryFile);
			fclose(binaryFile);
			current = current->next;
		}
	}


	//// 2.	�������� 3 ������(��� ������(records) �� ������� �������� 0) � ���� � �������� �������.
	//fopen_s(&binaryFile, "binaryFile.txt", "rb");
	//fread_s(readRecords, sizeof(readRecords), sizeof(readRecords), 1, binaryFile);
	//fclose(binaryFile);
};

