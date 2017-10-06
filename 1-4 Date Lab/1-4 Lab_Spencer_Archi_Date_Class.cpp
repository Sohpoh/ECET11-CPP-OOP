//Spencer & Archi
//Team 3

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
private:
	string first;
	string last;
	int salary;

public:
	Employee(string f, string l, int s);
	void setFirstName(string f);
	void setLastName(string l);
	void setSalary(int s);
	string getFirstName();
	string getLastName();
	int getSalary();
};

Employee::Employee(string f, string l, int s) {
	first = f;
	last = l;
	if (s > 0)
		salary = s;
	else
		salary = 0;
}

void Employee::setFirstName(string f) {
	first = f;
}

void Employee::setLastName(string l) {
	last = l;
}

void Employee::setSalary(int s) {
	salary = s;
}

string Employee::getFirstName() {
	return first;
}

string Employee::getLastName() {
	return last;
}

int Employee::getSalary() {
	return salary;
}


int main() {
	string f1, l1, f2, l2;
	int s1, s2;

	cout << "Enter first and last name of Employee 1 : ";
	cin >> f1 >> l1;
	cout << "What is his/her montly salary? ";
	cin >> s1;

	cout << "Enter first and last name of Employee 2 : ";
	cin >> f2 >> l2;
	cout << "What is his/her montly salary? ";
	cin >> s2;


	Employee uno = Employee(f1, l1, s1);
	Employee dos = Employee(f2, l2, s2);

	cout << "Yearly Salaries of Employees: " << endl;
	cout << "     " << uno.getFirstName() << " " << uno.getLastName() << ": $ " << (12 * uno.getSalary()) << endl;

	cout << "     " << dos.getFirstName() << " " << dos.getLastName() << ": $ " << (12 * dos.getSalary()) << "\n\n";

	cout << "Salaries after 10% raise: " << endl;
	cout << "     " << uno.getFirstName() << " " << uno.getLastName() << ": $ " << (1.1 * 12 * uno.getSalary()) << endl;
	cout << "     " << dos.getFirstName() << " " << dos.getLastName() << ": $ " << (1.1 * 12 * dos.getSalary()) << endl;
}
