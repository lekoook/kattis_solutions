/******************************************************************************
  CS2040C AY2017/18 Semester 2
  evenup.cpp
  This program computes the number of cards left after removing adjacent cards
  with even sum.
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

/* Function Prototypes */

int main(void) {
	stack<int> stack1;
	int num, value;

	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> value;

		if (stack1.empty()) {
			stack1.push(value);
		}
		else {
			if ((value + stack1.top()) % 2 == 0) {
				stack1.pop();
			}
			else {
				stack1.push(value);
			}
		}
	}

	cout << stack1.size() << endl;


	return 0;
}
