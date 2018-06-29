/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool compareWord(pair<string, int> &lhs, pair<string, int> &rhs) {
	if (lhs.second > rhs.second)
		return true;
	else if (lhs.second == rhs.second) {
		if (lhs.first < rhs.first) 
			return true;
	}
	else 
		return false;

	return false;
}

int main(void) {
	unordered_map<string, pair<int, unordered_set<string> > > wordMap;
	unordered_set<string> nameSet;
	int num;
	string input, name, word;

	cin >> num; cin.get();
	for (int i = 0; i < num; i++) {
		getline(cin, input);
		istringstream inputStream(input);

		// Get the name
		inputStream >> name;
		nameSet.insert(name);
		
		// Store the subsequent words with its frequency and users
		while (inputStream >> word) {
			get<0>(wordMap[word]) += 1;
			get<1>(wordMap[word]).insert(name);
		}
	}
/*
	for (auto itr : wordMap) {
		cout << itr.first << " - Freq: " << get<0>(itr.second) << " Users: ";
		for (auto names : get<1>(itr.second)) {
			cout << names << " ";
		}
		cout << endl;
	}

	for (auto itr : nameSet) {
		cout << itr << " ";
	}
	cout << endl;
*/

	// Iterate through all words in wordMap and place them in vector
	// to be sorted later
	vector< pair<string, int> > output; 
	for (auto word : wordMap) {
		if ((int)get<1>(word.second).size() == (int)nameSet.size()) {
			output.push_back(make_pair(word.first, get<0>(word.second)));
		}
	}
	
	if ((int)output.size() == 0) {
		cout << "ALL CLEAR" << endl;
		return 0;
	}
	
	// Sort the wordMap according to the frequency and lexicographical order
	sort(output.begin(), output.end(), compareWord);
	
	// Print output
	for (auto item : output) {
		cout << item.first << endl;
	}
	
/*	
	for (auto itr : nameSet) {
		cout << itr << " ";
	}
	cout << endl;
*/
	return 0;
}
