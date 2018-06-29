/******************************************************************************
  CS2040C AY2017/18 Semester 2
  phonelist.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	unordered_set<string> numSet;
	int cases, numbers;
	string num;
	bool consist = true;
	
	// O(C * N^2), where C is the number of characters in each number
	cin >> cases;
	while (cases--) {
		cin >> numbers; cin.ignore(10000, '\n');
		while (numbers--) {
			getline(cin, num);
			for (int i = 1; i <= (int)num.size(); i++) {
				if (numSet.count(num.substr(0, i))) {
					consist = false;
					break;
				}
			}
			if (!consist) break;
			numSet.insert(num);
		}

		if (!consist) cout << "NO" << endl;
		else cout << "YES" << endl;

		consist = true;
		numSet.clear();
	}

	return 0;
}
