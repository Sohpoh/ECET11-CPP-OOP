//Spencer Ng
//Class name

#include <iostream>
#include<string>
#include<Windows.h>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

class CheckWriter {
private:
	string company;
	string date;
	string fullName;
	float amount;
public:
	void setCompany(string company);
	void setDate(string date);
	void setName(string name);
	void setAmount(float amount);
	void printCheck();
};

char capitalize(char c) {
	if(c>='a' && c<= 'z')
		return c-32;
	return c;
}

string truncate(string s, int numChars) {
	string result = "";
	for (int i = 0; i < numChars && i < s.length(); i++) {
		result += s[i];
	}
	return result;
}

void CheckWriter::setCompany(string company) {
	this->company = truncate(company, 20) + " inc.";
}

void CheckWriter::setDate(string date) {
	string newDate = "";
	if (date[1] == '-') {
		newDate += "0";
		newDate += date[0];
	}
	else {
		newDate += date[0];
		newDate += date[1];
	}
	newDate += "/";
	int i = 0;
	while (date[i] != '-')
		i++;
	for (i+=1; date[i]!='-'; i++) {
		newDate += date[i];
	}
	newDate += '/';
	newDate += date[date.length() - 2];
	newDate += date[date.length() - 1];

	this->date = newDate;
}

void CheckWriter::setName(string name) {
	string newName = "";
	name = truncate(name, 20);
	for (int i = 0; i < name.length(); i++) {
		if (i == 0 || name[i - 1] == ' ')
			newName += capitalize(name[i]);
		else newName += name[i];
	}

	this->fullName = newName;
}



void CheckWriter::setAmount(float amount) {
	if (amount >= 0 && amount <= 9999.99)
		this->amount = amount;
	else this->amount = 1000;
}

string amountToWords(float amount) {
	float origAmount = amount;
	string finalString = "";
	int thousand = 0, hundred = 0, ten = 0, one = 0;
	int cents = 0;
	while (amount >= 1000) {
		thousand++;
		amount -= 1000;
	}
	while (amount >= 100) {
		hundred++;
		amount -= 100;
	}
	while (amount >= 10) {
		ten++;
		amount -= 10;
	}
	while (amount >= 1) {
		one++;
		amount--;
	}
	cents = amount * 100;

	switch (thousand) {
	case 1:
		finalString+= "one thousand ";
		break;
	case 2:
		finalString+= "two thousand ";
		break;
	case 3:
		finalString+= "three thousand ";
		break;
	case 4:
		finalString+= "four thousand ";
		break;
	case 5:
		finalString+= "five thousand ";
		break;
	case 6:
		finalString+= "six thousand ";
		break;
	case 7:
		finalString+= "seven thousand ";
		break;
	case 8:
		finalString+= "eight thousand ";
		break;
	case 9:
		finalString+= "nine thousand ";
		break;
	
		
	}
	switch (hundred) {
	case 1:
		finalString += "one hundred ";
		break;
	case 2:
		finalString += "two hundred ";
		break;
	case 3:
		finalString += "three hundred ";
		break;
	case 4:
		finalString += "four hundred ";
		break;
	case 5:
		finalString += "five hundred ";
		break;
	case 6:
		finalString += "six hundred ";
		break;
	case 7:
		finalString += "seven hundred ";
		break;
	case 8:
		finalString += "eight hundred ";
		break;
	case 9:
		finalString += "nine hundred ";
		break;
	

	}
	switch (ten) {
	case 1:
		if (one == 0)
			finalString += "ten ";
		if (one == 1)
			finalString += "eleven ";
		if (one == 2)
			finalString += "twelve ";
		if (one == 3)
			finalString += "thirteen ";
		if (one == 4)
			finalString += "fourteen ";
		if (one == 5)
			finalString += "fifteen ";
		if (one == 6)
			finalString += "sixteen ";
		if (one == 7)
			finalString += "seventeen ";
		if (one == 8)
			finalString += "eighteen ";
		if (one == 9)
			finalString += "nineteen ";
		break;
	case 2:
		finalString += "twenty ";
		break;
	case 3:
		finalString += "thirty ";
		break;
	case 4:
		finalString += "forty ";
		break;
	case 5:
		finalString += "fifty ";
		break;
	case 6:
		finalString += "sixty ";
		break;
	case 7:
		finalString += "seventy ";
		break;
	case 8:
		finalString += "eighty ";
		break;
	case 9:
		finalString += "ninety ";
		break;
	

	}
	if (ten != 1) {
		switch (one) {
		case 1:
			finalString += "one ";
			break;
		case 2:
			finalString += "two ";
			break;
		case 3:
			finalString += "three ";
			break;
		case 4:
			finalString += "four ";
			break;
		case 5:
			finalString += "five ";
			break;
		case 6:
			finalString += "six ";
			break;
		case 7:
			finalString += "seven ";
			break;
		case 8:
			finalString += "eight ";
			break;
		case 9:
			finalString += "nine ";
			break;
		

		}
	}
	if (finalString != "") {
		
		finalString[0] = capitalize(finalString[0]);
	}
	if (cents != 0 && finalString != "") {
		finalString += "and ";
	}
	cout << finalString;
	if(cents!=0){
		cout << int(round(100*origAmount)) % 100 << " cents";
		int i = 0;
		while (i < to_string(origAmount).length()) {
			if (to_string(origAmount)[i] == '.')
				break;
			i++;
		}
		i++;
		for (; i < to_string(origAmount).length(); i++)
			finalString += to_string(origAmount)[i];

		finalString += " cents";
	}
	cout << endl;
	return finalString;
	
}

void CheckWriter::printCheck() {
	setfill('-');
	for (int i = 0; i < 80; i++) 
		cout << '-';
	cout << endl << "|" << endl;
	cout << "| " << company;
	for (int i = 0; i < 55 - company.length(); i++)
		cout << " ";
	cout << "Date: " << date << endl << "|" << endl;
	string nameStatement = "Pay to the order of: " + fullName;
	cout << "| " << nameStatement;
	for (int i = 0; i < 55 - nameStatement.length(); i++)
		cout << " ";
	cout << "$" << amount << endl;
	cout << "| ";
	amountToWords(amount);
	
	cout << "|" << endl;
	for (int i = 0; i < 80; i++)
		cout << '-';
	
}



int main() {
	
	
	CheckWriter check;
	string dcompany, ddate, dfullName;
	float damount;
	cout << "Enter company name: ";
	getline(cin, dcompany);
	check.setCompany(dcompany);
	cout << "Enter date: ";
	getline(cin, ddate);
	check.setDate(ddate);
	cout << "Enter Employee full name: ";
	getline(cin, dfullName);
	check.setName(dfullName);
	cout << "Enter amount: ";
	cin >> damount;
	check.setAmount(damount);

	check.printCheck();



	return 0;
}