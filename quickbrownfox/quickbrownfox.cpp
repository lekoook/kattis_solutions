#include <iostream>
#include <vector>
#include <cctype>
#include <set>

using namespace std;

int main(void) {
	vector<int> check;
	set<char> exist;
	string input;
	char c;
	int cases;

	cin >> cases; cin.ignore(1000, '\n');

	for (int i = 0; i < cases; i++) {
		getline(cin, input);
		check.assign(26, 0);
		exist.clear();

		// Go through each charactor in the string
		for (int j = 0; j < (int)input.size(); j++) {
			c = input[j];
			if (isalpha(c)) {
				c = tolower(c);
				check[c - 'a'] = 1;
				exist.insert(c);
			}
		}

		// Check for panagram
		if ((int)exist.size() >= 26) {
			cout << "pangram" << endl;
		}
		else {
			cout << "missing" << " ";
			for (int j = 0; j < 26; j++) {
				if (check[j] == 0) {
					c = (char)(j + 'a');
					cout << c;
				}
			}
			cout << endl;
		}	
	}


	return 0;
}