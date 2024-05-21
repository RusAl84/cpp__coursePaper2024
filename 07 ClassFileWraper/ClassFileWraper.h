#pragma once
#include <iostream>
#include <Windows.h>
#include "../05 Class Student/StudentClass.h"
#include "../05 Class Student/StudentNode.h"
#include "stdio.h"
#include <string>
#include <fstream>

class ClassFileWraper
{
public:
	bool mode; // True - Binary, False - Text
	char filename[100];
	int countItem;

	bool fileExists() {
		//https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exists-using-standard-c-c11-14-17-c
		struct stat buffer;
		return (stat(filename, &buffer) == 0);
	}

	void delFile() {
		if (fileExists())
			remove(filename);
	}

	void saveData(StudentNode* sn) {
		struct StudentNode* current = sn;
		delFile();
		if (mode)
		{
			FILE* binaryFile;
			fopen_s(&binaryFile, filename, "wb+");
			while (current) {
				fwrite(current, sizeof(StudentNode), 1, binaryFile);
				current = current->next;
			}
			fclose(binaryFile);
		}
	}

	void loadData(StudentNode* sn) {
		if (fileExists()) {
			if (mode)
			{
				struct StudentNode* myHead = NULL;
				struct StudentNode* newItem = new StudentNode();
				FILE* binaryFile;
				fopen_s(&binaryFile, filename, "r");
				countItem = 0;
				while (fread_s(newItem, sizeof(StudentNode), sizeof(StudentNode), 1, binaryFile) == 1)
				{
					//cout << endl<< newItem->surName;
					if (countItem == 0)
						newItem->next = NULL;
					else
						newItem->next = myHead;
					myHead = newItem;
					countItem++;
				}
				fclose(binaryFile);
				sn = myHead;
			}
		}
	}
};

