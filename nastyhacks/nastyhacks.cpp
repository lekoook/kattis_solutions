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
	int n, revenue, expected, costs;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> revenue >> expected >> costs;

		if ((expected - costs) > revenue)
			cout << "advertise" << endl;
		else if ((expected - costs) == revenue)
			cout << "does not matter" << endl;
		else 
			cout << "do not advertise" << endl;
	}
	return 0;
}
