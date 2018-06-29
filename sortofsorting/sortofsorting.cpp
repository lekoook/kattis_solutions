/******************************************************************************
  CS2040C AY2017/18 Semester 2
  sortofsorting.cpp
  This program sort names according to the first two letters.
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <limits>

#define MAX_NAMES 200

using namespace std;

/* Function Prototypes */
void sortNames(string names[MAX_NAMES], int numNames);

int main(void) {
	int numNames;
	string unsortedNames[MAX_NAMES];

	cin >> numNames;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// Loop till the number of names <= 0
	while (numNames > 0) {
		// Get the name in each line
		for (int i = 0; i < numNames; i++) {
			getline(cin, unsortedNames[i]);
		}
		// Sort the array of names accordingly
		sortNames(unsortedNames, numNames);
		// Output the sorted names
		for (int i = 0; i < numNames; i++) {
			cout << unsortedNames[i] << endl;
		}

		cin >> numNames;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;
}

// Bubble sort
void sortNames(string names[MAX_NAMES], int numNames) {
	string tempName;
	
	for (int i = numNames-2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			// Check the first character
			if (names[j][0] > names[j+1][0]) {
				// Swap the names
				tempName = names[j];
				names[j] = names[j+1];
				names[j+1] = tempName;
			}
			// If the first characters are equal, check the second
			else if (names[j][0] == names[j+1][0]) {
				if (names[j][1] > names[j+1][1]) {
					// Swap
					tempName = names[j];
					names[j] = names[j+1];
					names[j+1] = tempName;
				}
			}
		}
	}
}
