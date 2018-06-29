/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

/* Function Prototypes */

int main(void) {
	int piece, chessNum[6] = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++) {
		cin >> piece;
		cout << chessNum[i] - piece << " ";
	}
	cout << endl;
	return 0;
}
