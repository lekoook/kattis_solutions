/******************************************************************************
  CS2040C AY2017/18 Semester 2
  hidingplaces.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define MAXR 8
#define MAXC 8
#define INF 100000

using namespace std;

typedef pair<int, int> coord;

vector< vector<int> > distances;
vector<string> places;
int deltaY[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int deltaX[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int findPlaces(coord source);

void printL() {
	cout << "distances: " << endl;
	for (auto &it: distances) {
		for (auto &it2: it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
}

int main(void) {
	int cases;
	string start;
	
	cin >> cases; cin.ignore(10000, '\n');
	for (int i = 0; i < cases; i++) {
		// Read in the starting coordinate
		cin >> start;
		coord source;
		source.first = 8 - (start[1] - '0');
		source.second = start[0] - 'a';
		
		// Run BFS to get the hiding places and steps
		int steps = findPlaces(source);
		
		// Output the results
		// Find all the grids with steps value and sort them
		places.clear();
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				if (distances[j][k] == steps) {
					char row = (8 - j) + '0';
					char col = 'a' + k;
					string add;
					add += col;
					add += row;
					
					places.push_back(add);
				}
			}
		}
		cout << steps << " ";
		for (int j = 0; j < (int)places.size(); j++) {
			cout << places[j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

int findPlaces(coord source) {
	queue<coord> que;
	int maxCount = 0;
	que.push(source);
	coord current;
	int row, col;
	distances.assign(8, vector<int>(8, INF));
	distances[source.first][source.second] = 0;
	
	while(!que.empty()) {
		current = que.front();
		que.pop();
		row = current.first;
		col = current.second;
//		cout << "current: " << row << "," << col << endl;
		// Go through all 8 possible moves
		for (int i = 0; i < 8; i++) {
			// If the next move is not out of bounds
			if (row + deltaY[i] >= 0 && row + deltaY[i] < MAXR && col + deltaX[i] >= 0 && col + deltaX[i] < MAXC) {
//				cout << "current distance: " << distances[row][col] << " next distance: " << distances[row+deltaY[i]][col+deltaX[i]] << endl;
				// If the next space's distance is greater than current
				if (distances[row+deltaY[i]][col+deltaX[i]] > distances[row][col]) {
					distances[row+deltaY[i]][col+deltaX[i]] = distances[row][col] + 1;
//					cout << "current: " << row << "," << col << "\tnext: " << row+deltaY[i] << "," << col+deltaX[i] << endl;
					que.push(make_pair(row+deltaY[i], col+deltaX[i]));
					// If the computed distance of next space is greater than current MAX
					if (distances[row+deltaY[i]][col+deltaX[i]] > maxCount) {
						maxCount = distances[row+deltaY[i]][col+deltaX[i]];
					}
				}
			}
		}
	}
//	printL();
	return maxCount;
}
