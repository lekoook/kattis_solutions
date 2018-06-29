#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(void) {
	string input;
	int cases, diff, start, next;
	long double circum = M_PI * 60.0;
	long double feetPerUnit = circum / 28.0;

	cin >> cases; cin.ignore(1000, '\n');
	for (int j = 0; j < cases; j++) {
		int totalDistance = 0;
		int pickups = 0;
		getline(cin, input, '\n');
		
		if (input[0] == ' ') input[0] = 'Z' + 1;
		if (input[0] == '\'') input[0] = 'Z' + 2;
		start = input[0] - 'A';
		pickups++;
		for (int i = 1; i < (int)input.size(); i++) {

			if (input[i] == ' ') input[i] = 'Z' + 1;
			if (input[i] == '\'') input[i] = 'Z' + 2;

			next = input[i] - 'A';

			if (next >= start) {
				diff = next - start;
			}
			else {
				diff = start - next;
			}
			if (diff > 14) {
				diff = 14 - (diff % 14);
			}
			
			totalDistance += diff;
			pickups++;
			start = next;
		}
		long double ans = ((long double)totalDistance * feetPerUnit) / 15.0;
		ans += (long double)pickups;
		printf("%0.10LF\n", ans);
	}

	return 0;
}