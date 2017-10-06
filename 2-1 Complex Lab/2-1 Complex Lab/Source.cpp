#include<iostream>
using namespace std;

class Complex {
private:
	
public:
	float realPart, imaginaryPart;
	Complex(float real, float imaginary);
	Complex add(Complex numOne, Complex numTwo);
	Complex subtract(Complex numOne, Complex numTwo);
	void printNum();
};

Complex Complex::add(Complex numOne, Complex numTwo) {
	return Complex(numOne.realPart + numTwo.realPart, numOne.imaginaryPart + numTwo.imaginaryPart);
}

Complex Complex::subtract(Complex numOne, Complex numTwo) {
	return Complex(numOne.realPart - numTwo.realPart, numOne.imaginaryPart - numTwo.imaginaryPart);
}

void Complex::printNum() {
	cout << "(" << realPart << ", " << imaginaryPart << ")";
}

Complex::Complex(float real = 0, float imaginary = 0) {
	realPart = real;
	imaginaryPart = imaginary;
}



