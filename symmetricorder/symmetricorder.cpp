/******************************************************************************
  CS2040C AY2017/18 Semester 2
  symmetricorder.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	stack<string> stack1;
	stack<string> stack2;
	int num, count = 1;
	string name;

	cin >> num;
	while (num > 0) {
		// Read in all names and push names into stack1 and stack2
		// alternatively beginning with stack1
		for (int i = 1; i <= num; i++) {
			cin >> name;

			if (i % 2 != 0)
				stack1.push(name);
			else
				stack2.push(name);
		}
		
		// Pop and push names from stack1 into stack2 to form the ordered 
		// list
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}

		// Print the output
		cout << "SET " << count++ << endl;
		while (!stack2.empty()) {
			cout << stack2.top() << endl;
			stack2.pop();
		}

		cin >> num;
	}

	return 0;
}
