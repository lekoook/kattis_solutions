/******************************************************************************
  CS2040C AY2017/18 Semester 2
  bookingaroom.cpp
  This program determines a room available for booking.
  Lee Kok Teng
  C04
 ******************************************************************************/

#include <iostream>
#include <vector>

#define MAX_ROOMS 100

using namespace std;

// Classes
class Hotel {
private:
	vector<bool> booked;
public:
	Hotel() {}
	Hotel(int r) {
		booked.assign(r, false);
	}

	void book(int r) {
		booked[r - 1] = true;
	}

	int getEmptyRoom() {
		for (int i = 0; i < (int)booked.size(); i++) {
			if (!booked[i]) {
				return i+1;
			}
		}
		return -1;
	}
};

/* Function Prototypes */

int main(void) {
	int r, n, roomNum;

	cin >> r >> n;

	Hotel hotel(r);
	
	for (int i = 1; i <= n; i++) {
		cin >> roomNum;
		hotel.book(roomNum);
	}

	if (r <= n) {
		cout << "too late" << endl;
	}
	else {
		cout << hotel.getEmptyRoom() << endl;
	}

	return 0;
}


