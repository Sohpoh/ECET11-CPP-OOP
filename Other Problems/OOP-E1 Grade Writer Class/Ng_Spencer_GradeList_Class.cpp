//Spencer Ng
//GradeList Class

#include <iostream>
#include<iomanip>
#include<string>
#include<Windows.h>
#include<vector>
#include<algorithm>
using namespace std;

class GradeList {
private:
	int level;
	float grade;
	int gradeList[4][5];
public:
	GradeList();
	void setLevel(int level);
	void setGrade(float grade);
	void displayTable();
};


GradeList::GradeList() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++)
			gradeList[i][j] = 0;
	}
}

void GradeList::setLevel(int level) {
	this->level = level;
	
}

void GradeList::setGrade(float grade) {
	this->grade = grade;
}

void GradeList::displayTable() {
	if (grade >= 89.5)
		gradeList[level - 9][0]++;
	else if (grade >= 79.5)
		gradeList[level - 9][1]++;
	else if (grade >= 69.5)
		gradeList[level - 9][2]++;
	else if (grade >= 64.9)
		gradeList[level - 9][3]++;
	else
		gradeList[level - 9][4]++;
	system("cls");
	cout << "Academy Grade Distribution" << endl << endl;
	cout << setw(12) << "A" << setw(4) << "B" << setw(4) << "C" << setw(4) << "D" << setw(4) << "F" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "GRADE" << setw(3) << i + 9 << ":";
		for (int j = 0; j < 5; j++) {
			cout << setw(3) << gradeList[i][j] << "|";
		}
		cout << endl;
	}
	cout << endl;
}


int main() {

	GradeList grades1;
	char entry = 'w';
	while (entry != 'q') {
		int grade;
		int level;
		cout << "Enter grade level: ";
		cin >> level;
		grades1.setLevel(level);
		cout << "Enter grade: ";
		cin >> grade;
		grades1.setGrade(grade);
		grades1.displayTable();

		cout << "Continue[q to quit]? ";
		cin >> entry;
	}

	return 0;
}