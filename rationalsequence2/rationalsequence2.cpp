/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	vector<char> sequence;
	int cases, p, q;
	bool isLeft;

	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		int index = 1;
		cin >> p;

		// Read the numerator and denominator
		cin >> p;
		cin.ignore(1, '/');
		cin >> q;

		// While loop with the condition that current child is not root
		while ((p > 1) || (q > 1)) {
			// Determine if the input is a left or right child
			if (p < q) {
				isLeft = true;
				sequence.push_back('L');
			}
			else {
				isLeft = false;
				sequence.push_back('R');
			}

			// Depending if the current child is left or right, compute the
			// p and q of its parent
			if (isLeft) {
				q = q - p;
			}
			else {
				p = p - q;
			}
		}

		// Read the sequence of left and right childs from the root to 
		// determine the index of the input in the binary tree
		while (!sequence.empty()) {
			if (sequence.back() == 'L') {
				index *= 2;
			}
			else {
				index = (index * 2) + 1;
			}
			sequence.pop_back();
		}

		// Output the index value
		cout << i << " " << index << endl;
	}

	return 0;
}
