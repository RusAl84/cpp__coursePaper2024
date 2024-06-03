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
		else
		{
			std::ofstream outFile;          // ����� ��� ������
			outFile.open(filename, std::ios::app); // �������� ���� ��� ������
			// outFile.open(FileName, std::ios::app); // �������� ���� ��� ������
			if (outFile.is_open())
			{
				while (current) {
					outFile << current->surName << endl;
					outFile << current->name << endl;
					outFile << current->middleName << endl;
					outFile << current->faculty << endl;
					outFile << current->department << endl;
					outFile << current->group << endl;
					outFile << current->recordCardNumber << endl;
					string sex = 0;
					if (current->sex)
						sex = "1";
					else
						sex = "0";
					outFile << sex << endl;
					outFile << current->department << endl;
					outFile << current->group << endl;
					outFile << current->recordCardNumber << endl;
					outFile << current->startYear << endl;
					outFile << current->birthDateString << endl;
					for (int i = 0; i < sesCount; i++)
						for (int j = 0; j < namesCount; j++) {
							if (current->examsRecordsData[i][j].isEmpty)
							{
								outFile << "isempty" << endl;
							}
							else
							{
								outFile << "not_empty" << endl;
								outFile << current->examsRecordsData[i][j].mark << endl;
								outFile << current->examsRecordsData[i][j].name << endl;
							}
						}
					outFile << current->avrMark << endl; //!!!!
					current = current->next;
				}
			}
			outFile.close();
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
					if (countItem == 0) {
						newItem->next = NULL;
						myHead = newItem;
					}
					else {
						current = myHead;
						for (int i = 0; i < countItem - 1; i++) {
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

