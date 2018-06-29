/******************************************************************************
  CS2040C AY2017/18 Semester 2
  emptyingbaltic.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

#define INF 1000000000
#define MAX 500

using namespace std;

// arg0: y-coordinate (row)
// arg1: x-coordinate (col)
typedef pair<int, int> nodePair;

int grid[MAX][MAX];
vector< vector< vector<nodePair> > > adjList;
vector< vector<int> > distVect;

int cellCount = 0;

void explore(int startX, int startY);

int main(void) {
	int rows, cols, value, sX, sY;
	
	cin >> rows >> cols;
	
	adjList.assign(rows, vector< vector<nodePair>(0) >(cols));
	distVect.assign(rows, vector<int>(cols, INF));
	
	// Read in the grid
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			cin >> value;
			grid[i][j] = value;
			if (value < 0) cellCount++;
		}
	}
	
	// Read in the start location
	cin >> sY >> sX;
	
	// Dijkstra to form the route paths
	explore(sY, sX); 
	
	return 0;
}

void explore(int startX, int startY) {
	distVect[startX][startY] = 0;
	set<nodePair> pq;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == startX 
			if (grid[i][j] < 0)
				pq.insert(make_pair(i, j));
		}
	}
}
