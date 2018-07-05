//Spencer Ng
//Team 3

#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;


int main() {
	
	string digit[] = { "", "ONE", "TWO", "THREE", "FOUR", 
		"FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

	string tens[] = { "TWENTY" , "THIRTY", "FORTY",
		"FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY" };

	string teens[] = { "TEN" , "ELEVEN", "TWELVE",
		"THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN",
		"SEVENTEEN", "EIGHTEEN", "NINETEEN" };

	while (true) {
		float amount;
		cout << "Enter amount: $";
		cin >> amount;

		if (amount >= 1000 || amount <= 0)
			cout << "Please enter an amount less than $1000\n\n";

		else {

			int hundred = int(amount) / 100;
			int ten = (int(amount) / 10) % 10;
			int one = int(amount) % 10;
			int cents = (int)floor(amount * 100) % 100;

			if (hundred != 0) {
				cout << digit[hundred] + " HUNDRED";
				if (ten != 0 || one != 0)
					cout << " ";
			}
			if (ten == 1)
				cout << teens[one];
			else {
				if (ten > 1) {
					cout << tens[ten - 2];
					if (one != 0)
						cout << " ";
				}
				cout << digit[one];
			}
			if (hundred + ten + one != 0)
				cout << " and ";
			cout << cents << "/100\n\n";


		}
	}

	

	return 0;
}
