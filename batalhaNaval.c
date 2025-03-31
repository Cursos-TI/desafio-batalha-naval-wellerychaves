#include <stdio.h>

// function prototypes
void setupBoard(int board[10][10]);
void verticalShip(int board[10][10], int startRowIndex, int column);
void horizontalShip(int board[10][10], int startRowIndex, int column);
void diagonalShips(int board[10][10]);
void printBoard(int board[10][10]);

int main() {
	int board[10][10];

	// setup the game inserting the column and rows indexes and the battle field
	setupBoard(board);

	// inserting ships on table
	// horizontal ship - first column and row next
	horizontalShip(board, 5, 2);
	// vertical ship - first start row and column
	verticalShip(board, 5, 1);
	diagonalShips(board);

	// call the function to print the board
	printBoard(board);

	return 0;
}

void setupBoard(int board[10][10]) {
	for (int column = 0; column < 10; column++) {
		for (int line = 0; line < 10; line++) {
			board[column][line] = 0;
		};
	}
}

void verticalShip(int board[10][10], int startRowIndex, int column) {
	for (int index = 0; index < 4; index++) {
		board[startRowIndex + index][column] = 3;
	}
}

void horizontalShip(int board[10][10], int startRowIndex, int column) {
	for (int index = 0; index < 4; index++) {
		board[column][startRowIndex + index] = 3;
	}
}

void diagonalShips(int board[10][10]) {
	for (int index = 1; index <= 4; index++) {
		board[index][index] = 3;
	}

	for (int index = 6; index < 10; index++) {
		board[index][12 - index] = 3;
	}
}

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
		};
		printf("\n");
	}

	printf("-- ");
	for (int index = 0; index < 10; index++) {
		printf("%d ", index + 1);
	}

	printf("\n");
}

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no
// tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas
// atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1

// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0
