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
	int publishNum, impactFactor, citations;
	double impact;

	cin >> publishNum >> impactFactor;

	citations = publishNum * impactFactor;

	do {
		citations -= 1;
		impact = (double) citations / publishNum;
	} while (impact > (impactFactor - 1));
	
	cout << citations + 1 << endl;

	return 0;
}
