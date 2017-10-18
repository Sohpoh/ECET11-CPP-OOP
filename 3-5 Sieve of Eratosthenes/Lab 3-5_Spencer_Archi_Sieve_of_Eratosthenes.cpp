//Spencer Ng
//Team 3

#include<iostream>
#include<vector>
using namespace std;


vector<int> getPrimeList(int n) {
	vector<int> primeList = vector<int>();
	primeList.push_back(2);

	vector<bool> isPrimeList = vector<bool>(1299710, true);

	for (int i = 3; i < isPrimeList.size() && primeList.size() != n; i += 2) {
		if (isPrimeList[i]) {
			primeList.push_back(i);
			for (int j = i * 2; j < isPrimeList.size(); j += i)
				isPrimeList[j] = false;
		}
	}

	return primeList;

}

int main() {


	int input;
	cout << "Enter the number of primes you want to generate (up to 100 thousand): ";
	cin >> input;

	cout << "\nGenerating primes...\n\n";

	vector<int> primeList = getPrimeList(input);

	cout << "The first " << input << " primes are:\n\n";

	for (int i = 0; i < primeList.size(); i++) {
		cout << primeList[i] << endl;
	}

	return 0;
}