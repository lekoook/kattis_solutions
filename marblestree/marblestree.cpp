#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int calculate(vector< vector<int> > &adjList, 
	vector<int> &degreeList, vector<int> &countList);

int main(void) {
	int vertices, vertexNum, marbles, children, childNum;
	vector< vector<int> > adjList;
	vector<int> degreeList;
	vector<int> countList;
	
	while (cin >> vertices, vertices > 0) {
		// Reset all data structures
		adjList.assign(vertices, vector<int>(0));
		degreeList.assign(vertices, 0);
		countList.assign(vertices, 0);
		
		// Read in input
		for (int i = 0; i < vertices; i++) {
			cin >> vertexNum; vertexNum -= 1;
			cin >> marbles;
			cin >> children;

			// Update the data structures with input
			countList[vertexNum] = marbles;
			degreeList[vertexNum] = children;
			for (int j = 0; j < children; j++) {
				cin >> childNum; childNum -= 1;
				adjList[childNum].push_back(vertexNum);
			}
		}

		// Calculate the minimum moves
		int moves = calculate(adjList, degreeList, countList);
		cout << moves << endl;
	}
	
	return 0;
}

// This function first looks through all the vertices that has ZERO degree.
// Degree of a vertex refers to the number of incoming direction of that vertex
// or the 'children' of that vertex.
// By starting from ZERO degree vertices, we are effectively starting from the
// vertices that has no incoming direction which are the leaf vertices of the 
// tree in this problem.
// We then distribute the marbles from these leaves upwards, towards the root,
// depth level by depth level.
int calculate(vector< vector<int> > &adjList, 
	vector<int> &degreeList, vector<int> &countList) {
	int totalMoves = 0, currentVtx;
	
	// Get a tally of all vertices with ZERO degree and add to a queue
	queue<int> zeroQ;
	for (int i = 0; i < (int)degreeList.size(); i++) {
		if (degreeList[i] == 0)
			zeroQ.push(i);
	}

	// Run through the zero degree queue to process all those vertices
	while (!zeroQ.empty()) {
		currentVtx = zeroQ.front();
		zeroQ.pop();
		
		if (adjList[currentVtx].size() > 0) { // Root vertex has no outgoing
			// Distribute the marbles in this current vertex
			// First get the parent vertex of current vertex
			int parent = adjList[currentVtx][0];
			// This computes the difference between the current vertex marbles and one
			// If the current marbles is 1, parent's marbles has no change, hence no
			// moves added
			// If the current marbles is >1, parent's marbles will increase by the
			// difference. Hence, all but ONE marble is moved to the parent vertex
			// If the current marbles is <1, parent's will decrease by the negative
			// difference. This negative difference means that the parents 'owe' the
			// current vertex by the amount of marbles. Which can be 'paid back' by
			// it's subsequent children.
			int difference = countList[currentVtx] - 1;
			countList[parent] += difference;
			degreeList[parent]--;
			if (degreeList[parent] == 0)
				zeroQ.push(parent);
	
			// Update the total moves using the difference
			totalMoves += abs(difference);
		}
		
	}
	
	return totalMoves;		
}