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
	int persons;
	string name, item;

	while (cin >> persons, persons) {
		cin.ignore(10000, '\n');
		map<string, set<string> > foodMap;
		for (int i = 0; i < persons; i++) {
			string line;
			getline(cin, line);
			istringstream lineStr(line);
			lineStr >> name;

			while (lineStr >> item) {
				foodMap[item].insert(name);
			}
		}

		for (auto &it : foodMap) {
			cout << it.first;
			for (auto &n : it.second) {
				cout << " " << n;
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
