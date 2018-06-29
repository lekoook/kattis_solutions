/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// Typedef
typedef pair<int, bool> nodePair;

// Global variables
unordered_set<int> redNodes;
vector< vector<nodePair> > adjList;
unordered_set<int> endNodes;
vector<bool> visitedNodes;

void findStopNodes(int node, bool isBug);

void printList() {
	cout << "redNodes:" << endl;
	int count = 0;
	for (auto it : redNodes) {
		cout << count << ": " << it+1 << endl;
		count++;
	}

	cout << "adjList:" << endl;
	count = 1;
	for (auto it : adjList) {
		cout << count << ":";
		for (auto it2 : it) {
			cout << " " << it2.first+1;
		}
		cout << endl;
		count++;
	}
}

int main(void) {
	int nodes, edges, node1, node2;
	cin >> nodes >> edges;

	// Initialise all adjacency list and checks
	adjList.assign(nodes, vector<nodePair>(0));
	visitedNodes.assign(nodes, false);

	// Read in the graph
	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2;
		node2 -= 1;
		// It is a red outgoing edge
		if (node1 < 0) {
			node1 *= -1;
			node1 -= 1;
			redNodes.insert(node1);
			adjList[node1].push_back(make_pair(node2, true));
		}
		// It is a black outgoing edge
		else {
			node1 -= 1;
			adjList[node1].push_back(make_pair(node2, false));
		}
	}

	//printList();

	// Execute DFS
	findStopNodes(0, false);
	cout << endNodes.size() << endl;

	/*	
	// Count number of end nodes;
	cout << "end nodes are:" << endl;
	for (auto &it : endNodes) {
		cout << it+1 << endl;
	}
	*/

	return 0;
}

// DFS algo to find all the possible stop nodes
void findStopNodes(int node, bool isBug) {
	// Check if this node has already been visited
	if (visitedNodes[node]) {
		return;
	}
	
	//cout << "visited " << node+1 << endl;
	visitedNodes[node] = true;

	
	// Determine if this node is an end point node
	if (redNodes.count(node) == 0) {
		//cout << "visiting " << node+1 << " and marking it as end node" << endl;
		endNodes.insert(node);
	}
	// This will detect if the starting node 1 has no forced moves at all
	if (node == 0 && redNodes.count(node) == 0) {
		//cout << "visiting " << node+1 << " and marking it as end node" << endl;
		endNodes.insert(node);
	}

	// Go through all the neighbours of this node
	for (int i = 0; i < (int)adjList[node].size(); i++) {
		// Red outgoing edge
		if (adjList[node][i].second) {
			findStopNodes(adjList[node][i].first, isBug);
		}
		// Black outgoing edge
		else if (!isBug && !adjList[node][i].second) {
			findStopNodes(adjList[node][i].first, true);
		}
	}
}
