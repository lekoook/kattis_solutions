/******************************************************************************
  CS2040C AY2017/18 Semester 2
  mjehuric.cpp
  This program sorts a given sequence of numbers
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>

#define SIZE 5

using namespace std;

/* Function Prototypes */

int main(void) {
	int seq[SIZE], tempInt;

	for (int i = 0; i < SIZE; i++) {
		cin >> seq[i];
	}

	for (int i = SIZE-2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (seq[j] > seq[j+1]) {
				// Swap
				tempInt = seq[j];
				seq[j] = seq[j+1];
				seq[j+1] = tempInt;
				
				for (int k = 0; k < SIZE; k++) {
					cout << seq[k] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}


