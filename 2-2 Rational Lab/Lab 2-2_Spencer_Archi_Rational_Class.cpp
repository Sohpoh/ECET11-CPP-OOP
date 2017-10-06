#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main() {

	string s = "zba";
	vector<char> letters = vector<char>(s.length());
	for (int i = 0; i < s.length(); i++) {
		letters[i] = s[i];
	}
	sort(letters.begin(),letters.end());

	

	for (int i = letters.size()-1; i >=0; i--) {
		cout << letters[i];
	}
	
	system("pause");
}