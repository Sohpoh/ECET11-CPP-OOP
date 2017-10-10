/* Palindrome Quiz
 * C++ Algorithmic Quiz #1
 *
 * The input will consist of an integer K, followed by K integers, called N.
 * The value of N is between 1 and 1000 (inclusive). Afterwards:
 *
 * a. If N is a palindrome, stop.
 * b. Set N = N + reverse(n)
 * c. If step a was repeated over 50 times, stop.
 * d. Go to step a
 *
 * If the final value of N is a palindrome, print the initial value of N 
 * followed by a whitespace and the final value of N. If it is not a palindrome
 * (iterated over 50 times), print the initial value of N followed by a whitespace
 * and "ITERATION NUMBER EXCEEDED". There should be K lines of output in your program.
 *
 * Reverse(N) is defined as N with its digits in reverse order, excluding leading zeroes.
 * For example, Reverse(123) = 321, Reverse(606) = 606, Reverse(1002) = 2001, Reverse(100) = 1.
 *
 * A number is considered a palindrome if and only if its reversed value is the same as itself.
 *
*/

#include<iostream>
#include<string>
using namespace std;

unsigned long long reverse(unsigned long long n) {
	
	unsigned long long result = 0;
	
	while (n != 0) {
		result *= 10;
		result += n % 10;
		n /= 10;
	}
	return result;
}

bool isPalindrome(unsigned long long n) {
	return reverse(n) == n;
}

int main() {
	int testCases;
	cin >> testCases;

	unsigned long long n;

	for (int i = 0; i < testCases; i++) {
		cin >> n;

		unsigned long long initN = n;

		for (int j = 0; j < 50 && !isPalindrome(n); j++)
			n += reverse(n);

		cout << initN << " " << (isPalindrome(n) ? to_string(n) : "ITERATION NUMBER EXCEEDED") << endl;

	}
}