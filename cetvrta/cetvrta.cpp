#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	unordered_set<int> X;
	unordered_set<int> Y;
	int value;

	for (int i = 0; i < 3; i++) {
		cin >> value;
		if (X.count(value) != 0)
			X.erase(X.find(value));
		else
			X.insert(value);

		cin >> value;
		if (Y.count(value) != 0)
			Y.erase(Y.find(value));
		else
			Y.insert(value);
	}

	cout << *(X.begin()) << " " << *(Y.begin()) << endl;

	return 0;
}
