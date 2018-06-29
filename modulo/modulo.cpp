#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int input;
	set<int> check;

	for (int i = 0; i < 10; i++) {
		cin >> input;
		check.insert(input % 42);
	}

	cout << (int)check.size() << endl;

	return 0;
}