#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int N, W, H;
	double diagonal, input;

	cin >> N >> W >> H;
	diagonal = sqrt((double)(pow(W,2)) + (double)(pow(H,2)));

	while (N--) {
		cin >> input;
		if (input > diagonal) 
			cout << "NE" << endl;
		else
			cout << "DA" << endl;
	}
	return 0;
}