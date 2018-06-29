#include <iostream>

using namespace std;

int main(void) {
	string input;
	string ref = "PER";
	int refCount = 0, daysCount = 0;

	cin >> input;
	for (int i = 0; i < (int)input.size(); i++) {
		if (input[i] != ref[refCount++]) daysCount++;
		refCount = refCount % 3;
	}	

	cout << daysCount << endl;
	
	return 0;
}