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
	string input;
	vector<string> vect;
	set<string> combSet;

	while (cin >> input) {
		for (auto &it : vect) {
			string val = it + input;
			string val2 = input + it;
			combSet.insert(val);
			combSet.insert(val2);
		}
		vect.push_back(input);
	}

	for (auto &it : combSet) {
		cout << it << endl;
	}
	return 0;
}
