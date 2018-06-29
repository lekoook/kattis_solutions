#include <iostream>

using namespace std;

int main(void) {
	int cases, b;
	float p;

	cin >> cases;
	while (cases--) {
		cin >> b >> p;
		float diff = 60.0 / p;
		float bpm = diff * b;
		printf("%.4f %.4f %.4f\n", bpm-diff, bpm, bpm+diff);
	}
	return 0;
}
