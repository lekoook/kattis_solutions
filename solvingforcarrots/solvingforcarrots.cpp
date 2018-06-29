/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/* Function Prototypes */

int main(void) {
	int contestants, problems;
	string desc;

	cin >> contestants >> problems;

	for (int i = 0; i < contestants; i++) {
		cin >> desc;
	}

	cout << problems << endl;

	return 0;
}


