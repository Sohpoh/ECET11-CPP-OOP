//Spencer Ng
//Car Class
#include <iostream>
#include<string>
#include<Windows.h>
using namespace std;



class Car {
private:
	string make;
	string model;
	int speed;

public:
	Car(string make, string model);
	string getMake();
	string getModel();
	int getSpeed();
	bool accelerate(int speed);
	bool deAccelerate(int speed);

};

Car::Car(string make, string model) {
	this->make = make;
	this->model = model;
	this->speed = 0;
}

string Car::getMake() {
	return make;
}

string Car::getModel() {
	return model;
}

int Car::getSpeed() {
	return speed;
}

bool Car::accelerate(int speed) {
	if (speed >= 0 && speed <= 100 && speed % 5 == 0) {
		cout << "\n" << make << " " << model << " accelerating:" << endl;
		for (int i = 0; i < speed / 5; i++) {
			cout << "*";
			if (i != speed / 5 - 1)
				Sleep(1000);
		}
		cout << "\nFinal speed = " << speed << " mph" << endl;
		this->speed = speed;
		return true;
	}
	else {
		cout << "ERROR: Acceleration Speed doesn't fit the requirements" << endl;
		return false;
	}
}

bool Car::deAccelerate(int speed) {
	if (speed >= 0 && speed <= 100 && speed % 5 == 0) {
		cout << "\n" <<  make << " " << model << " de-accelerating:" << endl;
		for (int i = 0; i < this->speed / 5; i++)
			cout << "*";
		if (this->speed != 5)
			Sleep(1000);
		
		for (int i = 0; i < (this->speed - speed) / 5; i++) {
			cout << "\b \b";
			if (i != (this->speed - speed) / 5 - 1) {
				
				Sleep(1000);
			}
		}
		this->speed = speed;
		cout << "\nFinal speed = " << getSpeed() << " mph" << endl;
		return true;
	}
	else {
		cout << "ERROR: De-acceleration Speed doesn't fit the requirements" << endl;
		return false;
	}
}

int main() {

	string make, model;
	int as, das;
	bool aflag, daflag;

	cout << "Enter make: "; cin >> make;
	cout << "Enter model: "; cin >> model;

	Car c1(make, model);

	do {
		cout << "\nEnter desired acceleration Speed: ";
		cin >> as;
		aflag = c1.accelerate(as);
	} while (aflag == false);
	do {
		cout << "\nEnter desired de-acceleration Speed: ";
		cin >> das;
		daflag = c1.deAccelerate(das);
	} while (daflag == false);
	return 0;
}