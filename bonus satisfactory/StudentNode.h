#pragma once

struct StudentNode
{
	char surName[20]; // Фамилия
	char name[20]; // Имя
	char middleName[20]; // Отчество
	char faculty[60]; // Факультет (название института)
	char department[60]; // Название кафедры
	char group[20]; // шифр группы кафедры
	char recordCardNumber[20]; // номер зачетной книжки
	// int recordCardNumber; // для некоторых вариантов заданий допустимо 
							 // и удобнее использовать целочисленное значение зачетной книжки
	char birthDateString[20]; // дата рождения 
	// int birthDay;
	// int birthMonth;
	// int birthYear;
	bool sex; // Флаг пола true - мальчик
	// false - девочка
// Предполагается бинарный пол
	int startYear; // Год начала обучения
	ExamsRecords examsRecordsData[sesCount][namesCount]; // данные о сессиях 5,5 лет для БИСО 
	// для БИСО 11 семестров, 
	// для БББО 8 семестров - 4 года
	StudentNode* next; // указатель на следующий элемент для динамического списка
	// заранее его здесь создам, чтобы получить оценку хорошо и выше
	// можно добавить позже
	// int id; // id вспомогательная переменная (удобно для некоторых заданий) 
	float avrMark; // средний балл по оценкам (удобно для некоторых заданий)

};