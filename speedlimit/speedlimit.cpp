#include <iostream>

using namespace std;

int main(void) {
	int  currSpd, currTime, sets, diffTime;

	while (cin >> sets, sets > 0) {
		int totalDist = 0;
		int prevTime = 0;
		
		while (sets--) {
			cin >> currSpd >> currTime;

			diffTime = currTime - prevTime;
			totalDist += (diffTime * currSpd);
			prevTime = currTime;	
		}

		cout << totalDist << " miles" << endl;
	}	
	return 0;
}