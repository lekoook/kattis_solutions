/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// Global variables
vector< vector<int> > redAdjList;
vector< vector<int> > blackAdjList;
vector<int> nodesChecklist;
vector<bool> visitedNodes;

void findStopNodes(int node, int totalNodes);

void printList() {
	cout << "redAdjList:" << endl;
	int count = 0;
	for (auto it : redAdjList) {
		cout << count << ":";
		for (auto it2 : it) {
			cout << " " << it2;
		}
		cout << endl;
		count++;
	}

	cout << "blackAdjList:" << endl;
	count = 0;
	for (auto it : blackAdjList) {
		cout << count << ":";
		for (auto it2 : it) {
			cout << " " << it2;
		}
		cout << endl;
		count++;
	}
}

int main(void) {
	int nodes, edges, node1, node2, stopCount = 0;
	cin >> nodes >> edges;
	bool hasRed = false;

	// Initialise all adjacency list and checks
	redAdjList.assign(nodes, vector<int>(0));
	blackAdjList.assign(nodes, vector<int>(0));
	nodesChecklist.assign(nodes, 0);
	visitedNodes.assign(nodes, false);

	// Read in the graph
	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2;
		node2 -= 1;
		// It is a red edge
		if (node1 < 0) {
			hasRed = true;
			node1 *= -1;
			node1 -= 1;
			redAdjList[node1].push_back(node2);
		}
		// It is a black edge
		else {
			node1 -= 1;
			blackAdjList[node1].push_back(node2);
		}
	}

	//printList();

	// Execute BFS on all nodes with red edges (in redAdjList)
	// BFS stops when:
	// 1) Node has no more outgoing edges
	// 2) Node has black outgoing but no red outgoing
	// Whenever there is stoppage, mark the stop node in the checklist
	// BFS continues when:
	// 1) Node has red outgoing but no black outgoing -> go to the single red neighbour
	// 2) Node has black outgoing AND has red outgoing -> go to all black neighbours
	for (int j = 0; j < nodes; j++) {
		if (redAdjList[j].size() > 0) {
			findStopNodes(j, nodes);
		}
	}
	if (!hasRed) {
		stopCount = (int)blackAdjList[0].size() + 1;
	}

	// Check for all the stop nodes and add them to count
	for (int j = 0; j < (int)nodesChecklist.size(); j++) {
		if (nodesChecklist[j] > 0) {
			stopCount++;
		}
	}

	cout << stopCount << endl;

	return 0;
}

// BFS algo to find all the possible stop nodes
void findStopNodes(int node, int totalNodes) {
	bool hasBug = false;

	// PQ to BFS all nodes
	queue<int> que;
	que.push(node);

	// Reset the visitedNodes vector
	visitedNodes.assign(totalNodes, false);

	// Keep going until PQ is empty
	while (!que.empty()) {
		int currentNode = que.front();
		// Set the visit state
		visitedNodes[currentNode] = true;
		// Check for the respective conditions to GO or STOP
		// If this node has red outgoing but no black outgoing, we go RED neighbour
		if (redAdjList[currentNode].size() > 0 && blackAdjList[currentNode].size() == 0) {
			if (!visitedNodes[redAdjList[currentNode][0]]) {
				que.push(redAdjList[currentNode][0]);
			}
		}
		// If this node has red outgoing AND black outgoing, we go ALL BLACK AND ALL RED neighbours
		else if (redAdjList[currentNode].size() > 0 && blackAdjList[currentNode].size() > 0) {
			for (int i = 0; i < (int)blackAdjList[currentNode].size(); i++) {
				if (!visitedNodes[blackAdjList[currentNode][i]]) {
					que.push(blackAdjList[currentNode][i]);
				}
			}
			for (int i = 0; i < (int)redAdjList[currentNode].size(); i++) {
				if (!visitedNodes[redAdjList[currentNode][i]]) {
					que.push(redAdjList[currentNode][i]);
				}
			}
		}
		/*
		// If this node has black outgoing but no red outgoing, we go ALL BLACK neighbours
		else if (redAdjList[currentNode].size() == 0 && blackAdjList[currentNode].size() > 0) {
			for (int i = 0; i < (int)blackAdjList[currentNode].size(); i++) {
				if (!visitedNodes[blackAdjList[currentNode][i]]) {
					que.push(blackAdjList[currentNode][i]);
				}
			}
		}
		*/
		// Everything else, we stop this node and mark it
		else {
			nodesChecklist[currentNode] = 1;
		}

		// Throw away the current node
		que.pop();
	}
}
