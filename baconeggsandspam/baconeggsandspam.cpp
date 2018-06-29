/******************************************************************************
  CS2040C AY2017/18 Semester 2
  baconeggandspam.cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	map<string, vector<string> > foodMap;
	int diners;
	string name, item, input;

	cin >> diners; cin.ignore(10000, '\n');
	while (diners) {
		for (int i = 0; i < diners; i++) {
			getline(cin, input);
			istringstream inputStream(input);

			// Read in all inputs
			inputStream >> name;
			while (inputStream >> item)
				foodMap[item].push_back(name);
		}

		// Sort all diners of each food item
		for (auto &food : foodMap)
			sort(food.second.begin(), food.second.end());

		// Output all diners of each food item
		for (auto &food : foodMap) {
			cout << food.first << " ";
			for (auto &diner : food.second)
				cout << diner << " ";
			cout << endl;
		}

		cout << endl;
		cin >> diners; cin.ignore(10000, '\n');
		foodMap.clear();
	}
	return 0;
}
