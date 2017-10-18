//Spencer & Archi
//Team 3
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Polynomial {

private:
	int coefficients[9];
	int degree;
public:
	Polynomial(int coefficients[]);
	void setCoefficients(int coefficients[]);
	int* getCoefficients();
	void displayPolynomial();
	Polynomial operator+(const Polynomial &);
	Polynomial operator-(const Polynomial &);
	void operator+=(const Polynomial &);
	Polynomial operator*(const Polynomial &);
};


Polynomial Polynomial::operator*(const Polynomial& rhs) {
	int newCoeff[9];
	for (int i = 0; i < 9; i++)
		newCoeff[i] = 0;
	for (int i = 4; i < 9; i++)
		for (int j = 4; j < 9; j++)
			newCoeff[(8 - i) + (8 - j)] += this->coefficients[i] * rhs.coefficients[j];
	for (int i = 0; i < 4; i++) {
		int temp = newCoeff[i];
		newCoeff[i] = newCoeff[8 - i];
		newCoeff[8 - i] = temp;
	}
		
	return Polynomial(newCoeff);
}

void Polynomial::operator+=(const Polynomial& rhs) {
	for (int i = 0; i < 9; i++)
		this->coefficients[i] += rhs.coefficients[i];
}

Polynomial Polynomial::operator-(const Polynomial& rhs) {
	int newCoeff[9];
	for (int i = 0; i < 9; i++)
		newCoeff[i] = this->coefficients[i] - rhs.coefficients[i];
	return Polynomial(newCoeff);
}

Polynomial Polynomial::operator+(const Polynomial& rhs) {
	int newCoeff[9];
	for (int i = 0; i < 9; i++)
		newCoeff[i] = this->coefficients[i] + rhs.coefficients[i];
	return Polynomial(newCoeff);
}

int * Polynomial::getCoefficients() {
	return coefficients;
}

void Polynomial::setCoefficients(int coefficients[]) {
	for (int i = 0; i < 9; i++)
		this->coefficients[i] = coefficients[i];
}

Polynomial::Polynomial(int coefficients[]) {
	for (int i = 0; i < 9; i++)
		this->coefficients[i] = coefficients[i];
	
}

void Polynomial::displayPolynomial() {
	bool firstOutput = true;
	for (int i = 0; i < 9; i++)
		if (coefficients[i] != 0) {
			if (coefficients[i] > 0 && !firstOutput)
				cout << " + ";
			if (coefficients[i] < 0)
				cout << " - ";
			if (abs(coefficients[i]) != 1 || i == 8) {
				cout << abs(coefficients[i]);
				
			}
			if (8 - i != 0) {
				firstOutput = false;
				cout << "x";
				if (8 - i != 1)
					cout << "^" << 9 - i - 1;
			}
			
		}
	cout << endl;
}

int main() {
	
	int coefficients[9];
	int degree;

	char choice;
	do {
		system("cls");
		cout << "Enter the degree of P1 (up to 4): ";
		cin >> degree;
		cout << "Enter the " << degree + 1 << " coefficient(s) of P1 (separate each with a space, highest degree first): ";
		for (int i = 0; i < 9 - (degree + 1); i++)
			coefficients[i] = 0;
		for (int i = 9 - (degree + 1); i < 9; i++)
			cin >> coefficients[i];

		Polynomial p1(coefficients);

		cout << "Enter the degree of P2 (up to 4): ";
		cin >> degree;
		cout << "Enter the " << degree + 1 << " coefficient(s) of P2 (separate each with a space, highest degree first): ";
		for (int i = 0; i < 9 - (degree + 1); i++)
			coefficients[i] = 0;
		for (int i = 9 - (degree + 1); i < 9; i++)
			cin >> coefficients[i];

		Polynomial p2(coefficients);
		cout << "P1 = "; p1.displayPolynomial();
		cout << "P2 = "; p2.displayPolynomial();
		cout << "P1 + P2 = ";  (p1 + p2).displayPolynomial();
		cout << "P1 - P2 = "; (p1 - p2).displayPolynomial();
		cout << "P2 - P1 = "; (p2 - p1).displayPolynomial();
		cout << "P1 * P2 = "; (p1*p2).displayPolynomial();

		cout << "\nContinue? (Y/N)" << endl;
		cin >> choice;
	} while (tolower(choice) != 'n');
	return 0;
}