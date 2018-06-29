#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute(vector<char> answer);
int setPrecedence(char opt);

void printO(vector<int> &arr) {
	cout << "arr order is:";
	for (auto it : arr) {
		cout << " " << it;
	}
	cout << endl;	
}

int eval(int first, int second, char opt);

int main(void) {
	char operators[4] = { '*', '+', '-', '/' };
	int cases, N;

	cin >> cases;
	while (cases--) {
		vector<char> answer;
		int output = 0;
		bool found = false;
		cin >> N;
		
		// Three nested loops to cycle through all possible operators
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					answer.clear();
					answer.push_back(operators[i]);
					answer.push_back(operators[j]);
					answer.push_back(operators[k]);
					output = compute(answer);

					if (output == N) {
						found = true;
					}

					if (found) break;
				}
				if (found) break;
			}
			if (found) break;
		}
		
		if (found) {
			cout << "4";
			for (int i = 0; i < 3; i++)
				cout << " " << answer[i] << " 4";

			cout << " = " << N << endl;
		}
		else {
			cout << "no solution" << endl;
		}
	}

	return 0;
}

int compute(vector<char> answer) {
	vector<int> arr {4,4,4,4};
	
	for (int i = 0; i < (int)answer.size(); i++) {
		if (answer[i] == '/' || answer[i] == '*') {
			arr[i] = eval(arr[i], arr[i+1], answer[i]);
			arr.erase(arr.begin() + i + 1);
			answer.erase(answer.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < (int)answer.size(); i++) {
		arr[i] = eval(arr[i], arr[i+1], answer[i]);
		arr.erase(arr.begin() + i + 1);
		answer.erase(answer.begin() + i);
		i--;
	}
	return arr[0];
}

int eval(int first, int second, char opt) {
	switch(opt) {
		case '*': 
			return first * second;
		case '+': 
			return first + second;
		case '-': 
			return first - second;
		default: 
			return first / second;
	}

	return 0;
}