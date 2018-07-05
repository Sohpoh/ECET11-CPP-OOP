//Spencer Ng, Rameen Farooq, Adrian Wiley
//Turkey Pizza Quiz

#include <iostream>
#include<string>
#include<map>
#include<array>
#include<cmath>
#include<vector>
#include<algorithm>
#include <Windows.h>
#include<stdlib.h>
using namespace std;

bool isRightAllTrue(const vector<bool>& vec, int index) {
	for (index++; index < vec.size(); index++)
		if (vec[index] == false)
			return false;
	return true;

}

int main() {

	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		int distance, value;
		vector<int> ticketValues;
		vector<bool> isSelected(10, false);
		cin >> distance;
		bool isTurkey = false;

		for (int j = 0; j < 10; j++) {
			cin >> value;
			ticketValues.push_back(value);
		}


		for (int j = 0; j < pow(2, 10) - 1; j++) {
			for (int k = 0; k < 10; k++) {
				if (isRightAllTrue(isSelected, k) || k == 9)
					isSelected[k] = !isSelected[k];
			}
			int sum1 = 0, sum2 = 0;
			for (int k = 0; k < 10; k++) {
				if (isSelected[k])
					sum1 += ticketValues[k];
				else sum2 += ticketValues[k];
			}
			if (abs(sum1 - sum2) == distance) {
				isTurkey = true;
				break;
			}

		}

		if (isTurkey)
			cout << "Turkey";
		else cout << "Pizza";
		cout << endl;

	}

	return 0;
}