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
	int rows, cols, value;
	
	cin >> rows >> cols;
	cin >> value;
	cout << rows << " " << cols << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << value;
		}
		cout << endl;
	}

	return 0;
}
