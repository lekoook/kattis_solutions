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
	int value, num, power, totalSum = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> value;
		power = value % 10;
		value /= 10;

		totalSum += std::pow(value, power);
	}

	cout << totalSum << endl;

	return 0;
}
