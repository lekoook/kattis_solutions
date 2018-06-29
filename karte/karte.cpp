#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main(void) {
	string input;
	char suit;
	int X, Y, num;
	unordered_map<char, set<int> > check;

	getline(cin, input);

	for (int i = 0; i < input.size(); i+=3) {
		suit = input[i];
		X = input[i+1] - '0';
		Y = input[i+2] - '0';
		num = Y + (X * 10);
		
		if (check[suit].count(num) != 0) {
			cout << "GRESKA" << endl;
			return 0;
		}
		check[suit].insert(num);
	}

	cout << 13-(int)check['P'].size() << " " << 13-(int)check['K'].size() << " " << 13-(int)check['H'].size() << " " << 13-(int)check['T'].size() << endl;

	return 0;
}