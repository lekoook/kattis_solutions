/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

void processDigits(int countArray[10], int num);

int main(void) {
	int orders, addresses, num, first, last, interval;
	string street, dummy;

	cin >> orders; cin.ignore(10000, '\n');
	for (int i = 0; i < orders; i++) {
		// Read in prerequisite info
		getline(cin, street);
		cin >> addresses;
		getline(cin, dummy);
		int count = addresses;
		int digitsCount = 0;
		int countArray[10] = { 0 };

		// Read and process all the house numbers
		while (addresses) {
			// This is the range of digits
			if (cin.peek() == '+') {
				// Throw away the plus sign
				getline(cin, dummy, ' ');
				// Process all house numbers within the range
				cin >> first >> last >> interval; cin.ignore(10000, '\n');
				while (first <= last) {
					processDigits(countArray, first);
					first += interval;
					addresses--;
				}
			}
			else {
				// Process all digits of house number
				cin >> num; cin.ignore(10000, '\n');
				processDigits(countArray, num);

				addresses--;
			}
		}

		// Print out required output
		cout << street << endl;
		if (count > 1) {
			cout << count << " addresses" << endl;
		}
		else {
			cout << count << " address" << endl;
		}

		for (int j = 0; j < 10; j++) {
			cout << "Make " << countArray[j] << " digit " << j << endl;
			digitsCount += countArray[j];
		}

		if (digitsCount > 1) {
			cout << "In total " << digitsCount << " digits" << endl;
		}
		else {
			cout << "In total " << digitsCount << " digit" << endl;
		}
	}

	return 0;
}

void processDigits(int countArray[10], int num) {
	int digit;
	while (num) {
		digit = num % 10;
		countArray[digit]++;
		num /= 10;
	}
}
