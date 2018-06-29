#include <iostream>
#include <vector>

#define LIMIT 201

using namespace std;

void explore(vector< vector<int> > &keypad, vector<bool> &possibilities);
void recurse(int currentDigit, vector<int> &currentString, vector< vector<int> > &keypad, vector<bool> &possibilities);
void processString(vector<int> &currentString, vector<bool> &possibilities);
int getClosest(int input, vector<bool> &possibilities);

int main(void) {
	vector<bool> possibilities;
	vector< vector<int> > keypad;
	int cases;

	cin >> cases;

	// Model the keypad as a directed graph
	keypad.assign(10, vector<int>(0));
	// Assign the neighbours of each key given the constraints
	keypad[1].push_back(2);
	keypad[1].push_back(4);
	keypad[2].push_back(3);
	keypad[2].push_back(5);
	keypad[3].push_back(6);
	keypad[4].push_back(5);
	keypad[4].push_back(7);
	keypad[5].push_back(6);
	keypad[5].push_back(8);
	keypad[6].push_back(9);
	keypad[7].push_back(8);
	keypad[8].push_back(9);
	keypad[8].push_back(0);
	
	// Generate all the possible values into an array using the graph model
	possibilities.assign(LIMIT, false);
	explore(keypad, possibilities);
/*
	// Print all possibile numbers
	for (int i = 0; i < (int)possibilities.size(); i++) {
		if (possibilities[i])
			cout << i << endl;
	}
*/
	// For each case, we determine the closest possible value in the
	// 'possibilities' array
	int closest, input;
	while (cases--) {
		cin >> input;
		closest = getClosest(input, possibilities);
		cout << closest << endl;
	}
	
	return 0;
}

void explore(vector< vector<int> > &keypad, vector<bool> &possibilities) {
	vector<int> currentString;

	// Go through all the individual keys
	for (int i = 0; i < 10; i++) {
		recurse(i, currentString, keypad, possibilities);
	}
}

void recurse(int currentDigit, vector<int> &currentString, vector< vector<int> > &keypad, vector<bool> &possibilities) {
	// Add the current digit into the string
	currentString.push_back(currentDigit);
	// Go through all the neighbours of the current digit
	for (int i = 0; i < (int)keypad[currentDigit].size(); i++) {
		recurse(keypad[currentDigit][i], currentString, keypad, possibilities);
	}
	// Once the end of a depth first search is reached, we process the
	// current string of digits
	if ((int)keypad[currentDigit].size() == 0)
		processString(currentString, possibilities);

	// Remove current digit from the current string
	currentString.pop_back();
}

// Given a string of digits, we process this string by taking the first digit
// as the head digit. We then take this head digit and run through all
// possible permutations with the remaining digits. Cases that fits the
// problem requirements will be added into the possible numbers
void processString(vector<int> &currentString, vector<bool> &possibilities) {
	if ((int)currentString.size() <= 0) return;

//	cout << "processing ";
//	for (auto it : currentString) cout << it << " ";
//	cout << endl;

	int headDigit = currentString[0];
	possibilities[headDigit] = true;

	// Run through all possible 2-digits permutations including repeated digits
	int twoDigitsRepeat = (headDigit * 10) + headDigit;
	possibilities[twoDigitsRepeat] = true;
	for (int i = 1; i < (int)currentString.size(); i++) {
		int num = (headDigit * 10) + currentString[i];
//		cout << "adding " << num << endl;
		if (num > 0 && num <= 200)
			possibilities[num] = true;
	}

	// Run through all possible 3-digits permutations including repeated digits
	// ALL digits repeated
	int threeDigitsRepeat = (headDigit * 100) + (headDigit * 10) + headDigit;
	if (threeDigitsRepeat > 0 && threeDigitsRepeat <= 200)
		possibilities[threeDigitsRepeat] = true;

	for (int i = 1; i < (int)currentString.size()-1; i++) {
		int firstNextDigit = currentString[i];
		for (int j = i+1; j < (int)currentString.size(); j++) {
			int secondNextDigit = currentString[j];
			
			// The head digit concatenate with the next two digits
			int num = (headDigit * 100) + (firstNextDigit * 10) + secondNextDigit;
			// Head digit repeated twice first, followed by next first digit
			int nextFirst = (headDigit * 100) + (headDigit * 10) + firstNextDigit;
			// Head digit repeated twice first, followed by next second digit
			int nextSecond = (headDigit * 100) + (headDigit * 10) + secondNextDigit;
			// Head digit once, followed by next first digit repeated twice
			int nextFirstTwice = (headDigit * 100) + (firstNextDigit * 10) + firstNextDigit;
			// Head digit once, followed by next second digit repeated twice
			int nextSecondTwice = (headDigit * 100) + (secondNextDigit * 10) + secondNextDigit;
			//cout << "adding " << num << endl;
			if (num > 0 && num <= 200)
				possibilities[num] = true;
			if (nextFirst > 0 && nextFirst <= 200)
				possibilities[nextFirst] = true;
			if (nextSecond > 0 && nextSecond <= 200)
				possibilities[nextSecond] = true;
			if (nextFirstTwice > 0 && nextFirstTwice <= 200)
				possibilities[nextFirstTwice] = true;
			if (nextSecondTwice > 0 && nextSecondTwice <= 200)
				possibilities[nextSecondTwice] = true;			
		}
	}
	
	// WRONG, did not take into account numbers like 120
	for (int i = 1; i <(int)currentString.size()-1; i++) {
		// The head digit concatenate with the next two digits
		int num = (headDigit * 100) + (currentString[i] * 10) + (currentString[i+1]);
		// Head digit repeated twice first, followed by next first digit
		int nextFirst = (headDigit * 100) + (headDigit * 10) + currentString[i];
		// Head digit repeated twice first, followed by next second digit
		int nextSecond = (headDigit * 100) + (headDigit * 10) + currentString[i+1];
		// Head digit once, followed by next first digit repeated twice
		int nextFirstTwice = (headDigit * 100) + (currentString[i] * 10) + currentString[i];
		// Head digit once, followed by next second digit repeated twice
		int nextSecondTwice = (headDigit * 100) + (currentString[i+1] * 10) + currentString[i+1];
//		cout << "adding " << num << endl;
		if (num > 0 && num <= 200)
			possibilities[num] = true;
		if (nextFirst > 0 && nextFirst <= 200)
			possibilities[nextFirst] = true;
		if (nextSecond > 0 && nextSecond <= 200)
			possibilities[nextSecond] = true;
		if (nextFirstTwice > 0 && nextFirstTwice <= 200)
			possibilities[nextFirstTwice] = true;
		if (nextSecondTwice > 0 && nextSecondTwice <= 200)
			possibilities[nextSecondTwice] = true;
	}
}

int getClosest(int input, vector<bool> &possibilities) {
	bool result = false;
	int change = 0, prev = 0;
	result = possibilities[input];
	while (!result) {
		if (change != prev && (input-change) >= 0) {
			prev = change;
			result = possibilities[input - change];
		}
		else {
			change++;
			result = possibilities[input + change];
		}
	}
	if (change == prev)
		return input - change;
	else
		return input + change;
}