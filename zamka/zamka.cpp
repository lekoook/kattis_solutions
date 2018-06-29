/******************************************************************************
CS2040C AY2017/18 Semester 2
zamka.cpp
This program rescues the bear.
Lee Kok Teng
C04
******************************************************************************/

#include <iostream>

using namespace std;

/* Function Prototypes */
int getDigitSum(int integer);

int main(void) {
	int l, d, x;
	int min, max;

	cin >> l;
	cin >> d;
	cin >> x;

	// Find the minimal integer
	for (int i = l; i <= d; i++) {
		if (getDigitSum(i) == x) {
			min = i;
			break;
		}
	}

	// Find the maximal integer
	for (int i = d; i >= l; i--) {
		if (getDigitSum(i) == x) {
			max = i;
			break;
		}
	}

	cout << min << endl;
	cout << max << endl;

	return 0;
}

int getDigitSum(int integer) {
	int sum = 0;
	
	while (integer > 0) {
		sum += (integer % 10);
		integer /= 10;
	}

	return sum;
}
