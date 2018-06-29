/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int value, limit, sum = 0;

	while (true)  {
		cin >> value;
		if (cin.eof()) break;
		limit = sqrt(value);
		
		for (int i = 1; i <= limit; i++) {
			if (value % i == 0) {
				sum += i;
				if ((i != value/i) && (value/i != value))
					sum += value/i;
			}
		}
		
		cout << value;
		if (sum == value)
			cout << " perfect" << endl;
		else if (fabs(value-sum) <= 2)
			cout << " almost perfect" << endl;
		else
			cout << " not perfect" << endl;
		
		sum = 0;
	}
	return 0;
}
