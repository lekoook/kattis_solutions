#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, days;
	int maxDays = 0, dayCounter = 0;
	vector<int> trees;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> days;
		trees.push_back(days);
	}
	// Sort the trees in descending order
	sort(trees.begin(), trees.end(), greater<int>());

	// Run through each tree
	for (int i = 0; i < N; i++) {
		int daysToGrow = trees[i] + 1 + dayCounter;
		if (daysToGrow > maxDays)
			maxDays = daysToGrow;
		dayCounter++;
	}

	cout << maxDays + 1 << endl;
	return 0;
}