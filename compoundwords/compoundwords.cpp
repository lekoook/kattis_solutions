/******************************************************************************
  CS2040C AY2017/18 Semester 2
  compoundwords.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	set<string> wordsMap;
	vector<string> wordVect;
	string word;

	while (cin >> word) {
		for (auto itr = wordVect.begin(); itr != wordVect.end(); itr++) {
			wordsMap.insert((*itr) + word);
			wordsMap.insert(word+ (*itr));
		}
		wordVect.push_back(word);
	}

	for (auto &item : wordsMap)
		cout << item << endl;

	
	return 0;
}
