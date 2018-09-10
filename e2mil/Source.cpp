#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int temp = 0;
	ifstream fin("e2mil_test.txt");
	char x[10];
	long long int number=0;
	char symbol;
	if (temp == 0) {
		for (int i = 0; i < 10; i++) {				//изначальное заполнение
			fin.get(symbol);
			if (symbol != '\n') {
				x[i] = symbol - '0';
				number = number + x[i] * pow(10, 9 - i);
			} //возможно потребуется что то придумать если возникнет проблема когда будет конец строки
			else i--;
		}
		temp++;}
	number = 0;
	for (int i = 0; i < 9; i++) {				//заполнение если не простое число
		x[i] = x[i + 1];
		number = number + x[i] * pow(10, 9 - i);
	}
	fin.get(symbol);
	if (symbol != '\n') { x[9] = symbol - '0'; }
	number = number + x[9];
	cout << number << '\n';

		
	
	return 0;
}