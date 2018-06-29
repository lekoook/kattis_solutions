/******************************************************************************
  CS2040C AY2017/18 Semester 2
  numbertree.cpp
  This program finds the path
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main(void) {
	int height, maxNum, target = 1;
	string line, path;

	getline(cin, line);
	istringstream stream (line);
	stream >> height;
	stream >> path;

	maxNum = pow(2, (height+1)) - 1;

	for (int i = 0; i < (int)path.size(); i++) {
		if (path[i] == 'L') {
			// Move left
			target *= 2;
		}
		else {
			// Move right
			target = (target * 2) + 1;
		}
	}
	cout << (maxNum - (target - 1)) << endl;

	return 0;
}
