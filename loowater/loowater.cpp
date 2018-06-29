#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void p(vector<int> &arr) {
	for (auto it : arr)
		cout << it << " ";
	cout << endl;
}

int main(void) {
	int heads, knights, length;
	vector<int> headLength;
	vector<int> knightLength;

	while (cin >> heads >> knights, heads!= 0 && knights != 0) {
		// Reset all data and structures
		int totalWages = 0;
		headLength.assign(0, 0);
		knightLength.assign(0, 0);
		
		// Read in the data
		for (int i = 0; i < heads; i++) {
			cin >> length;
			headLength.push_back(length);
		}
		for (int i = 0; i < knights; i++) {
			cin >> length;
			knightLength.push_back(length);
		}

		// Sort both length arrays
		sort(headLength.begin(), headLength.end());
		sort(knightLength.begin(), knightLength.end());
				
		// Match all the dragon heads length with knights length
		// Starting from shortest dragon head, look for the knight length that is
		// either equal or more than dragon head length. Compute the wage as well
		// The solution is not possible when there are not enough knights to match
		// the dragon heads
		int knightPtr = 0, currentHeadLen;
		bool found = true;
		for (int i = 0; i < heads; i++) {
			currentHeadLen = headLength[i];
			found = false;
			for (int j = knightPtr; j < knights; j++) {
				if (knightLength[j] >= currentHeadLen) {
					knightPtr = j + 1;
					totalWages += knightLength[j];
					found = true;
					break;
				}
			}
			
			if ((knightPtr >= knights && i+1 < heads) || (found == false)) {
				totalWages = -1;
				break;
			}
		}

		if (totalWages >= 0)
			cout << totalWages << endl;
		else
			cout << "Loowater is doomed!" << endl;
	}
	
	return 0;
}