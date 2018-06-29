/******************************************************************************
  CS2040C AY2017/18 Semester 2
  alistgame.cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int main(void) {
	//int x, testValue = 2, primeCount = 0;
	int number, x_fixed = 2, cycle_size = 2, x = 2, factor = 1;

	cin >> number;
	while (factor == 1) {
		for (int count = 1;count <= cycle_size && factor <= 1;count++) {
			x = (x * x + 1) % number;
			factor = gcd(x - x_fixed, number);
		}

		cycle_size *= 2;
		x_fixed = x;
	}

	cout << factor << endl;

	/*
	   cin >> x;

	   while (x > 1) {
	   cout << "testing " << testValue << endl;
	   if (x % testValue == 0) {
	   x /= testValue;
	   primeCount++;
	   }
	   else {
	   if (testValue == 2)
	   testValue++;
	   else
	   testValue += 2;
	   }
	   }

	   cout << primeCount << endl;
	 */
	return 0;
}
