/******************************************************************************
  CS2040C AY2017/18 Semester 2
  guess.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

#define MAX 1000

using namespace std;

int main(void) {
	int guess = MAX / 2, count = 1;
	int higherBound = MAX, lowerBound = 1;
	string response;
	
	while (count < 11) {
		if (count > 10)
			break;
		cout << guess << endl;
		//cout << flush;
		fflush(stdout);

		cin >> response;
		// If guess is too high, reduce guess by half
		if (response == "lower") {
			higherBound = guess;
			guess = (lowerBound + higherBound) / 2;
		}
		// If guess is too low, increase guess by half
		else if (response == "higher") {
			lowerBound = guess;
			guess = (lowerBound + higherBound) / 2;
		}
		// Else guess is correct, terminate
		else {
			return 0;
		}

		count++;
	}

	return 0;
}
