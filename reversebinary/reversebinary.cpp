#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int input, remain, output = 0;
	vector<int> binary;
	
	cin >> input;

	while (input) {
		remain = input % 2;
		binary.push_back(remain);
		input /= 2;
	}

	int pos = 0;
	for (int i = (int)binary.size()-1; i >= 0; i--) {
		output += pow(2, pos++) * binary[i]; 
	}

	cout << output << endl;
}