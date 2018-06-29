/******************************************************************************
  CS2040C AY2017/18 Semester 2
  beijutext.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <deque>
#include <iterator>

using namespace std;

void printD(deque<char> output) {
	while (!output.empty()) {
		cout << output.front();
		output.pop_front();
	}
	cout << endl;
}

int main(void) {
	string input;
	deque<char> output;
	auto textItr = output.end();

	getline(cin, input);
	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] == '[') {
			textItr = output.begin();
		}
		else if (input[i] == ']') {
			textItr = output.end();
		}
		else {
			textItr = output.insert(textItr, input[i]);
			advance(textItr, 1);
		}
	}
	printD(output);

	return 0;
}
