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
	int A, B, words;
	unordered_set<string> essay;

	srand(time(0));
	cin >> A >> B;

	if (A > (B/2)) words = A;
	else words = B/2;

	for (int i = 0; i < words; i++) {
		string gen;
		int letters = (rand() % 15) + 1;
		for (int i = 0; i < letters; i++) {
			gen += (rand() % 26) + 'a';
		}
		
		if (essay.count(gen) == 0) {
			cout << gen << " ";
			essay.insert(gen);
		}
		else {
			words--;
		}
	}
	cout << endl;

	return 0;
}
