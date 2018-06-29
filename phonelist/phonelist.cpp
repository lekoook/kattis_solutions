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
	vector<string> numVect;
	int cases, numbers;
	string num;
	bool consist = true;
	
	cin >> cases;
	while (cases--) {
		cin >> numbers; cin.ignore(10000, '\n');
		while (numbers--) {
			getline(cin, num);
			numVect.push_back(num);
		}
		
		sort(numVect.begin(), numVect.end());

		for (int i = 0; i < (int)numVect.size()-1; i++) {
			if ((numVect[i].find(numVect[i+1]) == 0) 
				|| (numVect[i+1].find(numVect[i])) == 0) {
				consist = false;
				break;
			}
		}

		if (consist) cout << "YES" << endl;
		else cout << "NO" << endl;

		consist = true;
		numVect.clear();
	}

	return 0;
}
