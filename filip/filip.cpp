#include <iostream>

using namespace std;

int main(void) {
	int A, B, temp, digit;

	cin >> A >> B;
	temp = 0;
	while (A > 0) {
		digit = A % 10;
		A /= 10;
		temp += digit;
		temp *= 10;
	}
	temp /= 10;
	A = temp;

	temp = 0;
	while (B > 0) {
		digit = B % 10;
		B /= 10;
		temp += digit;
		temp *= 10;
	}
	temp /= 10;
	B = temp;	

	if (A > B) cout << A << endl;
	else cout << B << endl;
	
	return 0;
}