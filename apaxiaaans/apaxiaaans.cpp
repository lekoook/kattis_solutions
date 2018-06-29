/******************************************************************************
  CS2040C AY2017/18 Semester 2
  apaxiaaans.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

int main(void) {
	string word;
	char val = '-';
	
	cin >> word;
	for (int i = 0; i < (int)word.size(); i++) {
		if (word[i] != val) {
			cout << word[i];
			val = word[i];
		}
	}
	
	cout << endl;
	
	return 0;
}
