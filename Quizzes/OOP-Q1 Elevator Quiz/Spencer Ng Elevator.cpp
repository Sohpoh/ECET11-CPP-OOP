#include <iostream>
#include<Windows.h>
using namespace std;

//Spencer Ng

class Elevator {
private:
	int currentFloor;
public:
	Elevator(int);
	void request(int);
};

Elevator::Elevator(int cfloor = 1) {
	if(cfloor<1||cfloor>21)
		currentFloor = 1;
	else currentFloor = cfloor;
	cout << "Creating elevator on floor " << currentFloor << endl;
}

void Elevator::request(int newfloor) {
	if (newfloor < 1 || newfloor>21 || newfloor == currentFloor) {
		cout << "Request Denied\n";
	}
	else if (newfloor > currentFloor) {
		cout << "Floor " << newfloor << " request\nStarting at floor " << currentFloor << endl;
		while (newfloor > currentFloor) {
			currentFloor++;
			cout << " Going Up - now at floor " << currentFloor << endl;
			Sleep(1000);
		}
		cout << "Stopping at floor " << currentFloor << endl;
	}
	else if (newfloor < currentFloor) {
		cout << "Floor " << newfloor << " request\nStarting at floor " << currentFloor << endl;
		while (newfloor < currentFloor) {
			currentFloor--;
			cout << " Going Down - now at floor " << currentFloor << endl;
			Sleep(1000);
		}
		cout << "Stopping at floor " << currentFloor << endl;
	}

	
}

/*int main() {

	int input;
	cout << "Which floor would you like to start at? ";
	cin >> input;
	Elevator buildingElevator = Elevator(input);

	do {
		cout << "\nInput floor number: ";
		cin >> input;
		buildingElevator.request(input);
	} while (true);

	cout << "Never gonna give you up\nNever gonna let you down\n";
	cout << "Never gonna reach here\nForget this";

	exit(0);
}*/