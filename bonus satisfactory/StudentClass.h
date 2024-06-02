#pragma once
#include <iostream>
#include <Windows.h>
#include "ExamsResultsClass.h"
#include "ClassFileWraper.h"
#include "StudentNode.h"


class StudentClass 
{
public:

	static void addDefaultStudent(StudentNode* sn) {
		//sn->id = 0;

		strcpy_s(sn->surName, sizeof(sn->surName), "Русаков");
		strcpy_s(sn->name, sizeof(sn->name), "Алексей");
		strcpy_s(sn->middleName, sizeof(sn->middleName), "Михайлович");
		strcpy_s(sn->faculty, sizeof(sn->faculty), "10.05.04 Информационно-аналитические системы безопасности");
		strcpy_s(sn->department, sizeof(sn->department), "Институт кибербезопасности и цифровых технологий");
		strcpy_s(sn->group, sizeof(sn->group), "БИСО-03-23");
		strcpy_s(sn->recordCardNumber, sizeof(sn->recordCardNumber), "20Б0857");
		sn->sex = true;
		sn->startYear = 2021;
		strcpy_s(sn->birthDateString, sizeof(sn->birthDateString), "27.12.1984");
		ExamsResultsClass* er = new ExamsResultsClass();
		er->add(0, "Яыки программирования 1", 5);
		er->add(0, "Математика 1", 5);
		er->add(0, "Физкультура 1", true);
		er->add(1, "Яыки программирования 2", 5);
		er->add(1, "Математика 2", 5);
		er->add(1, "Физкультура 2", true);
		for (int i = 0; i < sesCount; i++)
			for (int j = 0; j < namesCount; j++) {
				sn->examsRecordsData[i][j].isEmpty = er->data[i][j].isEmpty;
				if (sn->examsRecordsData[i][j].isEmpty)
				{
					sn->examsRecordsData[i][j].mark = 0;
					strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), "");
				}
				else
				{
					sn->examsRecordsData[i][j].mark = er->data[i][j].mark;
					strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), er->data[i][j].name);
				}
			}
		sn->next = NULL;
		delete er;
	}

	bool editSex() {
		ClassMenu* sexMenu = new ClassMenu();
		int resultSelectedItem = 1;
		const int exitItem = 3;
		sexMenu->addTitleItem("Выберите пол: ");
		sexMenu->addItem("мужской");
		sexMenu->addItem("женский");
		while (resultSelectedItem != exitItem) {
			sexMenu->run();
			resultSelectedItem = sexMenu->getSelectedItem();
			switch (resultSelectedItem) {
			case 0:
				return true;
				resultSelectedItem = exitItem;
				break;
			case 1:
				return false;
				resultSelectedItem = exitItem;
				break;
			default:
				break;
			}
		}
	}

	void editStudent(StudentNode* sn)
	{
		ClassMenu* studDataMenu = new ClassMenu();
		int resultStudDataMenu = 1;
		const int exitStudDataMenu = 0;
		ClassEdit* ce = new  ClassEdit();
		ExamsResultsClass* erc = new ExamsResultsClass();
		studDataMenu->addItem("Выход");   //0
		studDataMenu->addItem("Добавить/изменить фамилию"); //1
		studDataMenu->addItem("Добавить/изменить имя");   //2
		studDataMenu->addItem("Добавить/изменить отчество");   //3
		studDataMenu->addItem("Добавить/изменить институт");   //4
		studDataMenu->addItem("Добавить/изменить кафедру");   //5
		studDataMenu->addItem("Добавить/изменить группу");   //6
		studDataMenu->addItem("Добавить/изменить номер зачетной книжки");   //7
		studDataMenu->addItem("Добавить/изменить пол");   //
		studDataMenu->addItem("Добавить/изменить год поступления в ВУЗ");   //8
		studDataMenu->addItem("Добавить/изменить дату рождения");   //9
		studDataMenu->addItem("Добавить/изменить оценки");   //10
		int day, month, year;
		while (resultStudDataMenu != exitStudDataMenu) {
			studDataMenu->eraseTitle();
			studDataMenu->addTitleItem("Изменение/добавление данных о студенте:");
			studDataMenu->addTitleItem("Фамилия: " + string(sn->surName) + " Имя: " + string(sn->name) + " Отчество: " + string(sn->middleName));
			string sexString = "";
			if (sn->sex)
				sexString = "мужской";
			else { sexString = "женский"; }
			studDataMenu->addTitleItem("пол: " + sexString + " дата рождения: " + string(sn->birthDateString) + " год поступления:" + std::to_string(sn->startYear));
			studDataMenu->addTitleItem("Номер зачетной книжки: " + string(sn->recordCardNumber) + " Группа: " + string(sn->group));
			studDataMenu->addTitleItem("Институт: " + string(sn->faculty));
			studDataMenu->addTitleItem("Кафедра: " + string(sn->department));
			studDataMenu->run();
			resultStudDataMenu = studDataMenu->getSelectedItem();
			string tmpString = "";
			int year = 0;
			int startYear = 0;
			switch (resultStudDataMenu) {
			case 0:
				resultStudDataMenu = exitStudDataMenu;
				break;
			case 1:
				ce->setLabel("Введите фамилию. ");
				strcpy_s(sn->surName, sizeof(sn->surName), ce->setDataString(sn->surName).c_str());
				break;
			case 2:
				ce->setLabel("Введите имя. ");
				strcpy_s(sn->name, sizeof(sn->name), ce->setDataString(sn->name).c_str());
				break;
			case 3:
				ce->setLabel("Введите отчество. ");
				strcpy_s(sn->middleName, sizeof(sn->middleName), ce->setDataString(sn->middleName).c_str());
				break;
			case 4:
				ce->setLabel("Введите название института. ");
				strcpy_s(sn->faculty, sizeof(sn->faculty), ce->setDataString(sn->faculty).c_str());
				break;
			case 5:
				ce->setLabel("Введите название кафедры. ");
				strcpy_s(sn->department, sizeof(sn->department), ce->setDataString(sn->department).c_str());
				break;
			case 6:
				ce->setLabel("Введите группу. ");
				strcpy_s(sn->group, sizeof(sn->group), ce->setDataString(sn->group).c_str());
				break;
			case 7:
				ce->setLabel("Введите номер зачетной книжки. ");
				strcpy_s(sn->recordCardNumber, sizeof(sn->recordCardNumber), ce->setDataString(sn->recordCardNumber).c_str());
				break;
			case 8:
				ce->setLabel("Введите пол. ");
				sn->sex = editSex();        ////
				break;
			case 9:
				ce->setLabel("Введите год поступления в ВУЗ. ");
				startYear = ce->setDataInt(1996, 2023, 2023);
				//tmpString = sb->split(sn->birthDateString.c_str(), '.', 3);
				year = atoi(tmpString.c_str());
				if (year == 0)
					sn->startYear = startYear;
				else
				{
					if (startYear - year >= 15) {
						sn->startYear = startYear;
					}
					else
					{
						cout << "Ошибка год поступления в институт должен быть на 15 лет больше чем год рождения";
						_getch();
					}
				}
				break;
			case 10:
				ce->setLabel("Введите день рождения. ");
				day = ce->setDataInt(1, 31, 31);
				ce->setLabel("Введите месяц рождения. ");
				month = ce->setDataInt(1, 12, 12);
				ce->setLabel("Введите год рождения. ");
				year = ce->setDataInt(1900, 2014, 2004);
				if (sn->startYear < 1990) {
					cout << "Ошибка год поступления в институт должен быть не ранее 1990";
					_getch();
				}
				else
				{
					if (sn->startYear - year >= 13) {
						string tmpStr = to_string(day) + "." + to_string(month) + "." + to_string(year);
						strcpy_s(sn->birthDateString, sizeof(sn->birthDateString), tmpStr.c_str());
					}
					else
					{
						cout << "Ошибка год поступления в институт должен быть на 13 лет больше чем год рождения";
						_getch();
					}
				}
				break;
			case 11:
				ce->setLabel("Просмотреть/ изменить оценки.");
				for (int i = 0; i < sesCount; i++)
					for (int j = 0; j < namesCount; j++) {
						erc->data[i][j].isEmpty = sn->examsRecordsData[i][j].isEmpty;
						if (erc->data[i][j].isEmpty)
						{
							erc->data[i][j].mark = 0;
							strcpy_s(erc->data[i][j].name, sizeof(erc->data[i][j].name), "");
						}
						else
						{
							erc->data[i][j].mark = sn->examsRecordsData[i][j].mark;
							strcpy_s(erc->data[i][j].name, sizeof(erc->data[i][j].name), sn->examsRecordsData[i][j].name);
						}
					}
				erc->editExamsResults();
				for (int i = 0; i < sesCount; i++)
					for (int j = 0; j < namesCount; j++) {
						sn->examsRecordsData[i][j].isEmpty = erc->data[i][j].isEmpty;
						if (sn->examsRecordsData[i][j].isEmpty)
						{
							sn->examsRecordsData[i][j].mark = 0;
							strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), "");
						}
						else
						{
							sn->examsRecordsData[i][j].mark = erc->data[i][j].mark;
							strcpy_s(sn->examsRecordsData[i][j].name, sizeof(sn->examsRecordsData[i][j].name), erc->data[i][j].name);
						}
					}

				break;
			default:
				break;
			}
		}
		delete erc;
		delete studDataMenu;
		delete ce;
	}


	double getAvrMarks(StudentNode* sn) {
		double sum = 0;
		double count = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 10; j++)
				if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
					sum = sum + sn->examsRecordsData[i][j].mark;
					count++;
				}
		int avr = 0;
		if (count > 0)
			avr = sum / count;
		return avr;
	}

	double getMarks45(StudentNode* sn) {
		double sum = 0;
		double count = 0;
		for (int i = 0; i < sesCount; i++)
			for (int j = 0; j < namesCount; j++)
				if (sn->examsRecordsData[i][j].isEmpty == false and sn->examsRecordsData[i][j].mark > 1) {
					count++;
					if (sn->examsRecordsData[i][j].mark > 3)
						sum++;
				}
		double proc = 0;
		if (count > 0)
			proc = sum / count;
		return proc;
	}

	//list
	struct StudentNode* myHead;
	int countItem = 0;

	StudentClass() {
		countItem = 0;
		myHead = NULL;
	}

	//Визуализация для добавления и удаления элементов в односвязном списке.
	//https://www.cs.usfca.edu/~galles/visualization/StackLL.html

	void addItem()
	{
		struct StudentNode* newItem = new StudentNode();
		//newItem->StudentNode = data;
		addDefaultStudent(newItem);
		editStudent(newItem);
		if (countItem == 0)
			newItem->next = NULL;
		else
			newItem->next = myHead;
		myHead = newItem;
		countItem++;
	}

	void insertItem(int index) {
		if (not (index >= 0 and index <= countItem and countItem >= 0))
			return;
		if (index == 0) {
			addItem();
		}
		else
		{
			struct StudentNode* current = myHead;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}
			struct StudentNode* newItem = new StudentNode();
			//newItem->data = data;
			addDefaultStudent(newItem);
			editStudent(newItem);
			newItem->next = current->next;
			current->next = newItem;
			countItem++;
		}
	}

	void editItem(int index) {
		if (index >= 0 and index < countItem and countItem>0) {
			struct StudentNode* current = myHead;
			for (int i = 0; i < index; i++) {
				current = current->next;
				//cout << "+" << current->data;
			}
			//current->data = data;
			editStudent(current);
		}
		else {
			cout << endl << "Ошибка индекс не в диапазоне";
		}
	}

	void deleteItem(int index) {
		if (index >= 0 and index < countItem and countItem>0) {
			struct StudentNode* current = myHead;
			struct StudentNode* old;
			if (index == 0) {
				old = myHead;
				myHead = current->next;
				delete old;
				countItem--;
			}
			else {
				int i = 0;
				while (current) {
					if (i == index - 1) {
						old = current->next->next;
						delete current->next;
						current->next = old;
						countItem--;
						break;
					}
					i++;
					current = current->next;
				}
			}
		}
	}

	void printMyList() {
		struct StudentNode* current = myHead;
		cout << endl;
		while (current) {
			//cout << " " << current->data;
			cout << " " << current->surName;
			current = current->next;
		}
	}

	//list

	StudentNode* getItem(int index) {
		struct StudentNode* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
			//cout << "+" << current->data;
		}
		return current;
	}



	//
	void mainMenu() {
		ClassMenu* mainMenu = new ClassMenu();
		mainMenu->addTitleItem("Главное меню");
		mainMenu->addItem("Просмотреть список студетов (удалить или изменить данные)"); //0
		mainMenu->addItem("Добавить данные о студенте в БД"); //1
		mainMenu->addItem("Загрузить студентов из файла БД"); //2
		mainMenu->addItem("Сохранить БД студентов в файл"); //3
		mainMenu->addItem("Выполнить вариант XX"); //4
		mainMenu->addItem("Выход"); //5
		int resultSelectedItem = 0;
		int exitInt = 4;
		ClassMenu* studentsMenu = new ClassMenu();
		studentsMenu->addTitleItem("Список студентов");
		int resultStudentSelectedItem = 1;
		const int exitIntStudentMenu = 0;
		StudentNode* sn;
		StudentClass* st = new StudentClass();
		ClassMenu* delStudentsMenu = new ClassMenu();
		int curCount;
		ClassEdit* ce = new  ClassEdit();
		int startYear = 0;
		int endYear = 0;
		int year = 0;
		string firstPartString;
		//sort
		ClassFileWraper* cfw = new ClassFileWraper();
		strcpy_s(cfw->filename, sizeof(cfw->filename), "dataBinary.txt");
		cfw->mode = true; // Binary     //!!!!!!!!!!!!!!!!!!!!!!!!!!!
		this->myHead = cfw->loadData();
		countItem = cfw->countItem;
		//sort
		while (resultSelectedItem != exitInt) {
			mainMenu->run();
			resultSelectedItem = mainMenu->getSelectedItem();
			switch (resultSelectedItem) {
			case 0:
				resultStudentSelectedItem = 1;
				while (resultStudentSelectedItem != exitIntStudentMenu) {
					studentsMenu->eraseItem();
					studentsMenu->addItem("Выход");
					studentsMenu->addItem("Удалить данные о студенте");
					struct StudentNode* current = myHead;
					while (current) {
						string tmpString = string(current->surName) + " " + string(current->name) + " " + string(current->middleName) + " " + string(current->birthDateString);
						studentsMenu->addItem(tmpString); //добавить в меню студентов
						current = current->next;
					}
					studentsMenu->run();
					resultStudentSelectedItem = studentsMenu->getSelectedItem();
					//if (resultStudentSelectedItem == exitIntStudentMenu) {
					//	break;
					//}
					if (resultStudentSelectedItem == 1) //удаление данных о студенте
					{
						delStudentsMenu->eraseAll();
						delStudentsMenu->addTitleItem("Выберите студента для удаления данных");
						delStudentsMenu->addItem("Выход");
						int resultDel = 1;
						const int exitDel = 0;
						struct StudentNode* current = myHead;
						while (current) {
							string tmpString = string(current->surName) + " " + string(current->name) + " " + string(current->middleName) + " " + string(current->birthDateString);
							delStudentsMenu->addItem(tmpString); //добавить в меню студентов
							current = current->next;
						}
						while (resultDel != exitDel) {
							delStudentsMenu->run();
							resultDel = delStudentsMenu->getSelectedItem();
							if (resultDel == exitDel) {
								break;
							}
							else {
								int num = resultDel - 1;
								//sdb->DataBase.erase(std::next(sdb->DataBase.begin(), num));
								deleteItem(num);
								break;
							}
						}
					}
					if (resultStudentSelectedItem > 1)
					{
						int num = resultStudentSelectedItem - 2;
						editItem(num);
						//можно сделать проверку есть ли такая ещё 
					}
				}
				//resultSelectedItem = exitInt;
				break;
			case 1: //Добавить студента
				addItem();
				break;
			case 2: //Загрузить студентов из файла БД
				//sort 
				this->myHead = cfw->loadData();  //todo delete memory leak
				countItem = cfw->countItem;
				break;
			case 3: //Сохранить БД студентов в файл
				//sort
				cfw->saveData(myHead);
				break;
			case 4: //Выполнить вариант XX
				//printAllSurName_Name_MName_bYaear_AvrMarks();
				processingAvrMarks();
				//printAllSurName_Name_MName_bYaear_AvrMarks();
				sort();
				printAllSurName_Name_MName_bYaear_AvrMarks();
				_getch();
				resultSelectedItem = 0;
				break;
			case 5:
				resultSelectedItem = exitInt;
				break;
			default:
				break;
			}
		}
		//_getch();
	}

	//sort
	void processingAvrMarks() {
		struct StudentNode* current = myHead;
		while (current) {
			current->avrMark = getAvrMarks(current);
			current = current->next;
		}
	}

	StudentNode* getElement(int ind) {
		struct StudentNode* current = myHead;
		for (int i = 0; i < ind; i++) {
			current = current->next;
		}
		return current;
	}

	//                                 current куда            element что
	void  copyDataElement(StudentNode* current, StudentNode* element) {
		strcpy_s(current->surName, sizeof(current->surName), element->surName);
		strcpy_s(current->name, sizeof(current->name), element->name);
		strcpy_s(current->middleName, sizeof(current->middleName), element->middleName);
		strcpy_s(current->faculty, sizeof(current->faculty), element->faculty);
		strcpy_s(current->department, sizeof(current->department), element->department);
		strcpy_s(current->group, sizeof(current->group), element->group);
		strcpy_s(current->recordCardNumber, sizeof(current->recordCardNumber), element->recordCardNumber);
		current->sex = element->sex;
		current->startYear = element->startYear;
		strcpy_s(current->birthDateString, sizeof(current->birthDateString), element->birthDateString);
		for (int i = 0; i < sesCount; i++)
			for (int j = 0; j < namesCount; j++) {
				current->examsRecordsData[i][j].isEmpty = element->examsRecordsData[i][j].isEmpty;
				if (current->examsRecordsData[i][j].isEmpty)
				{
					current->examsRecordsData[i][j].mark = 0;
					strcpy_s(current->examsRecordsData[i][j].name, sizeof(current->examsRecordsData[i][j].name), "");
				}
				else
				{
					current->examsRecordsData[i][j].mark = element->examsRecordsData[i][j].mark;
					strcpy_s(current->examsRecordsData[i][j].name, sizeof(current->examsRecordsData[i][j].name), element->examsRecordsData[i][j].name);
				}
			}
		current->avrMark = element->avrMark; //!!!!
	}
	void  setElement(int ind, StudentNode* element) {
		struct StudentNode* current = myHead;
		for (int i = 0; i < ind; i++) {
			current = current->next;
		}
		copyDataElement(current, element);
	}
	void sort() {
		//https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
		//https://www.geeksforgeeks.org/bubble-sort/
		int size = countItem;
		struct StudentNode* tmp1 = new StudentNode();
		struct StudentNode* tmp2 = new StudentNode();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (getElement(j)->avrMark > getElement(j + 1)->avrMark) {
					copyDataElement(tmp1, getElement(j));
					copyDataElement(tmp2, getElement(j + 1));
					setElement(j + 1, tmp1);
					setElement(j, tmp2);
					//copyDataElement(tmp1, getElement(0));
					//copyDataElement(tmp2, getElement(3));
					//setElement(3, tmp1);
					//setElement(0, tmp2);
				}
			}
		}
	}

	void printAllSurName_Name_MName_bYaear_AvrMarks() {
		struct StudentNode* current = myHead;
		cout << endl;
		while (current) {
			//cout << " " << current->data;
			cout << string(current->surName) + " " + string(current->name) + " " + string(current->middleName) + " " + string(current->birthDateString) + " " + to_string(current->avrMark) << endl;
			current = current->next;
		}
		//_getch();
	}
	//sort


};

