// Project01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
using namespace std;

int tempArray1[4];
int tempArray2[4];
	
int resultArray1[4];
int resultArray2[4];

int finalArray1[4];
int finalArray2[4];

int i = 0;

void copyArray(int aArray[], int bArray[]);

void isArraysEqual(int aArray[] = finalArray1, int bArray[] = finalArray2);

void arraysMulti(int aArray[], int bArray[]);
void arraysSum(int aArray[], int bArray[]);


int main()
{
	setlocale(LC_CTYPE, "rus");

	int xArray[4] = { 1, 1, 0, 1 };
	int yArray[4] = { 0, 0, 1, 1 };
	int zArray[4] = { 1, 1, 0, 0 };

	int xArrayReverse[4] = { 0, 0, 1, 0 };
	int yArrayReverse[4] = { 1, 1, 0, 0 };
	int zArrayReverse[4] = { 0, 0, 1, 1 };


	
	cout << "			Закон поглощения\n" << endl;
	cout << "X || (X && Y) = X" << endl;
	cout << "X && (X || Y) = X" << endl;

	arraysMulti(xArray, yArray);// 2 функции можно менять местами
	arraysSum(xArray, tempArray1);// 2 функции можно менять местами

	copyArray(tempArray2, finalArray1);
	copyArray(xArray, finalArray2);
	
	cout << "Результат:" << endl;
	isArraysEqual();
	

	cout << "\n			Закон склеивания\n" << endl;
	cout << "(X && Y) || (X && !Y) = X" << endl;
	cout << "(X || Y) && (X || !Y) = X" << endl;

	arraysMulti(xArray, yArray);
	copyArray(tempArray1, resultArray1);
	arraysMulti(xArray, yArrayReverse);
	copyArray(tempArray1, resultArray2);
	arraysSum(resultArray1, resultArray2);

	copyArray(xArray, finalArray1);
	copyArray(tempArray2, finalArray2);

	cout << "Результат:" << endl;
	isArraysEqual();
	
	system("pause");
    return 0;
}

void copyArray(int aArray[], int bArray[]) {
	for (i = 0; i < 4; i++)	{
		bArray[i] = aArray[i];
	}
}

void isArraysEqual(int aArray[], int bArray[]) {
	int check = 0;
	for (int i = 0; i < 4; i++) {
		if (aArray[i] == bArray[i]) {
			check++;
			cout << "Cлева от знака равно. Элемент "<< i << ")    " << aArray[i] 
				 << " = " << bArray[i] << "    " << i << " Элемент. Результат справа от знака равно." << endl;
		}
		else {
			cout << "Слева от знака равно. Элемент " << i << ")    " << aArray[i] << " != " 
				 << bArray[i]  << "    " << i << " Элемент. Результат справа от знака равно." << endl;
		}
	}
	if (check == 4) {
		cout << "Закон доказан\n" << endl;
	}
	else {
		cout << "Закон не доказан\n" << endl;
	}

}
void arraysMulti(int aArray[], int bArray[]) {
	for (int i = 0; i < 4; i++) {
		if (aArray[i] == 1 && bArray[i] == 1) {
			tempArray1[i] = 1;
		}
		else {
			tempArray1[i] = 0;
		}
	}
}

void arraysSum(int aArray[], int bArray[]) {
	for (int i = 0; i < 4; i++) {
		if (aArray[i] == 1 || bArray[i] == 1) {
			tempArray2[i] = 1;
		}
		else {
			tempArray2[i] = 0;
		}
	}
}

