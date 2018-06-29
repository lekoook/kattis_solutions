/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

/* Function Prototypes */

int main(void) {
	string word;

	cin >> word;
	if (word.find("ss") == string::npos) 
		cout << "no hiss" << endl;
	else 
		cout << "hiss" << endl;

	return 0;
}
