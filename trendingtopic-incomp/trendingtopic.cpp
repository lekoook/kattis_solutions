/******************************************************************************
  CS2040C AY2017/18 Semester 2
  trendingtopic.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string input;
	string word;

	getline(cin, input);
	while (!input.empty()) {
		if (input == "<text>") {
			getline(cin, input);
			while (input != "</text>") {
				istringstream inputStream(input);
				while (!inputStream.eof()) {
					inputStream >> word;
					if ((int)word.size() < 4)
						continue;


				}

				getline(cin, input);
			}
		}
		else {
		
		}
	}

	return 0;
}
