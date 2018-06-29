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
	int temp, numTemp, count = 0;

	cin >> numTemp;

	for (int i = 0; i < numTemp; i++) {
		cin >> temp;
		if (temp < 0) count++;
	}

	cout << count << endl;
	return 0;
}


