/*(Account Class) Create a class called Account that a bank might
use to represent customers' bank accounts. Your class should
include one data member of type int to represent the account
balance. [Note: In subsequent chapters, we'll use numbers that
contain decimal points (e.g., 2.75) called floating-point values to
represent dollar amounts.] Your class should provide a constructor
that receives an initial balance and uses it to initialize the data
member. The constructor should validate the initial balance to
ensure that it is greater than or equal to 0. If not, the balance
should be set to 0 and the constructor should display an error
message, indicating that the initial balance was invalid. The class
should provide three member functions. Member function credit
should add an amount to the current balance. Member function
debit should withdraw money from the Account and should ensure
that the debit amount does not exceed the Account's balance. If it
does, the balance should be left unchanged and the function
should print a message indicating "Debit amount exceeded account
balance." Member function getBalance should return the current
balance. Create a program that creates two Account objects and
tests the member functions of class Account.*/

//Instance variables are private by  default
//prototype functions ONLY in class definitions; definitions in header files
#include<iostream>
using namespace std;

class Account {

private:
	double balance;
public:
	double getBalance();
	void credit(double);
	void debit(double);
	Account(double);

};

double Account::getBalance() {
	return balance;
}

Account::Account(double balance) {
	if(balance>=0)
		this->balance = balance;
	else {
		this->balance = 0;
		cerr << "Account balance cannot be initially negative\n";
	}
}

void Account::credit(double amount) {
	if (amount >= 0)
		balance += amount;
	else cerr << "Credited amount cannot be negative\n";
}

void Account::debit(double amount) {
	if (amount <= balance && amount>=0)
		balance -= amount;
	else cerr << "Debit amount exceeded account balance or is negative.\n";
}


int main() {
	Account accOne = Account(0), accTwo = Account(2.25);
	accOne.credit(3.25);
	accTwo.debit(3);
	cout << accOne.getBalance() << endl;
	cout << accTwo.getBalance() << endl;
	
}