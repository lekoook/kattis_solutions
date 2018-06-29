#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int conv(char c);

int main(void) {
	string input;
	vector<string> encoder;
	unordered_map<string, string> decoder;
	vector<int> lengthTable;

	// Build the encoding table and code length table
	encoder.push_back(".-");
	encoder.push_back("-...");
	encoder.push_back("-.-.");
	encoder.push_back("-..");
	encoder.push_back(".");
	encoder.push_back("..-.");
	encoder.push_back("--.");
	encoder.push_back("....");
	encoder.push_back("..");
	encoder.push_back(".---");
	encoder.push_back("-.-");
	encoder.push_back(".-..");
	encoder.push_back("--");
	encoder.push_back("-.");
	encoder.push_back("---");
	encoder.push_back(".--.");
	encoder.push_back("--.-");
	encoder.push_back(".-.");
	encoder.push_back("...");
	encoder.push_back("-");
	encoder.push_back("..-");
	encoder.push_back("...-");
	encoder.push_back(".--");
	encoder.push_back("-..-");
	encoder.push_back("-.--");
	encoder.push_back("--..");
	encoder.push_back("..--"); // underscore
	encoder.push_back(".-.-"); // comma
	encoder.push_back("---."); // period
	encoder.push_back("----"); // question mark

	decoder[".-"] = "A";
	decoder["-..."] = "B";
	decoder["-.-."] = "C";
	decoder["-.."] = "D";
	decoder["."] = "E";
	decoder["..-."] = "F";
	decoder["--."] = "G";
	decoder["...."] = "H";
	decoder[".."] = "I";
	decoder[".---"] = "J";
	decoder["-.-"] = "K";
	decoder[".-.."] = "L";
	decoder["--"] = "M";
	decoder["-."] = "N";
	decoder["---"] = "O";
	decoder[".--."] = "P";
	decoder["--.-"] = "Q";
	decoder[".-."] = "R";
	decoder["..."] = "S";
	decoder["-"] = "T";
	decoder["..-"] = "U";
	decoder["...-"] = "V";
	decoder[".--"] = "W";
	decoder["-..-"] = "X";
	decoder["-.--"] = "Y";
	decoder["--.."] = "Z";
	decoder["..--"] = "_";
	decoder[".-.-"] = ",";
	decoder["---."] = ".";
	decoder["----"] = "?";

	lengthTable.assign({2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4,4,4,4,4});
		
	while(getline(cin, input, '\n')) {
		string codeLen = "";
		string morse = "";
		string output = "";
		// Run through all characters of the input
		for (int i = 0; i < (int)input.size(); i++) {
			int c = conv(input[i]);
			codeLen += to_string(lengthTable[c]);
			morse += encoder[c];
		}

		// Decode the morse using the code length in reverse
		int strPtr = 0;
		for (int i = (int)codeLen.size()-1; i >= 0; i--) {
			int len = codeLen[i] - '0';
			string sub = "";
			while (len--) {
				sub += morse[strPtr++];
			}

			// Map the sub string to the correct character
			output += decoder[sub];
		}

		cout << output << endl;
	}
	
	return 0;
}

int conv(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	if (c == '_')
		return 26;
	if (c == ',')
		return 27;
	if (c == '.')
		return 28;
	if (c == '?')
		return 29;

	return 0;
}