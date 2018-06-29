/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>
#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2
using namespace std;

unordered_map<string, vector<string> > adjList;
unordered_map<string, int> status;

bool isSafe = false;

void dfs(string source);

int main(void) {
	int flights;
	string city1, city2, searchCity;

	cin >> flights; cin.get();
	for (int i = 0; i < flights; i++) {
		cin >> city1 >> city2;
		adjList[city1].push_back(city2);
	}

	while (cin >> searchCity) {
		isSafe = false;
		//Reset all the states
		for (auto &it : adjList) {
			status[it.first] = UNVISITED;
		}

		dfs(searchCity);
		if (isSafe)
			cout << searchCity << " safe" << endl;
		else
			cout << searchCity << " trapped" << endl;

	}
	/*
	for (auto v : adjList) {
		cout << v.first << " : ";
		for (auto i : v.second.second) {
			cout << i << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}

void dfs(string source) {
	// Set to explored
	status[source] = EXPLORED;
	
	// Explore all its neighbours
	//for (int i = 0; i < (int)adjList[source].size(); i++) {
	for (auto &neighbour : adjList[source]) {
		if (status[neighbour] == UNVISITED)
			dfs(neighbour);
		else if (status[neighbour] == EXPLORED)
			isSafe = true;
	}

	status[source] = VISITED;
}
