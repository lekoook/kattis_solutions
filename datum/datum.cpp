#include <iostream>

using namespace std;

int main(void) {
	int day, month, dayOfYear = 0;
	string ans;

	cin >> day >> month;

	for (int i = 1; i <= month; i++) {
		switch(i) {
			case 1:	dayOfYear += day; break;
			case 2:	dayOfYear += 31; break;
			case 3: dayOfYear += 28; break;
			case 4:	dayOfYear += 31; break;
			case 5:	dayOfYear += 30; break;
			case 6: dayOfYear += 31; break;
			case 7:	dayOfYear += 30; break;
			case 8:	dayOfYear += 31; break;
			case 9: dayOfYear += 31; break;
			case 10: dayOfYear += 30; break;
			case 11: dayOfYear += 31; break;
			default: dayOfYear += 30;
		}
	}

	switch (dayOfYear % 7) {
		case 0:	ans = "Wednesday"; break;
		case 1: ans = "Thursday"; break;
		case 2: ans = "Friday"; break;
		case 3: ans = "Saturday"; break;
		case 4: ans = "Sunday"; break;
		case 5: ans = "Monday"; break;
		default: ans = "Tuesday";
	}

	cout << ans << endl;
	
	return 0;
}