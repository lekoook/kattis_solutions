/******************************************************************************
  CS2040C AY2017/18 Semester 2
  getshorty.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cmath>

#define INF 1

using namespace std;

typedef pair<double, int> nodePair;

vector< vector<nodePair> > adjList;
vector<double> dist;

void explore(int source);

int main(void) {
	int nodes, edges;
	int node1, node2;
	double weight;
	
	while (cin >> nodes >> edges, nodes != 0 && edges != 0) {
		// Reset
		adjList.assign(nodes, vector<nodePair>(0));
		dist.assign(nodes, INF);
		
		// Read in the graph
		for (int i = 0; i < edges; i++) {
			cin >> node1 >> node2 >> weight;
			adjList[node1].push_back(make_pair(weight, node2));
			adjList[node2].push_back(make_pair(weight, node1));
		}
		
		// Run Dijsktra from node 0 to all other nodes
		explore(0);
		
		double ans = pow(10, -dist[nodes-1]);
		printf("%0.4lf\n", ans);
	}
	
	return 0;
}

void explore(int source) {
	dist[source] = 0;
	set<nodePair> pq;
	for (int i = 0; i < (int)adjList.size(); i++) {
		if (i == source)
			pq.insert(make_pair(0, i));
		else
			pq.insert(make_pair(INF, i));
	}
	
	nodePair current;
	int node, neighbour;
	double sum;
	
	while (!pq.empty()) {
		current = *(pq.begin());
		pq.erase(current);
		node = current.second;
		
		// Go through all neighbours
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			neighbour = adjList[node][i].second;
			// We 'log' the weights of all edges. Since the weights are
			// between 0 to 1, by using log, we effective switched the 
			// higher values to lower values.
			sum = dist[node] + (-log10(adjList[node][i].first));
			if (sum < dist[neighbour]) {
				pq.erase(make_pair(dist[neighbour], neighbour));
				pq.insert(make_pair(sum, neighbour));
				dist[neighbour] = sum;
			}
		}
	}
}
