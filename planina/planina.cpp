/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

/* Function Prototypes */

int main(void) {
	int nodes = 4, squares = 1, lineSegments = 4, iterations;

	cin >> iterations;

	for (int stage = 1; stage <= iterations; stage++) {
		nodes += lineSegments + squares;
		// Preparing for next stage
		lineSegments += lineSegments + (squares * 4); 
		squares = pow(4, stage);
	}

	cout << nodes << endl;
	return 0;
}
