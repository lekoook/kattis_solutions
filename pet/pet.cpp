#include <iostream>

using namespace std;

int main(void) {
	int score = 0, num, temp;
	int a, b, c, d;

	for (int i = 1; i <= 5; i++) {
		cin >> a >> b >> c >> d;
		temp = a + b + c + d;
		if (temp > score) {
			score = temp;
			num = i;
		}
	}	

	cout << num << " " << score << endl;
	return 0;
}