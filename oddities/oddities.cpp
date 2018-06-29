#include <iostream>

using namespace std;

int main(void) {
	int n, input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input % 2 == 0)
			cout << input << " is even" << endl;
		else
			cout << input << " is odd" << endl;
	}
	return 0;
}