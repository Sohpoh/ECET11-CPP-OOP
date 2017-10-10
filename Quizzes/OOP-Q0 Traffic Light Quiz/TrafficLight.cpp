#include<iostream>
#include<Windows.h>
using namespace std;

class TrafficLight {
private:
	void goService(float);
	void stopService(float);
	void repeatYellowService(float, int);
public:
	void displayMenu();
	void serviceSelect(int, float);

};

void TrafficLight::displayMenu() {
	cout << "1. Go Service\n2. Stop Service\n3. Repeat Yellow Service\n\n";
}

void TrafficLight::serviceSelect(int s, float t) {
	switch (s) {
	case 1:
		goService(t);
		break;
	case 2:
		stopService(t);
		break;
	case 3:
		int repeats;
		cout << "Please enter number of repeats: ";
		cin >> repeats;
		cout << endl;
		repeatYellowService(t, repeats);
		break;
	default:
		cout << "Error: not a valid service\nGoodbye!\n";
		exit(0);
	}
}

void TrafficLight::goService(float t) {
	cout << "\n*** Go service ***\nRed\n";
	Sleep(t);
	cout << "Green\n\n";
}

void TrafficLight::stopService(float t) {
	cout << "\n*** Stop Service ***\nGreen\n";
	Sleep(t);
	cout << "Yellow\n";
	Sleep(t);
	cout << "Red\n\n";
}

void TrafficLight::repeatYellowService(float t, int r) {
	cout << "*** Repeat Service ***\n";
	for (int i = 0; i < r; i++) {
		cout << "Yellow ON\n";
		Sleep(t);
		cout << "Yellow OFF\n";
		Sleep(t);
	}
	cout << endl;
}

int main() {
	TrafficLight trafficLight = TrafficLight();
	trafficLight.displayMenu();

	int serviceNum;
	float time;

	while (true) {
		cout << "Enter service: ";
		cin >> serviceNum;
		cout << "Please enter time: ";
		cin >> time;
		
		trafficLight.serviceSelect(serviceNum, time*1000);
	}

}