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

	int sequenceLength;
	cin >> sequenceLength;
	vector<int> sequence = vector<int>();
	for (int i = 0; i < sequenceLength; i++) {
		int num; 
		cin >> num;
		sequence.push_back(num);
	}
	sort(sequence.begin(), sequence.end());
	int k = sequence[0];


	for (int i = 0; sequence[i] == k && i < sequenceLength; i++)
		k++;
	

	cout << k << endl;

	return 0;
}