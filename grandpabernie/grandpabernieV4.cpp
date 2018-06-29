/******************************************************************************
  CS2040C AY2017/18 Semester 2
  grandpabernie.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int requests, year;
	unordered_map<string, vector<int> > vectTable;
	string country;
	
	clock_t start = clock();

	cin >> requests; cin.get();
	// Store the country and year of visit in a table of vectors
	for (int i = 0; i < requests; i++) {
		cin >> country;
		cin >> year; cin.get();
		
		// If the country exists in the table, update its vector
		// Else add in the country to the table
		vectTable[country].push_back(year);
		//sort(vectTable[country].begin(), vectTable[country].end());
	}
	
	for (auto itr = vectTable.begin(); itr != vectTable.end(); itr++) {
		sort(itr->second.begin(), itr->second.end());
	}

	// Requests from the vector table based on the country and k-th visit
	cin >> requests;
	for (int i = 0; i < requests; i++) {
		cin >> country;
		cin >> year; cin.get();

		// Query and retrieve the year given the country string
		cout << vectTable[country][year-1] << endl;
	}
	
	clock_t end = clock();
	cout << "Time ran: " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	return 0;
}

