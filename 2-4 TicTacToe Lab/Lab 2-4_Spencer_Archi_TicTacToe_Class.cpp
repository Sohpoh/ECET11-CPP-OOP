/*
Archi Parekh
Team 3
Lab 2, Program 4
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

class TicTacToe {
private:
	char x;
	char o;
	bool player;
	char board[3][3];

public:
	TicTacToe();
	bool search();
	bool place(int, int);
	bool playerSel();
	void display();
	void whoWon();

};

TicTacToe::TicTacToe() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = { '_' };
	x = 'x';
	o = 'o';
	player = false;
}

bool TicTacToe::playerSel() {
	player = !player;
	return player;
}

bool TicTacToe::place(int r, int c) {

	if (r > 0 && r < 4 && c > 0 && c < 4) {
		if (board[r - 1][c - 1] != '_') {
			cout << "INVALID ENTRY\n";
			return false;
		}
		else if (playerSel()) {
			board[r - 1][c - 1] = 'o';
		}
		else
			board[r - 1][c - 1] = 'x';
		return true;
	}

	else
		cout << "INVALID ENTRY\n";
	return false;


}

bool TicTacToe::search() {
	bool found;

	if (board[0][0] == x && board[0][1] == x && board[0][2] == x)
		found = true;
	else if (board[1][0] == x && board[1][1] == x && board[1][2] == x)
		found = true;
	else if (board[2][0] == x && board[2][1] == x && board[2][2] == x)
		found = true;
	else if (board[0][0] == o && board[0][1] == o && board[0][2] == o)
		found = true;
	else if (board[1][0] == o && board[1][1] == o && board[1][2] == o)
		found = true;
	else if (board[2][0] == o && board[2][1] == o && board[2][2] == o)			//Above: Horizontals, both
		found = true;
	else if (board[0][0] == x && board[1][0] == x && board[2][0] == x)
		found = true;
	else if (board[0][1] == x && board[1][1] == x && board[2][1] == x)
		found = true;
	else if (board[0][2] == x && board[1][2] == x && board[2][2] == x)			//Columns X
		found = true;
	else if (board[0][0] == o && board[1][0] == o && board[2][0] == o)
		found = true;
	else if (board[0][1] == o && board[1][1] == o && board[0][1] == o)
		found = true;
	else if (board[0][2] == o && board[1][2] == o && board[2][2] == o)			//Columns O
		found = true;
	else if (board[0][0] == x && board[1][1] == x && board[2][2] == x)
		found = true;
	else if (board[0][0] == o && board[1][1] == o && board[2][2] == o)
		found = true;
	else if (board[0][2] == o && board[1][1] == o && board[2][0] == o)
		found = true;
	else if (board[0][2] == x && board[1][1] == x && board[2][0] == x)			//Diagonals
		found = true;
	else
		found = false;

	return found;
}


void TicTacToe::whoWon() {
	bool f = search();

	char w;

	if (f) {
		if (playerSel())
			w = 'X';
		else
			w = 'O';

		cout << "\nPlayer " << w << " WON!\n";
	}
	else
		cout << "\nDRAW! \n";




}

void TicTacToe::display() {

	cout << "\n\t\t  1 2 3 ";


	for (int i = 0; i < 3; i++) {
		cout << "\n\t\t" << i + 1 << " ";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
	}
}


int main() {
	TicTacToe t;
	int row, column;
	int q = 0;
	bool w;
	int count = 0;
	char again = 'y';

	cout << "Welcome to Tic Tac Toe!" << endl;
	cout << "Player O goes first." << endl;
	cout << "Enter row followed by column to place character." << endl;
	cout << "ENJOY!" << endl;
	t.display();

	while (!q && count != 9) {

		do {
			cout << "\nEnter row and column: ";
			cin >> row >> column;
			w = t.place(row, column);
		} while (!w);

		Sleep(100);
		system("cls");
		t.display();

		if (t.search())
			q = 1;
		else
			q = 0;

		count++;
	}

	t.whoWon();

	return 0;


}
