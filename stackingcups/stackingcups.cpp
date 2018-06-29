/******************************************************************************
  CS2040C AY2017/18 Semester 2
  stackingcups.cpp
  This program arranges the cups from smallest to largest radius
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>

#define MAX_CUPS 20

using namespace std;

// Structures
typedef struct {
	int size;
	string colour;
} cupType;

/* Function Prototypes */

int main(void) {
	int numCups;
	string line;
	cupType cups[MAX_CUPS], tempCup;

	cin >> numCups;
	getline(cin, line);

	for (int i = 0; i < numCups; i++) {
		getline(cin, line);
		istringstream lineStream (line);

		if (isdigit(lineStream.peek())) {
			lineStream >> cups[i].size;
			cups[i].size /= 2;
			lineStream >> cups[i].colour;
		}
		else {
			lineStream >> cups[i].colour;
			lineStream >> cups[i].size;
		}
	}
	
	// Bubble sort
	for (int i = numCups-2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (cups[j].size > cups[j+1].size) {
				// Swap the cups
				tempCup = cups[j];
				cups[j] = cups[j+1];
				cups[j+1] = tempCup;
			}
		}
	}

	for (int i = 0; i < numCups; i++) {
		cout << cups[i].colour << endl;
	}

	return 0;
}


