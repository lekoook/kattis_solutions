/******************************************************************************
  CS2040C AY2017/18 Semester 2
  backspace.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	int queueSize;
	string input;
	deque<char> myQueue;

	getline(cin, input);
	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] == '<') {
			if (!myQueue.empty())
				myQueue.pop_back();
		}
		else {
			myQueue.push_back(input[i]);
		}
	}
	queueSize = (int) myQueue.size();
	for (int i = 0; i < queueSize; i++) {
		cout << myQueue.front();
		myQueue.pop_front();
	}
	cout << endl;

	return 0;
}
