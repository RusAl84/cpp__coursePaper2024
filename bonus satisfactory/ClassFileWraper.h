#pragma once
#include <iostream>
#include <Windows.h>
#include "StudentClass.h"
#include "StudentNode.h"
#include "stdio.h"
#include <string>
#include <fstream>

class ClassFileWraper
{
public:
	bool mode; // True - Binary, False - Text
	char filename[100];
	int countItem;
	struct StudentNode* myHead;

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
		if (mode) //binary
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

	StudentNode* loadData() {
		if (fileExists()) {
			if (mode)  //binary
			{
				struct StudentNode* myHead = NULL;
				countItem = 0;
				struct StudentNode* newItem = new StudentNode();
				struct StudentNode* current = NULL;
				FILE* binaryFile;
				fopen_s(&binaryFile, filename, "r");
				while (fread_s(newItem, sizeof(StudentNode), sizeof(StudentNode), 1, binaryFile) == 1)
				{
					if (countItem == 0){
						newItem->next = NULL;
						myHead = newItem;
					}
					else {
						current = myHead;
						for (int i = 0; i < countItem-1; i++) {
							current = current->next;
						}
						newItem->next = NULL;
						current->next = newItem;
					}
					countItem++;
					newItem = new StudentNode();
				}
				fclose(binaryFile);
				return myHead;
			}
		}
	}
};

