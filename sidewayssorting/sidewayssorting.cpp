/******************************************************************************
  CS2040C AY2017/18 Semester 2
  sidewayssorting.cpp
  This program sorts a given array of string of characters lexicographically 
  from left to right.
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>
#include <limits>
#include <cctype>

#define MAX 15

using namespace std;

/* Function Prototypes */

int main(void) {
	int r, c;
	string lines[MAX];
	char tempChar;

	// Read number of lines and characters
	cin >> r >> c;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while ((r > 0) && (c > 0)) {
		// Read strings input
		for (int lineIdx = 0; lineIdx < r; lineIdx++) {
			getline(cin, lines[lineIdx]);
		}

		// Sort the strings accordingly (Bubble sort)
		for (int charIdx = c-2; charIdx >= 0; charIdx--) {
			for (int i = 0; i <= charIdx; i++) {
				for (int lineIdx = 0; lineIdx < r; lineIdx++) {
					if ((tolower(lines[lineIdx].at(i))) > 
						(tolower(lines[lineIdx].at(i+1)))) {
						// Swap the vertical column
						for (int j = 0; j < r; j++) {
							tempChar = lines[j][i];
							lines[j][i] = lines[j][i+1];
							lines[j][i+1] = tempChar;
						}
						break;
					}
					else if ((tolower(lines[lineIdx].at(i))) == 
						(tolower(lines[lineIdx].at(i+1)))) continue;
					else break;
				}
			}
		}

		// Output the sorted strings
		for (int lineIdx = 0; lineIdx < r; lineIdx++) {
			cout << lines[lineIdx] << endl;
		}

		// Read number of lines and characters again
		cin >> r >> c;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;
}
