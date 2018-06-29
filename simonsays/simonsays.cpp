#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	string rest;

	cin >> N; cin.ignore(1000, '\n');
	for (int i = 0; i < N; i++) {
		getline(cin, rest, '\n');

		if (rest.substr(0, 10).compare("Simon says") == 0) {
			cout << rest.substr(10) << endl;
		}
	}

	return 0;
}
