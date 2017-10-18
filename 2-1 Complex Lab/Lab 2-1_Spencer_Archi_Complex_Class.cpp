//Spencer Ng
//Team 3
#include<iostream>
using namespace std;

class Complex {
private:
	
public:
	float realPart, imaginaryPart;
	Complex(float real, float imaginary);
	Complex add(Complex numTwo);
	Complex subtract(Complex numTwo);
	void printNum();
};

Complex Complex::add(Complex numTwo) {
	return Complex(realPart + numTwo.realPart, imaginaryPart + numTwo.imaginaryPart);
}

Complex Complex::subtract(Complex numTwo) {
	return Complex(realPart - numTwo.realPart, imaginaryPart - numTwo.imaginaryPart);
}

void Complex::printNum() {
	cout << "(" << realPart << ", " << imaginaryPart << ")" << endl;
}

Complex::Complex(float real = 0, float imaginary = 0) {
	realPart = real;
	imaginaryPart = imaginary;
}

int main() {
	char choice;
	float real, imaginary;
	do {
		cout << "Enter real part of num 1: ";
		cin >> real;
		cout << "Enter imaginary part of num 1: ";
		cin >> imaginary;
		cout << endl;
		Complex num1(real, imaginary);

		cout << "Enter real part of num 2: ";
		cin >> real;
		cout << "Enter imaginary part of num 2: ";
		cin >> imaginary;

		Complex num2(real, imaginary);

		system("cls");

		cout << "Num 1 is ";
		num1.printNum();

		cout << "Num 2 is ";
		num2.printNum();
		cout << endl;
		cout << "Enter desired operation:\n1: num1 + num2\n2: num1 - num2\n3: num2 - num1\n";
		cin >> choice;
		
		switch (choice) {
		case '1':
			cout << "\nResult is";
			num1.add(num2).printNum();
			break;
		case '2':
			cout << "\nResult is";
			num1.subtract(num2).printNum();
			break;
		case '3':
			cout << "\nResult is";
			num2.subtract(num1).printNum();
			break;
		default:
			cout << "Invalid choice. Please try again.\n\n";
		}

		cout << "Would you like to continue? (Y/N)" << endl;
		cin >> choice;
		system("cls");
	} while (tolower(choice) != 'n');

	return 0;
}

