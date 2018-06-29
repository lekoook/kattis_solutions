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

unordered_map<string, pair<int, vector<string> > > adjList;

bool isSafe = false;

void dfs(string source, int parentState);

int main(void) {
	int flights;
	string city1, city2, searchCity;

	cin >> flights; getchar();
	for (int i = 0; i < flights; i++) {
		cin >> city1 >> city2;
		/*
		if (adjList.find(city1) == adjList.end()) {
			adjList[city1] = make_pair(UNVISITED, vector<string>());
		}
		*/
		(adjList[city1].second).push_back(city2);
		/*
		if (adjList.find(city2) == adjList.end()) {
			adjList[city2] = make_pair(UNVISITED, vector<string>());
		}
		*/
	}

	while (cin >> searchCity) {
		isSafe = false;
		//Reset all the states
		for (auto &it : adjList) {
			it.second.first = UNVISITED;
		}

		dfs(searchCity, UNVISITED);
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

void dfs(string source, int parentState) {
	// Set to explored
	adjList[source].first = EXPLORED;

	/*
	// Base cases
	if (adjList[source].first == VISITED)
		return;
	else if (adjList[source].first == EXPLORED) {
		if (parentState == EXPLORED) {
			isSafe = true;
			return;
		}
	}
	else {
	}
	*/
	
	// Explore all its neighbours
	for (int i = 0; i < (int)adjList[source].second.size(); i++) {
		if (adjList[adjList[source].second[i]].first == UNVISITED)
			dfs(adjList[source].second[i], adjList[source].first);
		else if (adjList[adjList[source].second[i]].first == EXPLORED)
			isSafe = true;
	}

	adjList[source].first = VISITED;
}
