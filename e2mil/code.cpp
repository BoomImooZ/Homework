#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

	int main(){
		char ch =0;
		bool isPrime = true;
		long long int number=0;
		char symbol;
		ifstream fin("e2mil.txt");
		int x[10];
		int temp = 0;
		for (int i = 0; i < 7; i++) { fin.get(symbol); }				//����������� "� =  2."
		for (int i = 0; i < 10; i++) {									//����������� ����������
			fin.get(symbol);
			if (symbol != '\n') {
				x[i] = symbol - '0';
				number = number + x[i] * pow(10, 9 - i);
			}
			else {
				fin.get(symbol);
				x[i] = symbol - '0';
			}
		}
		while (fin.is_open()) {
			for (int i = 2; i <= (sqrt(abs(number))); i++) {			//�������� �� �������
				if (number%i == 0) {
					isPrime = false;
					break;
				}
				else {isPrime = true; }
			}
			if (isPrime==false) {
				number = 0;
				for (int i = 0; i < 9; i++) {							//����� �� ������ ����� ���� �� ������� �����
					x[i] = x[i + 1];
					number = number + x[i] * pow(10, 9 - i);
				}
				fin.get(symbol);										//���������� ���������� ������� � �����
				if (symbol != '\n') {x[9] = symbol - '0';}	
				else {
					fin.get(symbol); x[9] = symbol - '0';
				}
				number = number + x[9];
			}
			if (isPrime == true) {										// ����� �������� �����
				cout << "is prime  " << number<<'\n';
				fin.close();
			}
		}
		system("pause");
return 0;}
