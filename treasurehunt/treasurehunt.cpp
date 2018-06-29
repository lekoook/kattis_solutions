/******************************************************************************
CS2040C AY2017/18 __
treasurehunt.cpp
This program returns the number of steps required to find the treasure.
Lee Kok Teng
C04
******************************************************************************/

#include <bits/stdc++.h>

#define MAX_ROWS 200
#define MAX_COLS 200
#define OUT -1
#define LOST -2

using namespace std;

/* Function Prototypes */
int getTreasure(char playingField[MAX_ROWS][MAX_COLS], int rows, int cols);

int main(void) {
	//freopen("D.17.in", "r", stdin);

	int rows, cols, steps;
	char playingField[MAX_ROWS][MAX_COLS] = { { '0' } };
	string line;

	cin >> rows >> cols;
	if ((rows <= 0) || (rows > 200) || (cols <= 0) || (cols > 200))
		return 1;
	
	for (int row = 0; row < rows; row++) {
		cin >> line;
		for (int col = 0; col < cols; col++) {
			playingField[row][col] = line[col];
		}
	}

	steps = getTreasure(playingField, rows, cols);
	if (steps == LOST) cout << "Lost" << endl;
	else if (steps == OUT) cout << "Out" << endl;
	else cout << steps << endl;

	return 0;
}

int getTreasure(char playingField[MAX_ROWS][MAX_COLS], int rows, int cols) {
	int row = 0, col = 0;
	int steps = 0;
	int fieldFlags[MAX_ROWS][MAX_COLS] = { { 0 } };

	while (true) {
		fieldFlags[row][col] = 1;
		if (playingField[row][col] == 'N') {
			row--;
			steps++;
		}
		else if (playingField[row][col] == 'S') {
			row++;
			steps++;
		}
		else if (playingField[row][col] == 'W') {
			col--;
			steps++;
		}
		else if (playingField[row][col] == 'E') {
			col++;
			steps++;
		}
		
		if ((row < 0) || (row >= rows) || (col < 0) || (col >= cols)) {
			return OUT;
		}
		else if (playingField[row][col] == 'T') {
			return steps;
		}
		else if (fieldFlags[row][col] == 1) {
			return LOST;
		}
	}
}
