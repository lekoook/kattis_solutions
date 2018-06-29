/******************************************************************************
  CS2040C AY2017/18 __
  __.cpp
  This program __
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

#define MAX 200

using namespace std;

/* Function Prototypes */
void getTreasure(int field[MAX][MAX], int row, int col, int steps);

int main(void) {
	int rows, cols, field[MAX][MAX];
	string line;
	
	cin >> rows >> cols;
	
	getline(cin, line);
	for (int i = 0; i < rows; i++) {
		getline(cin, line);

		for (int j = 0; j < cols; j++) {
			field[i][j] = line[j];
		}
	}
	getTreasure(field, 0, 0, 0);
	
	return 0;
}

void getTreasure(int field[MAX][MAX], int row, int col, int steps) {
	if (field[row][col] == 'T') {
		cout << steps << endl;		
	}
}
