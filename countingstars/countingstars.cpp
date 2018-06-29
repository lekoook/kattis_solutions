/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int rows, cols;

void flood(char level[MAX][MAX], int x, int y);

int main(void) {
	char level[MAX][MAX] = {{'#'}};
	int cases = 1;

	while (cin >> rows >> cols) {
		int count = 0;
		cin.ignore(10000, '\n');
		//cout << "rows: " << rows << " cols: " << cols << endl;
		for (int i = 0; i < rows; i++) {
			string input;
			getline(cin, input);
			for (int j = 0; j < cols; j++) {
				level[i][j] = input[j];
			}
		}
/*
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << level[i][j];
			}
			cout << endl;
		}
*/
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (level[i][j] == '-') {
					level[i][j] = '#';
					flood(level, j+1, i);
					flood(level, j-1, i);
					flood(level, j, i+1);
					flood(level, j, i-1);

					count++;
				}
			}
		}

		cout << "Case " << cases++ << ": " << count << endl;
/*
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << level[i][j];
			}
			cout << endl;
		}
		*/
	}

	return 0;
}

void flood(char level[MAX][MAX], int x, int y) {
	if ((x < 0) || (x >= cols) || (y < 0) || (y >= rows) || (level[y][x] == '#'))
		return;

	if (level[y][x] == '-')
		level[y][x] = '#';

	//cout << "flood called on x:" << x << " y:" << y << endl;
	flood(level, x+1, y);
	flood(level, x-1, y);
	flood(level, x, y+1);
	flood(level, x, y-1);
}
