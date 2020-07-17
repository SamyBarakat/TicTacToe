
// ***********
// Author: Samy Barakat
// Assignment: 02
// TicTacToe


#include <iostream>

using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

bool isWon(char particpant, char board[][3]) {
	bool complete = false;

	for (int i = 0; i < 3; i++) {
		
		// Here, we check the row

		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			complete = true;
		
		// Here, we check the column

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			complete = true;
	}

	// Here, we check diagonal 

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		complete = true;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][1] != ' ')
		complete = true;

	return complete;
}

bool isDraw(char board[][3]) {

	// We count the empty cells

	int count = 0;			

	// Loop

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				count++;
		}
	}

	if (count == 0 && !isWon('X', board) && !isWon('O', board))
		return true;
	else
		return false;
}



void displayBoard(char board[][3]) {
	cout << "-------------" << endl;
	
	// Loop

	for (int i = 0; i < 3; i++) {
		cout << "|";
		for (int j = 0; j < 3; j++) {
			cout << " " << board[i][j] << " |";
		}
		cout << endl << "-------------" << endl;
	}
}

void makeAMove(char board[][3], char particpant) {
	bool viableInput = false;
	int row, column;

	// Loop

	while (!viableInput) {
		cout << "Enter a row(0, 1, 2) for player " << particpant << "   : ";
		cin >> row;              
		cout << "Enter a column(0, 1, 2) for player " << particpant << ": ";
		cin >> column;
		if (board[row][column] != ' ')
			cout << "This cell is already occupied. Try a different cell" << endl;
		else
			viableInput = true;
	}

	board[row][column] = particpant;
}