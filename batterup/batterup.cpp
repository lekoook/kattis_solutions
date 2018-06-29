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
	int bats, score, validBats;
	double slugPercent = 0;

	cin >> bats;
	validBats = bats;

	for (int i = 0; i < bats; i++) {
		cin >> score;
		if (score == -1) validBats--;
		else slugPercent += (double) score;
	}

	cout << slugPercent / validBats << endl;

	return 0;
}
