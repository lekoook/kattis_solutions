/******************************************************************************
  CS2040C AY2017/18 Semester 2
  horrorlist.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000000

using namespace std;

vector< vector<int> > adjList;
vector<int> indexes;
vector<int> horrorList;

void mark(int source);

int main(void) {
	int N, H, L;
	int index, node1, node2;
	
	cin >> N >> H >> L;
	
	adjList.assign(N, vector<int>(0));
	indexes.assign(N, INF);
	horrorList.assign(0, 0);
	
	// Read the horror list
	for (int i = 0; i < H; i++) {
		cin >> index;
		horrorList.push_back(index);
		indexes[index] = 0;
	}
	
	// Read in the graph connections
	for (int i = 0; i < L; i++) {
		cin >> node1 >> node2;
		adjList[node1].push_back(node2);
		adjList[node2].push_back(node1);
	}
	
	// Run BFS on all nodes that have 0 Horror Index (horror list)
	for (int i = 0; i < (int)horrorList.size(); i++) {
		mark(horrorList[i]);
	}
	
	// Print output
	int highest = 0;
	int resultIndex = 0;
	for (int i = 0; i < N; i++) {
		if (indexes[i] > highest) {
			highest = indexes[i];
			resultIndex = i;
		}
	}
	cout << resultIndex << endl;
	
	return 0;
}

void mark(int source) {
	queue<int> que;
	que.push(source);
	int current;
	//indexes[source] = 0;
	
	while (!que.empty()) {
		current = que.front();
		que.pop();
		
		// Go through all its neighours
		for (int i = 0; i < (int)adjList[current].size(); i++) {
			// If the neighbour's distance is greater than the current
			// node, we set the neighbour's distance and add to queue
			if (indexes[adjList[current][i]] > indexes[current]) {
				indexes[adjList[current][i]] = indexes[current] + 1;
				que.push(adjList[current][i]);
			}
		}
	}
}
