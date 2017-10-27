//Spencer Ng
//Password Class

#include <iostream>
#include<string>
#include<Windows.h>
#include<vector>
#include<algorithm>
using namespace std;

class Password {
private:
	string password;
	bool passwordLength();
	bool passwordCase();
	bool passwordDigit();
public:
	bool checkPassword();
	void setPassword(string password);
	
};

bool Password::passwordLength() {
	return password.length() >= 6;
}

bool Password::passwordCase() {
	for (int i = 0; i < password.length(); i++)
		if (password[i] >= 'A' && password[i] <= 'Z')
			return true;
	return false;
}

bool Password::passwordDigit() {
	if (password[0] >= '0' && password[0] <= '9')
		return false;
	for (int i = 1; i < password.length(); i++)
		if (password[i] >= '0' && password[i] <= '9')
			return true;
	return false;
}

bool Password::checkPassword() {
	return passwordLength() && passwordCase() && passwordDigit();
}

void Password::setPassword(string password) {
	this->password = password;
}

int main() {
	Password pwd;
	string str;
	do {
		cout << "Enter a password: ";
		cin >> str;
		pwd.setPassword(str);
	} while (!pwd.checkPassword());
	cout << "Password accepted" << endl;

	return 0;
}