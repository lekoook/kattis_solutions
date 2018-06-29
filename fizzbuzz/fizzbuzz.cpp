/******************************************************************************
  CS2040C AY2017/18 Semester 2
  fizzbuzz.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

int main(void) {
	int X, Y, N;
	
	cin >> X >> Y >> N;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0)
			cout << "Fizz";
		if (i % Y == 0)
			cout << "Buzz";
		if (i % X != 0 && i % Y != 0)
			cout << i;

		cout << endl;
	}
	return 0;
}


