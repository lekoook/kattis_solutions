#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< priority_queue<int> > heapArray;

int main(void) {
	int customers, timeToClose, cash, time;
	int timeCounter = 0, totalSum = 0;

	// Get all customers info
	cin >> customers >> timeToClose;
	heapArray.assign(timeToClose, priority_queue<int>());
	while (customers--) {
		cin >> cash >> time;
		heapArray[time].push(cash);
	}

	// Sum up the maximum cash
	while (timeCounter < timeToClose) {
		if (heapArray[timeCounter].size() > 0) {
			cout << "adding " << heapArray[timeCounter].top() << endl;
			totalSum += heapArray[timeCounter].top();
			heapArray[timeCounter].pop();
			timeCounter++;
		}
		else {
			bool allEmpty = true;
			for (int i = timeCounter+1; i < timeToClose; i++) {
				if (heapArray[i].size() > 0) {
					cout << "adding " << heapArray[i].top() << endl;
					totalSum += heapArray[i].top();
					heapArray[i].pop();
					timeCounter++;
					allEmpty = false;
					break;
				}
			}
			if (allEmpty) break;
		}
	}

	cout << totalSum << endl;
	
	return 0;
}