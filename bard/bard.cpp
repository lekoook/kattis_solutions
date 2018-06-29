#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	int villagers, evenings, attendance, person, songNo = 0;
	vector< set<int> > village;

	cin >> villagers >> evenings;
	village.assign(villagers, set<int>());

	while (evenings--) {
		cin >> attendance;
		bool hasBard = false;
		vector<int> appear;
		set<int> nightSongs;
		
		for (int i = 0; i < attendance; i++) {
			cin >> person;
			if (person == 1) hasBard = true;

			appear.push_back(person);
			
			for (auto it : village[person-1])
				nightSongs.insert(it);
		}

		if (hasBard) {
			songNo++;
			for (auto it : appear)
				village[it-1].insert(songNo);
		}
		else {
			for (auto it : appear)
				village[it-1] = nightSongs;
		}
	}

	// Print
	for (int i = 0; i < villagers; i++) {
		if (village[i].size() == village[0].size()) cout << i+1 << endl;
	}
	
	return 0;
}