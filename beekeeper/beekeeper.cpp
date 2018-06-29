/******************************************************************************
  CS2040C AY2017/18 Semester 2
  .cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

int main(void) {
	int cases, count, maxCount;
	string word, maxWord;

	cin >> cases;
	while (cases > 0) {
		maxCount = 0;
		maxWord = "";
		for (int i = 0; i < cases; i++) {
			cin >> word;
			count = 0;
			for (int j = 0; j < (int)word.size()-1; j++) {
				switch(word[j]) {
					case 'a': 
					case 'e': 
					case 'i': 
					case 'o': 
					case 'u':
					case 'y':
						if (word[j+1] == word[j]) {
							count++;
							j++;
						}
					default:
						continue;
				}
			}
			if (count > maxCount) {
				maxCount = count;
				maxWord = word;
			}
		}

		cout << maxWord << endl;

		cin >> cases;
	}

	return 0;
}
