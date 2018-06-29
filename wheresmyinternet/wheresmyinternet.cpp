#include <iostream>
#include <vector>

using namespace std;

void explore(int source, vector< vector<int> > &adjList, 
	vector<bool> &connectedList);

int main(void) {
	int houses, connections, n1, n2;
	vector< vector<int> > adjList;
	vector<bool> connectedList;

	cin >> houses >> connections;

	// Reset all data structures
	adjList.assign(houses, vector<int>(0));
	connectedList.assign(houses, false);

	// Read in all data
	while(connections--) {
		cin >> n1 >> n2; n1 -= 1; n2 -= 1;
		adjList[n1].push_back(n2);
		adjList[n2].push_back(n1);
	}

	// Explore the network using DFS
	explore(0, adjList, connectedList);

	// Print output
	bool found = false;
	for (int i = 0; i < houses; i++) {
		if (connectedList[i] == false) {
			cout << i + 1 << endl;
			found = true;
		}
	}

	if (!found) cout << "Connected" << endl;
	
	return 0;
}

void explore(int source, vector< vector<int> > &adjList, 
	vector<bool> &connectedList) {
	if (connectedList[source]) return;
	// Mark the current node
	connectedList[source] = true;

	// Explore all neighbouring nodes
	for (int i = 0; i < (int)adjList[source].size(); i++) {
		explore(adjList[source][i], adjList, connectedList);
	}
}