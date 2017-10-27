//Spencer Ng
//C++ Quiz

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <Windows.h>
#include<stdlib.h>
using namespace std;

int main() {

	int testCases;
	cin >> testCases;
	for (int i = 0; i < testCases / 3; i++) {

		vector<int> setIntersection = vector<int>(100, 0);

		for (int j = 0; j < 3; j++) {
			vector<bool> containsInt = vector<bool>(100, false);
			int setSize;
			cin >> setSize;

			for (int k = 0; k < setSize; k++) {
				int num;
				cin >> num;
				containsInt[num] = true;
			}

			for (int k = 0; k < containsInt.size(); k++)
				if (containsInt[k])
					setIntersection[k]++;
		}

		vector<int> setIntersectionAct = vector<int>();

		for (int j = 0; j < setIntersection.size(); j++)
			if (setIntersection[j] == 3)
				setIntersectionAct.push_back(j);

		if (!setIntersectionAct.empty()) {
			for (int j = 0; j < setIntersectionAct.size() - 1; j++)
				cout << setIntersectionAct[j] << " ";

			cout << setIntersectionAct[setIntersectionAct.size() - 1];
		}

		cout << endl;
	}

	return 0;
}