/******************************************************************************
  CS2040C AY2017/18 Semester 2
  visualgo.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>

#define INF 1000000000

using namespace std;

typedef pair<int, int> nodePair;

vector< vector<nodePair> > adjList;
vector< vector<nodePair> > predGraph;
vector<int> distVect;
vector<int> currentPath;
vector< vector<int> > allPaths;

void explore(int source, int end);
void computeShortest(int source, int end, int &count);

int main(void) {
	int nodes, edges, start, end;
	int node1, node2, weight;
	
	cin >> nodes >> edges;
	
	// Reset
	adjList.assign(nodes, vector<nodePair>(0));
	predGraph.assign(nodes, vector<nodePair>(0));
	distVect.assign(nodes, INF);
	currentPath.assign(0, 0);
	allPaths.assign(0, vector<int>(0));
	
	// Read in the graph
	for (int i = 0; i < edges; i++) {
		cin >> node1 >> node2 >> weight;
		adjList[node1].push_back(make_pair(weight, node2));
	}
	
	// Read in start and end
	cin >> start >> end;

	// Run Dijkstra from start to end
	// Form a subgraph of possible shortest routes in the process
	explore(start, end);

	// Now we have a subgraph of the original that contains all possible
	// shortest routes from the start to all other nodes
	// We only interested in the end point
	int count = 0;
	computeShortest(end, start, count);
	
	// Output
	cout << count << endl;
	
	return 0;
}

// Dijsktra from source to all other nodes
void explore(int source, int end) {
	distVect[source] = 0;
	set<nodePair> pq;
	for (int i = 0; i < (int)adjList.size(); i++) {
		if (i == source)
			pq.insert(make_pair(0, i));
		else
			pq.insert(make_pair(INF, i));
	}
	
	nodePair current;
	int node, sum, neighbour;
	
	while (!pq.empty()) {
		current = *(pq.begin());
		pq.erase(current);
		node = current.second;
		
		// If this node is an end node we break
		if (node == end) break;
		
		// Go through all neighbours
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			neighbour = adjList[node][i].second;
			// If the sum of the current node and the edge weight to the
			// neighbour node is lesser than the neighbour's current
			// distance, we update that distance and add the predecessor
			// to another graph
			sum = distVect[node] + adjList[node][i].first;
			if (sum <= distVect[neighbour]) {
				// If the the sum is lesser, we should clear all the
				// previous predecessors since those have higher sum
				if (sum < distVect[neighbour]) {
					predGraph[neighbour].clear();
				}
				predGraph[neighbour].push_back(make_pair(adjList[node][i].first, node));
				
				pq.erase(pq.find(make_pair(distVect[neighbour], neighbour)));
				pq.insert(make_pair(sum, neighbour));
				distVect[neighbour] = sum;
			}
			if (neighbour == end) break;
		}
	}
}

// DFS from the source to the end(required) point
// If the dead end has no more neighbours and is a end point, we add to
// count
void computeShortest(int source, int end, int &count) {
	if (source == end)
		count++;
		
	// Go through all its neighbours
	for (auto it : predGraph[source]) {
		computeShortest(it.second, end, count);
	}
}
