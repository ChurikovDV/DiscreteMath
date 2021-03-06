// Project01.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
using namespace std;

int i = 0;
int reverseResult[4];

void displayResult(int aArray[], int bArray[], int cArray[], char operation);
void reverseArray(int Array[]);

int main() {

	setlocale(LC_CTYPE, "rus");

	int xArray[4] = { 0, 1, 0, 1 };
	int zeroArray[4] = { 0, 0, 0, 0 };
	int uniArray[4] = { 1, 1, 1, 1 };
	
	cout << "\n	X || X = X\n" << endl;	
	displayResult(xArray, xArray, xArray, '|');

	cout << "\n	X && X = X\n" << endl;
	displayResult(xArray, xArray, xArray, '&');



	cout << "\n	X || O = X\n" << endl;
	displayResult(xArray, zeroArray, xArray, '|');

	cout << "\n	X || U = U\n" << endl;
	displayResult(xArray, uniArray, uniArray, '|');

	cout << "\n	X || !X = U\n" << endl;
	reverseArray(xArray);
	displayResult(xArray, reverseResult, uniArray, '|');



	cout << "\n	X && O = О\n" << endl;
	displayResult(xArray, zeroArray, zeroArray, '&');

	cout << "\n	X && U = X\n" << endl;
	displayResult(xArray, uniArray, xArray, '&');

	cout << "\n	X && !X = U\n" << endl;
	reverseArray(xArray);
	displayResult(xArray, reverseResult, zeroArray, '&');



	system("Pause");
    return 0;
}


void reverseArray(int Array[]) {
	for (i = 0; i < 4; i++) {
		if (Array[i] == 1)  reverseResult[i] = 0;
		else				reverseResult[i] = 1;
	}
}

void displayResult(int aArray[], int bArray[], int cArray[], char operation) {
	for (i = 0; i < 4; i++) {
		cout << "	" << aArray[i] << " " << operation << operation << " " << bArray[i]
			 << " = " << cArray[i] << endl;
	}
	cout << "\n" << endl;
}

