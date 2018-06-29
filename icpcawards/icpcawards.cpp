#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
	int teams;
	int firstCounter = 0, secondCounter = 0, thirdCounter = 0;
	string uni, name;
	unordered_set<string> appeared;
	vector<string> winners;

	cin >> teams; cin.ignore(1000, '\n');
	while (teams--) {
		cin >> uni >> name;
		if (appeared.count(uni) > 0) continue;
		appeared.insert(uni);

		string full = uni + " " + name;
		if (firstCounter < 4) {
			winners.push_back(full);
			firstCounter++;
		}
		else if (secondCounter < 4) {
			winners.push_back(full);
			secondCounter++;
		}
		else if (thirdCounter < 4) {
			winners.push_back(full);
			thirdCounter++;
		}
		else {
			break;
		}
	}

	for (auto it : winners) cout << it << endl;
	
	return 0;
}