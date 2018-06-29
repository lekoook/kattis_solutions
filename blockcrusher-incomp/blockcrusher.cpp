/******************************************************************************
  CS2040C AY2017/18 Semester 2
  blockcrusher.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <set>
#include <vector>
#include <utility>

#define MAXH 20
#define MAXW 60
#define INF 1000000000

using namespace std;

// arg0: y-coordinate
// arg1: x-coordinate
typedef pair<int, int> coord;
// arg0: weight
// arg1: coordinates
typedef pair<int, coord> cell;

int dy[3] = {1, 1, 1};
int dx[3] = {1, 0, -1};
char grid[MAXH][MAXW];
vector< vector<int> > dist;
vector< vector< vector<coord> > > predG;
vector<coord> crackline;
vector<coord> line;

int rows, cols;

void explore();
void backtrack(coord end);

void p() {
	cout << "grid:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << grid[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << "distance:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << dist[i][j] << "\t";
		}
		cout << endl;
	}
	
	cout << "pred graph:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << i << "," << j << ":";
			for (auto &it : predG[i][j]) {
				cout << " " << it.first << "," << it.second;
			}
			cout << endl;
		}
	}
}

int main(void) {
	string input;
	
	while (cin >> rows >> cols, rows != 0 && cols != 0) {
		cin.ignore(1000, '\n');
		
		// Reset
		dist.assign(rows, vector<int>(cols, INF));
		crackline.assign(rows, coord());
		line.assign(0, coord());
		predG.assign(rows, vector< vector<coord> >(cols));
		
		// Read in grid
		for (int i = 0; i < rows; i++) {
			getline(cin, input, '\n');
			for (int j = 0; j < cols; j++) {
				grid[i][j] = input[j];
			}
		}
		//p();
		// Run Dijkstra on grid
		explore();
		
		// Output answer
		for (int i = 0; i < rows; i++) {
			grid[line[i].first][line[i].second] = ' ';
		}
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}

void explore() {
	set<cell> pq;
	for (int i = 0; i < cols; i++) {
		pq.insert(make_pair(grid[0][i] - '0', make_pair(0, i)));
		dist[0][i] = grid[0][i] - '0';
	}
	
	cell current;
	int nextX, nextY, sum;
	
	
	while (!pq.empty()) {
		current = *(pq.begin());
		pq.erase(current);
		//cout << "exploring " << current.second.first << " " << current.second.second << endl;
		
		// Go through all neighbours
		for (int i = 0; i < 3; i++) {
			nextY = current.second.first + dy[i];
			nextX = current.second.second + dx[i];
			//cout << "current dist = " << dist[current.second.first][current.second.second] << "next dist = " << (grid[nextY][nextX] - '0') << endl;
			sum = dist[current.second.first][current.second.second] + (grid[nextY][nextX] - '0');
			if (nextY >= 0 && nextX >= 0 && nextY < rows && nextX < cols && sum <= dist[nextY][nextX]) {
				if (sum < dist[nextY][nextX]) {
				//	cout << "adding " << sum << " on " << nextY << "," << nextX << endl;
					predG[nextY][nextX].clear();	
					pq.erase(make_pair(dist[nextY][nextX], make_pair(nextY, nextX)));
					pq.insert(make_pair(sum, make_pair(nextY, nextX)));
					dist[nextY][nextX] = sum;
				}
				
				predG[nextY][nextX].push_back(make_pair(current.second.first, current.second.second));
				
				
			}
		}
		
	}
	
	int endX, lowest = INF;
	for (int i = 0; i < cols; i++) {
		if (dist[rows-1][i] < lowest) {
			lowest = dist[rows-1][i];
			endX = i;
		}
	}
	
	// Backtrack to the start
	backtrack(make_pair(rows-1, endX));
	
}

void backtrack(coord end) {
	line.push_back(end);
	// If there is no more parents, we found the crack line
	if ((int)predG[end.first][end.second].size() == 0) {
		crackline = line;
	}
	
	// Go through all parents
	for (int i = 0; i < (int)predG[end.first][end.second].size(); i++) {
		backtrack(predG[end.first][end.second][i]);
	}
	
	line.pop_back();
}
