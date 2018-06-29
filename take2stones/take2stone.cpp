/******************************************************************************
  CS2040C AY2017/18 Semester 2
  take2stone.cpp
  This program determines if Alice of Bob wins.
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

/* Function Prototypes */

int main(void) {
	int stones, remainder;

	cin >> stones;
	remainder = stones % 2;

	if (remainder) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Bob" << endl;
	}

	return 0;
}


