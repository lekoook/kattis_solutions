#include <iostream>

using namespace std;

int main(void) {
	int num1, num2, result;

	cin >> num1 >> num2;
	
	if ((num1 == 0) && (num2 == 0)) {
		cout << "Not a moose" << endl;
	}
	else if (num1 == num2) {
		cout << "Even " << num1*2 << endl;
	}
	else {
		if (num1 > num2) {
			cout << "Odd " << num1*2 << endl;
		}
		else {
			cout << "Odd " << num2*2 << endl;
		}
	}

	return 0;
}
