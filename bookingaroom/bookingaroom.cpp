/******************************************************************************
  CS2040C AY2017/18 Semester 2
  bookingaroom.cpp
  This program determines a room available for booking.
  Lee Kok Teng
  C04
 ******************************************************************************/

#include <iostream>

#define MAX_ROOMS 100

using namespace std;

/* Function Prototypes */

int main(void) {
	int r, n, roomNum;
	int rooms[MAX_ROOMS] = { 0 };

	cin >> r >> n;

	for (int i = 1; i <= n; i++) {
		cin >> roomNum;
		rooms[roomNum-1] = 1;
	}

	if (r == n) {
		cout << "too late" << endl;
	}
	else {
		for (int i = 0; i <= r; i++) {
			if (rooms[i] == 0) {
				cout << i+1 << endl;
				break;
			}
		}
	}

	return 0;
}


