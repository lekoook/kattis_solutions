#include <iostream>
#include <set>
#include <string>

using namespace std;

void recurse(string given, set<string> &answers, int start);

int main(void) {
	set<string> answers;
	string input;

	getline(cin, input, '\n');
	recurse(input, answers, 0);

	// Print
	for (auto it : answers) {
		cout << it << endl;
	}
	
	return 0;
}

void recurse(string given, set<string> &answers, int start) {
	// Remove every possible pairs of brackets in the current string
	// Then recurse into that new constructed string
	for (int i = start; i < (int)given.size(); i++) {
		if (given[i] == '(') {
			string newString;
			int matchingCount = 0;
			for (int j = i+1; j < (int)given.size(); j++) {
				// A possible pair is found, remove that pair
				if (given[j] == ')' && matchingCount == 0) {
					// Construct the new string
					newString = given.substr(0, i) + given.substr(i+1, j-i-1) + given.substr(j+1, (int)given.size());
//					cout << "original string: " << given << ", ";
//					cout << "components are: |" << given.substr(0, i) << "| , |" << given.substr(i+1, j-i-1) << "| , |" << given.substr(j+1, (int)given.size()); 
//					cout << "|    new string is \"" << newString << "\"" << endl;
					answers.insert(newString);
					recurse(newString, answers, i);
					break;
				}
				else if (given[j] == '(') {
					matchingCount++;
				}
				else if (given[j] == ')') {
					matchingCount--;
				}
			}
		}
	}
}