#include <iostream>
#include <cctype>

using namespace std;

bool canPass(string &input) {
	input[0] = tolower(input[0]);

	for (int i = 0; i < (int)input.size(); i++) {
		if (isupper(input[i])) return false;
	}

	return true;
}

int main(void) {
	int count = 0, P, T;
	string input;
	bool pass = true;

	cin >> P >> T; cin.ignore(1000, '\n');

	for (int i = 0; i < P; i++) {
		pass = true;

		for (int j = 0; j < T; j++) {
			getline(cin, input, '\n');
			
			if (!canPass(input)) pass = false;
		}

		if (pass) count++;
	}
	cout << count << endl;
	return 0;
}
