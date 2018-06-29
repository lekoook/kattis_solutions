/******************************************************************************
  CS2040C AY2017/18 Semester 2
  everywhere.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	unordered_set<string> citySet;
	int cases, cities;
	string city;

	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> cities;
		for (int j = 0; j < cities; j++) {
			cin >> city;
			citySet.insert(city);
		}

		cout << citySet.size() << endl;
		citySet.clear();
	}

	return 0;
}
