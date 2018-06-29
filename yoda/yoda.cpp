/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main(void) {
	stack<long> num1;
	stack<long> num2;
	long value1, value2, res1 = 0, res2 = 0;

	cin >> value1;
	cin >> value2;

	while ((value1 > 0) || (value2 > 0)) {
		if ((value1 % 10) > (value2 % 10)) {
			num1.push(value1 % 10);
		}
		else if ((value2 % 10) > (value1 % 10)) {
			num2.push(value2 % 10);
		}
		else {
			num1.push(value1 % 10);
			num2.push(value2 % 10);
		}

		value1 /= 10;
		value2 /= 10;
	}

	if (num1.empty()) {
		cout << "YODA" << endl;
	}
	else {
		while (!num1.empty()) {
			res1 += (num1.top() * (pow(10, (int)num1.size()-1)));
			num1.pop();
		}
		cout << res1 << endl;
	}

	if (num2.empty()) {
		cout << "YODA" << endl;
	}
	else {
		while (!num2.empty()) {
			res2 += (num2.top() * (pow(10, (int)num2.size()-1)));
			num2.pop();
		}
		cout << res2 << endl;
	}

	return 0;
}
