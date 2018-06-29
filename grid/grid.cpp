/******************************************************************************
  CS2040C AY2017/18 Semester 2
  grid.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector< vector<int> > grid;
vector< vector<int> > distances;
vector< vector<char> > drawing;

void explore(int rows, int cols);

void printL() {
	cout << "grid: " << endl;
	for (auto &it : grid) {
		for (auto &it2: it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
	
	cout << "distances: " << endl;
	for (auto &it : distances) {
		for (auto &it2: it) {
			cout << it2 << "\t";
		}
		cout << endl;
	}
}

void printD() {
	for (auto &it : drawing) {
		for (auto &it2: it) {
			cout << it2;
		}
		cout << endl;
	}
	cout << endl;
}

int main(void) {
	int rows, cols;
	string value;
	
	cin >> rows >> cols; cin.ignore(10000, '\n');
	grid.assign(rows, vector<int>(cols));
	distances.assign(rows, vector<int>(cols, INF));
	drawing.assign(rows, vector<char>(cols, '-'));
	
	// Read in the grid
	for (int i = 0; i < rows; i++) {
		getline(cin, value, '\n');
		for (int j = 0; j < cols; j++) {
			grid[i][j] = value[j] - '0';
		}
	}
	
	// Run BFS from the top left to find the bottom right
	explore(rows, cols);
	
	// Output
	if (distances[rows-1][cols-1] == INF)
		cout << "-1" << endl;
	else
		cout << distances[rows-1][cols-1] << endl;
	
	//printL();
	return 0;
}

void explore(int rows, int cols) {
	pair<int, int> current;
	current = make_pair(0, 0);
	queue< pair<int, int> > que;
	que.push(current);
	distances[current.first][current.second] = 0;
	
	while (!que.empty()) {
		current = que.front();
		que.pop();
		int digit = grid[current.first][current.second];
		int currR = current.first;
		int currC = current.second;
		drawing[currR][currC] = '*';
		printD();
		//cout << "checking " << currR << "," << currC << endl;
		
		if (currR == rows-1 && currC == cols-1) break;
		
		// Go through all its neighbouring given the step
		// Up
		if (currR - digit >= 0) {
//			cout << "up " << currR << "," << currC << endl;
			if (distances[currR-digit][currC] > distances[currR][currC]) {
				distances[currR-digit][currC] = distances[currR][currC] + 1;
				que.push(make_pair(currR - digit, currC));
			}
		}
		// Right
		if (currC + digit < cols) {
//			cout << "right " << currR << "," << currC << endl;
			if (distances[currR][currC+digit] > distances[currR][currC]) {
				distances[currR][currC+digit] = distances[currR][currC] + 1;
				que.push(make_pair(currR, currC + digit));
			}
		}
		// Down
		if (currR + digit < rows) {
//			cout << "down" << endl;
			if (distances[currR+digit][currC] > distances[currR][currC]) {
				distances[currR+digit][currC] = distances[currR][currC] + 1;
				que.push(make_pair(currR + digit, currC));
			}
		}
		// Left
		if (currC - digit >= 0) {
//			cout << "left" << endl;
			if (distances[currR][currC-digit] > distances[currR][currC]) {
				distances[currR][currC-digit] = distances[currR][currC] + 1;
				que.push(make_pair(currR, currC - digit));
			}
		}
	}
	
}
