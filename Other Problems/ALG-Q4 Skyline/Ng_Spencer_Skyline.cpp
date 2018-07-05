//Spencer Ng, Rameen Farooq, Adrian Wiley
//C++ Quiz

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

int main() {

	vector<int> skylineHeight(1001, 0);

	int numBuildings;
	cin >> numBuildings;
	for (int i = 0; i < numBuildings; i++) {
		int leftCoord, rightCoord, height;
		cin >> leftCoord >> rightCoord >> height;
		for (int j = leftCoord; j < rightCoord; j++)
			skylineHeight[j] = max(skylineHeight[j], height);
	}
	int lastHeight = 0;
	for (int i = 0; i < 1001; i++) {
		if (skylineHeight[i] != lastHeight) {
			cout << i << " " << skylineHeight[i] << endl;
			lastHeight = skylineHeight[i];
		}
	}

	return 0;
}