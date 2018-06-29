#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> custPair;
priority_queue<custPair> pq;

int main(void) {
	int customers, timeToClose, cash, time;
	int timeCounter = 0, totalSum = 0;

	// Get all customers info
	cin >> customers >> timeToClose;
	while (customers--) {
		cin >> cash >> time;
		pq.push(make_pair(cash, time));
	}

	// Sum up the maximum cash
	while (timeCounter < timeToClose && pq.size() > 0) {
		if (pq.top().second >= timeCounter) {
			totalSum += pq.top().first;
			pq.pop();
			timeCounter++;
		}
		else {
			pq.pop();
		}
	}

	cout << totalSum << endl;
	
	return 0;
}