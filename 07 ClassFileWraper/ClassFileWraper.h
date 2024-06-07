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
			std::ofstream outFile;          // поток для записи
			outFile.open(filename, std::ios::app); // окрываем файл для записи
			// outFile.open(FileName, std::ios::app); // окрываем файл для записи
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
					string sex = "0";
					if (current->sex)
						sex = "1";
					else
						sex = "0";
					outFile << sex << endl;
					outFile << current->startYear << endl;
					outFile << current->birthDateString << endl;
					for (int i = 0; i < sesCount; i++)
						for (int j = 0; j < namesCount; j++) {
							if (current->examsRecordsData[i][j].isEmpty)
							{
								outFile << "empty" << endl;
							}
							else
							{
								outFile << "not_empty" << endl;
								outFile << current->examsRecordsData[i][j].name << endl;
								outFile << current->examsRecordsData[i][j].mark << endl;
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
			countItem = 0;
			struct StudentNode* myHead = NULL;
			struct StudentNode* newItem = new StudentNode();
			struct StudentNode* current = NULL;
			if (mode)  //binary
			{
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
			else {
				std::ifstream inFile(filename);
				string line;
				while (getline(inFile, line))
				{
					strcpy_s(newItem->surName, sizeof(newItem->surName), line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->name, sizeof(newItem->name), line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->middleName, sizeof(newItem->middleName), line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->faculty, sizeof(newItem->faculty), line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->department, sizeof(newItem->department), line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->group, sizeof(newItem->group), line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->recordCardNumber, sizeof(newItem->recordCardNumber), line.c_str());
					getline(inFile, line);
					if (strcmp(line.c_str(), "1") == 0)
						newItem->sex = 1;
					else 
						newItem->sex = 0;
					getline(inFile, line);
					newItem->startYear = atoi(line.c_str());
					getline(inFile, line);
					strcpy_s(newItem->birthDateString, sizeof(newItem->birthDateString), line.c_str());
					for (int i = 0; i < sesCount; i++)
						for (int j = 0; j < namesCount; j++) {
							getline(inFile, line);
							if (strcmp(line.c_str(), "not_empty") == 0)
							{
								newItem->examsRecordsData[i][j].isEmpty = 0;
								getline(inFile, line);
								strcpy_s(newItem->examsRecordsData[i][j].name, sizeof(newItem->examsRecordsData[i][j].name), line.c_str());
								getline(inFile, line);
								newItem->examsRecordsData[i][j].mark = atoi(line.c_str());
							}
							else
							{
								newItem->examsRecordsData[i][j].isEmpty = 1;
							}	
							//cout << endl << "i= " << i << " j= " << j;
						}
					getline(inFile, line);
					newItem->avrMark = atoi(line.c_str()); //!!!!
					//_getch();
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
				inFile.close();
				return myHead;
			}
		}
	}
};

