/******************************************************************************
CS2040C AY2017/18 Semester 2
autori.cpp
This program converts the long variation of naming convention to shorter one.
Lee Kok Teng
C04
******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* Function Prototypes */

int main(void) {
	string name;
	string shortName;

	cin >> name;
	
	for (int i = 0; i < (int)name.size(); i++) {
		if (isupper(name[i])) {
			shortName.append(1, name[i]);
		}
	}

	cout << shortName << endl;

	return 0;
}


