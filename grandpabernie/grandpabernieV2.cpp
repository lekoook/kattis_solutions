/******************************************************************************
  CS2040C AY2017/18 Semester 2
  grandpabernie.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void updateVect(vector<int> &vect, int year);
int query(vector<int> &vect, int k);

int main(void) {
	int requests, year;
	unordered_map<string, vector<int> * > vectTable;
	string country;

	clock_t start = clock();

	cin >> requests; cin.get();
	// Store the country and year of visit in a table of vectors
	for (int i = 0; i < requests; i++) {
		cin >> country;
		cin >> year; cin.get();
		
		// If the country exists in the table, update its vector
		// Else add in the country to the table
		if (vectTable.count(country)) {
			vectTable[country]->push_back(year);
		}
		else {
			vector<int> *cVect = new vector<int>;
			cVect->push_back(year);
			vectTable.insert(make_pair(country, cVect));
		}
	}

	for (auto itr = vectTable.begin(); itr != vectTable.end(); itr++) {
		sort(itr->second->begin(), itr->second->end());
	}

	// Requests from the vector table based on the country and k-th visit
	cin >> requests;
	for (int i = 0; i < requests; i++) {
		cin >> country;
		cin >> year; cin.get();

		// Query and retrieve the year given the country string
		cout << query(*(vectTable.at(country)), year) << endl;
	}
	
	clock_t end = clock();
//	cout << "Time ran: " << (double)(end-start)/CLOCKS_PER_SEC << endl;

	return 0;
}

void updateVect(vector<int> &vect, int year) {
	// Insert the year value into the proper place
	auto itr = vect.begin();
	for (int i = 0; i < (int)vect.size(); i++) {
		if (vect[i] < year) {
			advance(itr, 1);
			continue;
		}
		else {
			vect.insert(itr, year);
			break;
		}
	}
	
	// If the year is to be the last element
	if (itr == vect.end()) {
		vect.push_back(year);
	}
}

int query(vector<int> &vect, int k) {
	return vect[k-1];
}
