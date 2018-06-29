/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int cases, guests, key, caseNo = 1, ans;
	unordered_map<int, int> gMap;

	cin >> cases;
	while (cases--) {
		cin >> guests;
		for (int i = 0; i < guests; i++) {
			cin >> key;
			gMap[key]++;
		}

		for (auto gas : gMap) {
			if (gas.second == 1) {
				ans = gas.first;
				break;
			}
		}

		cout << "Case #" << caseNo++ << ": " << ans << endl;
		gMap.clear();
	}
	return 0;
}
