/******************************************************************************
  CS2040C AY2017/18 Semester 2
  restaurant.cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	
	int N, value;
	string cmd;

	cin >> N;
	while (N > 0) {
		int pile1 = 0;
		int pile2 = 0;

		for (int i = 1; i <= N; i++) {
			cin >> cmd;
			cin >> value;

			if (cmd == "DROP") {
				pile2 += value;
				cout << "DROP 2 " << value << endl;
			}
			else {
				// If less than TAKE, then take from pile2
				if (pile1 < value) {
					if (pile1 == 0) {
						cout << "MOVE 2->1 " << pile2 << endl;
						pile1 = pile2;
						pile2 = 0;

						cout << "TAKE 1 " << value << endl;
						pile1 -= value;
					}
					else {
						cout << "TAKE 1 " << pile1 << endl;
						value -= pile1;
						pile1 = 0;
						
						cout << "MOVE 2->1 " << pile2 << endl;
						pile1 = pile2;
						pile2 = 0;

						cout << "TAKE 1 " << value << endl;
						pile1 -= value;
					}
				}
				// If more than or equal to what is need to TAKE, remove from
				// pile1.
				else {
					pile1 -= value;
					cout << "TAKE 1 " << value << endl;
				}
			}
		}

		cout << endl;

		cin >> N;
	}
	return 0;
}
