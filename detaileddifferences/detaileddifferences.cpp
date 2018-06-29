#include <iostream>

using namespace std;

int main(void) {
	int cases;
	string line1, line2;

	cin >> cases; cin.ignore(1000, '\n');
	while (cases--) {
		cin >> line1 >> line2;
		cout << line1 << endl;
		cout << line2 << endl;
		for (int i = 0; i < (int)line1.size(); i++) {
			if (line1[i] == line2[i])
				cout << ".";
			else
				cout << "*";
		}
		cout << endl << endl;
	}
	return 0;
}