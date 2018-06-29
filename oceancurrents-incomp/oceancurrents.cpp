#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INF 1000000

using namespace std;

typedef pair<int, int> coordPair;

int rows, cols;
int dRows[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dCols[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector< vector<int> > adjList;
vector< vector<int> > dist;


int explore(int rowStart, int colStart, int rowEnd, int colEnd);
void formNode(int row, int col, char c);

int main(void) {
	int trips;
	int rowStart, colStart, rowEnd, colEnd;

	// Read in the grid
	cin >> rows >> cols; cin.ignore(1000, '\n');
	adjList.assign(rows, vector<int>(cols));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			formNode(i, j, getchar());
		}
		cin.ignore(1000, '\n');
	}	
/*
	// Read in the trips
	cin >> trips;
	while (trips--) {	
		dist.assign(rows, vector<int>(cols, INF));
		cin >> rowStart >> colStart >> rowEnd >> colEnd;
		cout << explore(rowStart-1, colStart-1, rowEnd-1, colEnd-1) << endl;
	}	
*/
	return 0;
}

void formNode(int row, int col, char c) {
	int direct = c - '0';

	for (int i = 0; i < 8; i++) {
		if (i != direct) {
			if ((row + dRows[direct] >= 0) && (row + dRows[direct] < rows) && (col + dCols[direct] >= 0) && (col + dCols[direct] < cols))
				adjList[row][] = 1;
			else
				adjList[row + dRows[direct]][col + dCols[direct]] = -1;
		}
		else {
			if ((row + dRows[direct] >= 0) && (row + dRows[direct] < rows) && (col + dCols[direct] >= 0) && (col + dCols[direct] < cols)){}
//				adjList[row + dRows[direct]][col + dCols[direct]] = 0;
			else{}
//				adjList[row + dRows[direct]][col + dCols[direct]] = -1;
		}
	}

}

int explore(int rowStart, int colStart, int rowEnd, int colEnd) {
	dist[rowStart][colStart] = 0;
	coordPair startCoord = make_pair(rowStart, colStart);
	coordPair current;
	int sum;
	queue<coordPair> que;
	que.push(startCoord);

	while (!que.empty()) {
		current = que.front();
		que.pop();

		// Go through all neighbouring grids
		int row = current.first, col = current.second;
		for (int i = 0; i < 8; i++) {
			// Relax
			if ((row + dRows[i] >= 0) && (row + dRows[i] < rows) && (col + dCols[i] >= 0) && (col + dCols[i] < cols)) {
				sum = dist[row][col] + adjList[row + dRows[i]][col + dCols[i]];
				if (sum < dist[row + dRows[i]][col + dCols[i]])
					dist[row + dRows[i]][col + dCols[i]] = sum;
			}
		}
	}

	return dist[rowEnd][colEnd];
}