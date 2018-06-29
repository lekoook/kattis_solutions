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
	string moves;
	int cup = 1;

	cin >> moves;
	for (int i = 0; i < (int)moves.size(); i++) {
		switch(moves[i]) {
			case 'A':
				if (cup == 1) cup = 2;
				else if (cup == 2) cup = 1;
				break;
			case 'B':
				if (cup == 2) cup = 3;
				else if (cup == 3) cup = 2;
				break;
			default:
				if (cup == 3) cup = 1;
				else if (cup == 1) cup = 3;
		}
	}
	cout << cup << endl;
	return 0;
}
