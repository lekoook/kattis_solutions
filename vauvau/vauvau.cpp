#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &vect) {
	for (auto it : vect) cout << it << " ";
	cout << endl;
}

int main(void) {
	int A, B, C, D, P, M, G, highest = 0;
	// '1' means aggressive, '0' means calm
	vector<int> dogOnePeriod;
	vector<int> dogTwoPeriod;
	
	cin >> A >> B >> C >> D;
	cin >> P;
	if (P > highest) highest = P;
	cin >> M;
	if (M > highest) highest = M;
	cin >> G;
	if (G > highest) highest = G;

	dogOnePeriod.assign(highest, 0);
	dogTwoPeriod.assign(highest, 0);

	// Fill up the period of both dogs
	// Dog 1
	for (int i = 0; i < highest; i++) {
		int j;
		// Fill the aggressive period
		for (j = i; (j < i + A) && (j < highest); j++)
			dogOnePeriod[j] = 1;
		int k;
		// Fill the calm period
		for (k = j; (k < j + B) && (k < highest); k++)
			dogOnePeriod[k] = 0;			
		i = k - 1;
	}

	// Dog 2
	for (int i = 0; i < highest; i++) {
		int j;
		// Fill the aggressive period
		for (j = i; (j < i + C) && (j < highest); j++)
			dogTwoPeriod[j] = 1;
		int k;
		// Fill the calm period
		for (k = j; (k < j + D) && (k < highest); k++)
			dogTwoPeriod[k] = 0;

		i = k - 1;
	}

	// Print the outputs
	// For postman
	if (dogOnePeriod[P-1] && dogTwoPeriod[P-1]) cout << "both" << endl;
	else if (!dogOnePeriod[P-1] && !dogTwoPeriod[P-1]) cout << "none" << endl;
	else cout << "one" << endl;
	// For milkman
	if (dogOnePeriod[M-1] && dogTwoPeriod[M-1]) cout << "both" << endl;
	else if (!dogOnePeriod[M-1] && !dogTwoPeriod[M-1]) cout << "none" << endl;
	else cout << "one" << endl;
	// For garbageman
	if (dogOnePeriod[G-1] && dogTwoPeriod[G-1]) cout << "both" << endl;
	else if (!dogOnePeriod[G-1] && !dogTwoPeriod[G-1]) cout << "none" << endl;
	else cout << "one" << endl;
	
	return 0;
}