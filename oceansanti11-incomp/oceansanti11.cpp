#include <iostream>

using namespace std;

void printShift(int given) {
	while (given) {
		cout << given << endl;
		given = given >> 1;
	}
}

int main(void) {
	int cases, value;

	cin >> cases;

	while (cases--) {
		cin >> value;

		for (int i = 2; i <= value; i++) {
			printShift(i);
		}
	}
	return 0;
}