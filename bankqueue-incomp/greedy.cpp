#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<double, int, int> custTup;
vector<custTup> sequence;

bool custComp(custTup first, custTup second) {
	if (get<0>(first) > get<0>(second))
		return true;
	else if (get<0>(first) == get<0>(second)) 
		if (get<2>(first) <= get<2>(second))
			return true;

	return false;
}

int main(void) {
	int customers, timeToClose, cash, time;
	int timeCounter = 0, totalSum = 0;

	// Get all customers info
	cin >> customers >> timeToClose;
	while (customers--) {
		cin >> cash >> time;
		double score = (double)cash / (double) time;
		sequence.push_back(make_tuple(score, cash, time));
	}

	// Sort the scores
	sort(sequence.begin(), sequence.end(), custComp);

//	for (auto it : sequence) cout << get<1>(it) << " ";
//	cout << endl;

	// Sum up the maximum cash
	while (timeCounter < timeToClose) {
		if (get<2>(sequence[timeCounter]) >= timeCounter) {
//			cout << "adding " << get<1>(sequence[timeCounter]) << " with timeCounter = " << timeCounter << endl;
			totalSum += get<1>(sequence[timeCounter]);
		}
		timeCounter++;
	}

	cout << totalSum << endl;
	
	return 0;
}