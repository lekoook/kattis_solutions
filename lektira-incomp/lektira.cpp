// WRONG
// ANSWER: Try all permutations of three separate chopped strings

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	string input, word1, word2, word3;
	int pos;
	char smallest;

	cin >> input;

	// First run
	int firstIndex;
	smallest = '{';
	// Find the smallest character first and its position
	for (firstIndex = 0; firstIndex < (int)input.size(); firstIndex++) {
		if (input[firstIndex] < smallest) {
			smallest = input[firstIndex];
			pos = firstIndex; 
		}
	}
	firstIndex = pos;
	word1 = input.substr(0, pos+1); // Extract the substring to the smallest character
	// Second run
	int secondIndex;
	smallest = '{';
	for (secondIndex = firstIndex+1; secondIndex < (int)input.size(); secondIndex++) {
		if (input[secondIndex] < smallest) {
			smallest = input[secondIndex];
			pos = secondIndex; 
		}
	}
	secondIndex = pos;
	word2 = input.substr(firstIndex+1, (pos-firstIndex));
	// Third run
	word3 = input.substr(secondIndex+1, ((int)input.size()-1-secondIndex));

	reverse(word1.begin(), word1.end());
	reverse(word2.begin(), word2.end());
	reverse(word3.begin(), word3.end());

	cout << word1 << word2 << word3 << endl;

	return 0;
}