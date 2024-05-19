#pragma once
#include <string.h>
#include <string>
#define lenName 20
#define sesCount 11
#define namesCount 10
#include "ClassMenu.h"
#include "ClassEdit.h"

using namespace std;

struct ExamsRecords {
	char name[lenName]; // Название дисциплины
	int mark;
	// 0 - не зачтено
	// 1 - зачтено  
	// 2,3,4,5 - оценки
	bool isEmpty; // флаг о том, что ячейка массива пуста (ячейка пуста? да или нет)
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
	bool add(int sess, string itemName, int mark) {  //Для оценок
		int firstEmptyRow = getFirstEmptyRow(sess);
		if (firstEmptyRow < 9) {
			data[sess][firstEmptyRow].isEmpty = false;
			// Copy the source string to the destination string.
			// strcpy_s(dest, sizeof(dest), src); https://hatchjs.com/how-to-use-strcpy_s/
			//data[sess][firstEmptyRow].name= itemName;
			strcpy_s(data[sess][firstEmptyRow].name, sizeof(data[sess][firstEmptyRow].name), itemName.c_str());
			data[sess][firstEmptyRow].mark = mark;
			return true;
		}
		else
			return false;
	}
	bool add(int sess, string itemName, bool zach) { //Для зачетов
		int mark = 0;
		if (zach)
			mark = 1;
		else
			mark = 0;
		int firstEmptyRow = getFirstEmptyRow(sess);
		if (firstEmptyRow < 9) {
			data[sess][firstEmptyRow].isEmpty = false;
			//data[sess][firstEmptyRow].name = itemName;
			strcpy_s(data[sess][firstEmptyRow].name, sizeof(data[sess][firstEmptyRow].name), itemName.c_str());
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

	void editExamsResults() {
		ClassMenu* sesMenu = new ClassMenu();
		int result = 1;
		const int exit = 0;
		ClassMenu* msMenu = new ClassMenu();
		int resultS = 1;
		const int exitS = 0;
		ClassEdit* ce = new  ClassEdit();
		ExamsResultsClass* erc = new ExamsResultsClass();
		sesMenu->addItem("Выход");   //0
		for (int i = 1; i < 10; i++) {
			sesMenu->addItem("Сессия " + std::to_string(i));
		}
		while (result != exit) {
			sesMenu->eraseTitle();
			sesMenu->addTitleItem("Просмотр/изменение/добавление данных о оценках за все сессии");
			sesMenu->addTitleItem("Выберите сессию для просмотра и редактирования информации об оценках");
			sesMenu->run();
			result = sesMenu->getSelectedItem();
			if (result == exit) {
				result = exit;
				break;
			}
			int curSess = result;
			if ((curSess >= 1) and (curSess <= 10))
			{
				//рисуем меню и правим оценки про сессию
				msMenu->eraseAll();
				msMenu->addTitleItem("Просмотр/изменение/добавление данных о оценках");
				msMenu->addTitleItem("Данные сессии №" + std::to_string(curSess));
				resultS = 1;
				while (resultS != exitS) {
					msMenu->eraseItem();
					msMenu->addItem("Выход");
					msMenu->addItem("Добавить запись");
					msMenu->addItem("Удалить запись");
					for (int i = 0; i < 10; i++)
						if (not sn->examsRecordsData[curSess - 1][i].isEmpty)
						{
							string markString = "";
							int markInt = sn->examsRecordsData[curSess - 1][i].mark;
							if (markInt == 0) markString = "не зачтено";
							if (markInt == 1) markString = "зачтено";
							if ((markInt >= 2) and (markInt <= 5)) {
								markString = std::to_string(markInt);
							}
							msMenu->addItem("Предмет: " + sn->examsRecordsData[curSess - 1][i].name + " Оценка: " + markString);
						}
					msMenu->run();
					resultS = msMenu->getSelectedItem();
					if (resultS == 0)
						resultS == exitS;
					if (resultS == 1) {
						int itemNum = msMenu->getItemsCount() - 3;
						if (itemNum > 9) {
							system("cls");
							cout << "Ошибка в сессию бывает только 10 дисциплин для зачетов или экзаменов";
							_getch();  //!!!!!!!!!!!!!!!????????
							_getch();
						}
						else {
							addExamsResults(sn, curSess, itemNum);
						}
					}
					if (resultS == 2) {
						//Удалить запись
						delExamsResults(sn, curSess);
					}
					if (resultS > 2) {
						addExamsResults(sn, curSess, resultS - 3);
					}
				}
			}
			result = curSess;
		}
	}
	void addExamsResults(StudentNode* sn, int curSess, int curItem) {
		ClassEdit* ce = new  ClassEdit();
		ce->setLabel("Введите название предмета. ");
		sn->examsRecordsData[curSess - 1][curItem].name = ce->setDataString(sn->examsRecordsData[curSess - 1][curItem].name);
		int resultS = 1;
		const int exitS = 0;
		ClassMenu* msMenu = new ClassMenu();
		msMenu->addTitleItem("Выберите оценку");
		msMenu->addItem("не зачтено"); //0
		msMenu->addItem("зачтено"); //1
		msMenu->addItem("2"); //2	
		msMenu->addItem("3"); //3		
		msMenu->addItem("4"); //4		
		msMenu->addItem("5"); //5
		resultS = 1;
		while (resultS != exitS) {
			msMenu->run();
			resultS = msMenu->getSelectedItem();
			// 0 - не зачет  
			// 1 - зачет  
			// 2,3,4,5 - оценки
			sn->examsRecordsData[curSess - 1][curItem].mark = resultS;
			resultS = exitS;
		}
		sn->examsRecordsData[curSess - 1][curItem].isEmpty = false;
	}
	void delExamsResults(int curSess) {
		ClassEdit* ce = new  ClassEdit();
		int resultS = 1;
		const int exitS = 0;
		ClassMenu* msMenu = new ClassMenu();
		msMenu->addTitleItem("Выберите запись для удаления");
		resultS = 1;
		while (resultS != exitS) {
			msMenu->eraseItem();
			msMenu->addItem("Выход");
			for (int i = 0; i < 10; i++)
				if (not sn->examsRecordsData[curSess - 1][i].isEmpty)
				{
					string markString = "";
					int markInt = sn->examsRecordsData[curSess - 1][i].mark;
					if (markInt == 0) markString = "не зачтено";
					if (markInt == 1) markString = "зачтено";
					if ((markInt >= 2) and (markInt <= 5)) {
						markString = std::to_string(markInt);
					}
					msMenu->addItem("Предмет: " + sn->examsRecordsData[curSess - 1][i].name + " Оценка: " + markString);
				}
			msMenu->run();
			resultS = msMenu->getSelectedItem();
			if (resultS == exitS)
				resultS == exitS;
			else
			{
				sn->examsRecordsData[curSess - 1][resultS - 1].isEmpty = true;
				//Дефрагментация массива
				ExamsResultsClass* er = new ExamsResultsClass();
				for (int i = 0; i < 10; i++)
					if (not sn->examsRecordsData[curSess - 1][i].isEmpty)
						er->add(0, sn->examsRecordsData[curSess - 1][i].name, sn->examsRecordsData[curSess - 1][i].mark);
				//er->add(0, "Яыки программирования 1", 5);
				for (int i = 0; i < 10; i++)
					sn->examsRecordsData[curSess - 1][i].isEmpty = true;
				for (int i = 0; i < 10; i++)
					if (not er->data[0][i].isEmpty) {
						sn->examsRecordsData[curSess - 1][i].isEmpty = false;
						sn->examsRecordsData[curSess - 1][i].name = er->data[0][i].name;
						sn->examsRecordsData[curSess - 1][i].mark = er->data[0][i].mark;
					}
			}
		}
	}
	//bool isSameNameExamsResults(StudentNode* sn) {
	//	for (int curSess = 0; curSess < 9; curSess++) {
	//		for (int i = 0; i < 10; i++)
	//			for (int j = 0; j < 10; j++)
	//				if (sn->examsRecordsData[curSess][i].isEmpty == false and sn->examsRecordsData[curSess][j].isEmpty == false and i != j)
	//					if (strcmp(sn->examsRecordsData[curSess][i].name.c_str(), sn->examsRecordsData[curSess][j].name.c_str()) == 0)
	//						return true;
	//	}
	//	return false;
	//}
	//double getAvrMarks(StudentNode* sn) {
	//	double sum = 0;
	//	double count = 0;
	//	for (int i = 0; i < 9; i++)
	//		for (int j = 0; j < 10; j++)
	//			if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
	//				sum = sum + sn->examsRecordsData[i][j].mark;
	//				count++;
	//			}
	//	int avr = 0;
	//	if (count > 0)
	//		avr = sum / count;
	//	return avr;
	//}



};

