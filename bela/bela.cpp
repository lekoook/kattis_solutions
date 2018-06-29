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
	int hands, points = 0;
	char dominant;
	string card;

	cin >> hands >> dominant;

	for (int i = 0; i < hands*4; i++) {
		cin >> card;
		if (card[0] == 'J') {
			if (card[1] == dominant) points += 20;
			else points += 2;
		}
		else if (card[0] == '9') {
			if (card[1] == dominant) points += 14;
		}
		else {
			switch(card[0]) {
				case 'A':
					points += 11;
					break;
				case 'K':
					points += 4;
					break;
				case 'Q':
					points += 3;
					break;
				case 'T':
					points += 10;
					break;
				default: 
					break;
			}
		}
	}

	cout << points << endl;
	return 0;
}
