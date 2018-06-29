/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

int main(void) {
	cout << "20 60" << endl;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 60; j++) {
			if ((j == 30 && i%2 == 0) || (j == 29 && i%2 == 1))
				cout << 1;
			else
				cout << 9;
		}
		cout << endl;
	}
	cout << "0 0" << endl;
	return 0;
}


