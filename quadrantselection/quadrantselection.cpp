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
	int x, y;

	cin >> x >> y;

	if ((x > 0) && (y > 0)) 
		cout << 1 << endl;
	else if ((x < 0) && (y < 0)) 
		cout << 3 << endl;
	else if ((x > 0) && (y < 0))
		cout << 4 << endl;
	else
		cout << 2 << endl;

	return 0;
}


