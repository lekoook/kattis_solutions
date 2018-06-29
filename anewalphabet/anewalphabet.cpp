#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

int main(void) {
	string input, output = "";
	vector<string> translation;

	// Build the translation table
	translation.push_back("@");
	translation.push_back("8");
	translation.push_back("(");
	translation.push_back("|)");
	translation.push_back("3");
	translation.push_back("#");
	translation.push_back("6");
	translation.push_back("[-]");
	translation.push_back("|");
	translation.push_back("_|");
	translation.push_back("|<");
	translation.push_back("1");
	translation.push_back("[]\\/[]");
	translation.push_back("[]\\[]");
	translation.push_back("0");
	translation.push_back("|D");
	translation.push_back("(,)");
	translation.push_back("|Z");
	translation.push_back("$");
	translation.push_back("']['");
	translation.push_back("|_|");
	translation.push_back("\\/");
	translation.push_back("\\/\\/");
	translation.push_back("}{");
	translation.push_back("`/");
	translation.push_back("2");

	getline(cin, input, '\n');
	// Run through the entire input line and translate
	for (int i = 0; i < (int)input.size(); i++) {
		// If the character is a lower or upper case alphabet
		// Translate them to the 'cooler' alphabet
		if (isalpha(input[i])) {
			char c = tolower(input[i]);
			output += translation[c - 'a'];
		}
		// Else keep the character in the output
		else {
			output += input[i];
		}
	}

	cout << output << endl;
	return 0;
}