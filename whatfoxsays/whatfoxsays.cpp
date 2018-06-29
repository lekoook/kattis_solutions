/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int cases;
	string inputLine;
	unordered_set<string> soundMap;
	
	cin >> cases;
	cin.get();
	while (cases--) {
		getline(cin, inputLine);
		istringstream inputStream(inputLine);
	
		// Save the animal sounds to a Hash map first
		while (true) {
			string animalSound, animalLine;
			getline(cin, animalLine);
			if (animalLine == "what does the fox say?")
				break;
			
			istringstream animalStream(animalLine);
			animalStream >> animalSound;
			animalStream >> animalSound;
			animalStream >> animalSound;
			soundMap.insert(animalSound);
		}

		// Cross out unwanted sounds
		string sound;
		while (getline(inputStream, sound, ' ')) {
			if (soundMap.count(sound)) continue;
			cout << sound << " ";
		}
		cout << endl;
	}
	
	return 0;

}
