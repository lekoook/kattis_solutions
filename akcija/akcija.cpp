/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int books, value, total = 0;
	vector<int> bookV;

	cin >> books;
	for (int i = 0; i < books; i++) {
		cin >> value;
		bookV.push_back(value);
	}

	sort(bookV.begin(), bookV.end(), greater<int>());
	
	for (int i = 0; i < books; i++) {
		if ((i+1) % 3 == 0) {
			bookV.pop_back();
			continue;
		}
		total += bookV[i];
		bookV.pop_back();
	}

	cout << total << endl;

	return 0;
}
