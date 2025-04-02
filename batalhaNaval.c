#include <stdio.h>

// function prototypes
void setupBoard(int board[10][10]);
void verticalShip(int board[10][10], int startRowIndex, int column);
void horizontalShip(int board[10][10], int startRowIndex, int column);
void diagonalShips(int board[10][10]);
void coneSkill(int board[10][10], int columnCenter, int rowCenter);
void crossSkill(int board[10][10], int columnCenter, int rowCenter);
void octaedronSkill(int board[10][10], int columnCenter, int rowCenter);

void printBoard(int board[10][10]);

int main() {
	int board[10][10];
	printf("\nBatalha Naval!\n");
	// setup the game inserting the column and rows indexes and the battle field
	setupBoard(board);

	// inserting ships on table
	// horizontal ship - first column and row next
	horizontalShip(board, 5, 2);
	// vertical ship - first start row and column
	verticalShip(board, 5, 1);
	diagonalShips(board);

	// call the function to print the board
	printf("\nTabuleiro com os navios posicionados:\n");
	printBoard(board);

	// coordinates from the center of the skill
	coneSkill(board, 6, 3);
	crossSkill(board, 7, 8);
	octaedronSkill(board, 4, 1);

	// print bord again to show the skill impact
	printf("\nTabuleiro após o campo de batalha ser bombardeado:\n");
	printBoard(board);

	return 0;
}

// setup the board to have number in the rows and columns as well as make all board blank
void setupBoard(int board[10][10]) {
	for (int column = 0; column < 10; column++) {
		for (int row = 0; row < 10; row++) {
			board[column][row] = 0;
		};
	}
}

// insert a vertical ship to the board
void verticalShip(int board[10][10], int startColumnIndex, int row) {
	for (int index = 0; index < 4; index++) {
		board[startColumnIndex + index][row] = 3;
	}
}

// insert a horizontal ship to the board
void horizontalShip(int board[10][10], int startRowIndex, int column) {
	for (int index = 0; index < 4; index++) {
		board[column][startRowIndex + index] = 3;
	}
}

// insert 2 diagonal ships to the board
void diagonalShips(int board[10][10]) {
	for (int index = 1; index <= 4; index++) {
		board[index][index] = 3;
	}

	for (int index = 6; index < 10; index++) {
		board[index][12 - index] = 3;
	}
}

void coneSkill(int board[10][10], int columnCenter, int rowCenter) {
	if (columnCenter >= 0 && rowCenter <= 9) {
		for (int index = 0; index <= 2; index++) {
			for (int j = -index; j <= index; j++) {
				// do a check if the bomb area is inside of the board
				if (rowCenter + index < 10 && columnCenter + j >= 0 && columnCenter + j <= 9) {
					board[rowCenter + index][columnCenter + j] = 1;
				}
			}
		}

	} else {
		printf("Centro da habilidade fora dos limites do tabuleiro");
	}
}

void crossSkill(int board[10][10], int columnCenter, int rowCenter) {
	if (columnCenter >= 0 && rowCenter <= 9) {
		for (int index = 0; index <= 2; index++) {
			board[rowCenter - 1 + index][columnCenter] = 1;
		}
		for (int index = 0; index <= 4; index++) {
			board[rowCenter][columnCenter - 2 + index] = 1;
		}
	} else {
		printf("Centro da habilidade fora dos limites do tabuleiro");
	}
};

void octaedronSkill(int board[10][10], int columnCenter, int rowCenter) {
	if (columnCenter >= 0 && rowCenter <= 9) {
		for (int index = 0; index <= 2; index++) {
			board[1 - rowCenter + index][columnCenter] = 1;
			board[rowCenter][columnCenter - 1 + index] = 1;
		}

	} else {
		printf("Centro da habilidade fora dos limites do tabuleiro");
	}
};

// function to print the board
void printBoard(int board[10][10]) {
	printf("\n");

	for (int column = 0; column < 10; column++) {
		if (column != 9) {
			printf("%d  ", column + 1);
		} else {
			printf("%d ", column + 1);
		}

		for (int line = 0; line < 10; line++) {
			printf("%d ", board[column][line]);
		}

		printf("\n");
	}

	printf("-- ");
	for (int index = 0; index < 10; index++) {
		printf("%d ", index + 1);
	}

	printf("\n");
}
