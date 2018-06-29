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
	cout << 1 << endl;
	for (int i = 1; i <= 100000; i++) {
		cout << "D";
	}
	cout << endl;
	cout << 100000 << endl;
	cout << "[";
	for (int i = 1; i < 100000; i++) {
		cout << i << ",";
	}
	cout << 100000 << "]" << endl;
	return 0;
}


