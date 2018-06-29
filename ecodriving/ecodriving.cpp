#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;

// arg0: junction index
// arg1: distance from previous node
typedef pair<int, double> nodePair;
typedef pair<int, int> coordPair;
typedef pair<double, double> routePair;

vector< vector<nodePair> > adjList;
vector<coordPair> junctionsVect;
vector<nodePair> currentRoute;
vector<routePair> possibleRoutes;

double getTurnAngle(coordPair pair1, coordPair pair2);
double getDist(coordPair pair1, coordPair pair2);
void explore(int current, double distFromPrev, int dest);
void computeRoute();

int main(void) {
	int junctions, roads, maxDist, x, y, j1, j2;

	cin >> junctions >> roads >> maxDist;
	adjList.assign(junctions, vector<nodePair>(0));

	for (int i = 0; i < junctions; i++) {
		cin >> x >> y;
		junctionsVect.push_back(make_pair(x, y));
	}

	for (int i = 0; i < roads; i++) {
		cin >> j1 >> j2;
		j1 -= 1;
		j2 -= 1;
		double dist = getDist(junctionsVect[j1], junctionsVect[j2]);
		nodePair tup = make_pair(j2, dist);
		adjList[j1].push_back(tup);
	}

	explore(0, 0, junctions-1);
	return 0;
}

// DFS from the source (0) to find all possible routes to the last junction
// For each possible route, find the max turning angle and distance
// Push the two info into another vector
void explore(int current, double distFromPrev, int dest) {
	currentRoute.push_back(make_pair(current, distFromPrev));

	if (current == dest) {
		computeRoute();
	}

	// Go through all the neighbours
	for (int i = 0; i < (int)adjList[current].size(); i++) {
		explore(adjList[current][i].first, adjList[current][i].second, dest);
	}
	
	currentRoute.pop_back();
}


// Given an array of a route, compute the max turning angle
// and travel distance
void computeRoute() {
	double totalDist = 0;
	double maxAngle = 0;

	for (int i = 0; i < (int)currentRoute.size(); i++) {
		totalDist += currentRoute[i].second;
	}
}
double getTurnAngle(coordPair pair1, coordPair pair2) {
	
	return 0;
}

double getDist(coordPair pair1, coordPair pair2) {
	double dx = fabs(pair1.first - pair2.first);
	double dy = fabs(pair1.second - pair2.second);

	return sqrt(pow(dx, 2) + pow(dy, 2));
}