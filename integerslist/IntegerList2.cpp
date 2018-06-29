/******************************************************************************
  CS2040C AY2017/18 Semester 2
  integerslist.cpp
  This program returns the output from BAPC function 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>
#include <limits>
#include <list>

using namespace std;

/* Function Prototypes */

int main(void) {
	int testCases, numElements, rCounter = 0, value;
	string prog;
	bool reverse = false, empty = false;
	list<int> intList;

	cin >> testCases;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int test = 1; test <= testCases; test++) {
		rCounter = 0;
		reverse = false;
		empty = false;
		// Read the BAPC function string, number of elements and given array
		cin >> prog;
		cin >> numElements;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		scanf("[");
		int j;
		for (j = 0; j < numElements-1; j++) {
			cin >> value;
			intList.push_back(value);
			scanf(",");
		}
		if(numElements) { //Added this.
			cin >> value;
			intList.push_back(value);
		}
		scanf("]");

		//cout << "DBG --> " << endl;
		//for (auto v : intList) cout<<v<<" ";
		//cout << endl;

		// Process the array with the given function string
		for (int i = 0; i < (int)prog.size(); i++) {
			if (prog[i] == 'R') {
				// Switch the reverse flag whenever a 'R' is encountered
				rCounter++;
				if (reverse == true) reverse = false;
				else reverse = true;
			}
			else if (prog[i] == 'D') {
				// Check if the container is empty
				if (numElements == 0) {
					empty = true;
					break;
				}
				// Remove the last element if reverse flag is true
				// Otherwise remove the first element
				if (reverse) intList.pop_back();
				else intList.pop_front();
				numElements--;
			}
		}

		if (empty) {
			cout << "error" << endl;
			continue;
		}

		// Determine if the output array should be reversed based on 
		// the number of 'R's encountered
		if ((rCounter % 2) != 0) {
			intList.reverse();
		}

		// Output the final array
		cout << "[";
		for (int i = 0; i < numElements; i++) {
			cout << intList.front();
			intList.pop_front();
			if (i != numElements-1) cout << ",";
		}
		cout << "]" << endl;
	}

	return 0;
}
