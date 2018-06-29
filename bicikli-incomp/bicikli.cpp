// ALGORITHM TOO SLOW
// USE DYNAMIC PROGRAMMING

#include <iostream>
#include <vector>

using namespace std;

void explore(int source, vector< vector<int> > &adjList,
	vector<int> &status, int &counter, bool &isCyclic);

int main(void) {
	int towns, roads, t1, t2, counter = 0;
	vector< vector<int> > adjList;
	vector<int> status;
	bool isCyclic = false;

	cin >> towns >> roads;
	adjList.assign(towns, vector<int>(0));
	status.assign(towns, 0);
	
	while (roads--) {
		cin >> t1 >> t2; t1 -= 1; t2 -= 1;
		adjList[t1].push_back(t2);
	}
	// for (auto it : adjList) {
		// for (auto it2 : it) {
			// cout << it2+1 << " ";
		// }
		// cout << endl;
	// }
	explore(0, adjList, status, counter, isCyclic);

	if (isCyclic)
		cout << "inf" << endl;
	else
		cout << counter << endl;
	
	return 0;
}

void explore(int source, vector< vector<int> > &adjList,
	vector<int> &status, int &counter, bool &isCyclic) {
	status[source] = 1;

	if (isCyclic) return;
	
	if (source == 1) {
		status[source] = 0;
		counter++;
		return;
	}

	for (int i = 0; i < (int)adjList[source].size(); i++) {
//		cout << "current at " << source+1 << " visiting " << adjList[source][i]+1 << endl;
		if (status[adjList[source][i]] == 1) {
			isCyclic = true;
			return;
		} 
		explore(adjList[source][i], adjList, status, counter, isCyclic);
		if (isCyclic) return;
	}

	status[source] = 2;
	
	return;		
}