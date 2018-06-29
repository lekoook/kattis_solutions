/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITED 1

using namespace std;

typedef struct {
	int data = -1;
	int state = UNVISITED;
} vert_t;

vector< pair<int, vector<int> > > adjList;

void dfs(int source);

int main(void) {
	int cities, endpoints, pairs;
	
	cin >> cities;
	for (int i = 0; i < cities; i++) {
		cin >> endpoints;
		cin >> pairs;
		int cc = 0;
		
		// Build the adjacency list
		int left, right;
		adjList.assign(endpoints, pair<int, vector<int> >());
		for (int j = 0; j < pairs; j++) {
			cin >> left >> right;
			(adjList[left].second).push_back(right);
			(adjList[right].second).push_back(left);
		}
		
		// DFS to find the number of connected components
		for (int j = 0; j < endpoints; j++) {
			if (adjList[j].first == UNVISITED) {
				cc++;
				dfs(j);
			}
		}
		cout << cc-1 << endl;

	}
	return 0;
}

void dfs(int source) {
	// Base condition (is vertex is visited)
	if (adjList[source].first == VISITED) {
		return;
	}
	else {
		adjList[source].first = VISITED;
	}
	for (int neighbours = 0; neighbours < (int)adjList[source].second.size(); neighbours++) {
		dfs(adjList[source].second[neighbours]);
	}
}
