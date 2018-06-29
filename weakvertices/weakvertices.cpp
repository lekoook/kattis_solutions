/******************************************************************************
  CS2040C AY2017/18 Semester 2
  weakvertices.cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

#define MAX 20
using namespace std;

int triangle[MAX] = { 0 };
vector< vector<int> > adjMat;

//bool checkVert(int index);
void checkVert(int index);

int main(void) {
	int vertices;
	bool isWeak;
	while(cin >> vertices, vertices != -1) {
		// Read in the adj matrix
		for (int i = 0; i < vertices; i++) {
			vector<int> tempVect;
			int val;
			for (int j = 0; j < vertices; j++) {
				cin >> val;
				tempVect.push_back(val);
			}
			adjMat.push_back(tempVect);
		}

		// Check for vertices
		for (int i = 0; i < (int)adjMat.size(); i++) {
			//isWeak = checkVert(i);
			//if (triangle[i] == 0)
				checkVert(i);
			//if (isWeak) 
				//cout << i << " ";
		}

		// Print all the weak vertices
		//for (auto it : triangle) {
		//	cout << it << " ";
		//}
		//cout << endl;
		//cout << "set size is " << triangle.size() << endl;
		//adjMat.clear();
		for (int i = 0; i < vertices; i++) {
			if (triangle[i] == 0) {
				cout << i << " ";
			}
		}
		cout << endl;

		// clear the triangle array
		for (int i = 0; i < MAX; i++) {
			triangle[i] = 0;
		}
		adjMat.clear();
	}

	return 0;
}

//bool checkVert(int index) {
void checkVert(int index) {
	bool isWeak = true;
	vector<int> neighbours;
	for (int i = 0; i < (int)adjMat[index].size(); i++) {
		if (adjMat[index][i])
			neighbours.push_back(i);
	}

	if (neighbours.size() > 1) {
		for (int i = 0; i < (int)neighbours.size(); i++) {
			for (int j = 0; j < (int)neighbours.size(); j++) {
				//isWeak = false;
				// Means the two neighbours of the given source vertex are also neighbours with each other
				// Then that means these two neighbours and source vertex are all connected
				if (adjMat[neighbours[i]][neighbours[j]]) {
					triangle[index] = 1;
					triangle[neighbours[i]] = 1;
					triangle[neighbours[j]] = 1;
				}
				
			}
		}
	}
	

	//return isWeak;
}
