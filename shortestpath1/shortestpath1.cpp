/******************************************************************************
  CS2040C AY2017/18 Semester 2
  shortestpath1.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <utility>

#define INF 1000000000

using namespace std;

typedef pair<int, int> nodePair;

vector< vector<nodePair> > adjList;
vector<int> qVect;
vector<int> dist;

void explore(int source);

int main(void) {
	int nodes, edges, queries, start;
	int node1, node2, weight, q;
	
	while (cin >> nodes >> edges >> queries >> start) {
		if (nodes == 0 && edges == 0 && queries == 0 && start == 0)
			break;
		
		// Reset
		adjList.assign(nodes, vector<nodePair>(0));
		qVect.assign(0, 0);
		dist.assign(nodes, INF);
		
		// Read in the graph
		for (int i = 0; i < edges; i++) {
			cin >> node1 >> node2 >> weight;
			adjList[node1].push_back(make_pair(weight, node2));
		}
		
		// Read in the queries
		for (int i = 0; i < queries; i++) {
			cin >> q;
			qVect.push_back(q);
		}
		
		// Run Dijsktra from start node to all other nodes
		explore(start);
		
		// Output the answers
		for (int i = 0; i < queries; i++) {
			if (dist[qVect[i]] == INF)
				cout << "Impossible" << endl;
			else
				cout << dist[qVect[i]] << endl;
		}
		
		cout << endl;
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
	int sum, neighbour, node;
	
	while (!pq.empty()) {
		current = *(pq.begin());
		pq.erase(current);
		node = current.second;
		
		// Go through all neighbours
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			neighbour = adjList[node][i].second;
			// If the sum of current node distance and weight to neighbour
			// is lesser than the distance of the neighbour, update
			// the neighbour distance in pq and dist[]
			sum = dist[node] + adjList[node][i].first;
			if (sum < dist[neighbour]) {
				pq.erase(make_pair(dist[neighbour], neighbour));
				pq.insert(make_pair(sum, neighbour));
				dist[neighbour] = sum;
			}
		}
	}
}
