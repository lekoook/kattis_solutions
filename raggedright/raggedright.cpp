#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	string input;
	int longest = 0, score, totalScore = 0, length;
	vector<string> lines;

	while (getline(cin, input, '\n')) {
		length = (int)input.size();
		if (length > longest) longest = length;
		lines.push_back(input);
	}
	
	for (int i = 0; i < (int)lines.size()-1; i++) {
		length = (int)lines[i].size();
		score = pow((longest - length), 2);
		totalScore += score;
	}

	cout << totalScore << endl;
	
	return 0;
}