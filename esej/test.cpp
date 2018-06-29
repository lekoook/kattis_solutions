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
	unordered_set<string> wordSet;
	string word;
	while (cin >> word) {
		if (wordSet.count(word)) {
			cout << "duplicate" << endl;
			break;
		}
	}

	return 0;
}
