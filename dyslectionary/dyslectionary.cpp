#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	string input;

	while (!cin.eof()) {
		int len = 0;
		map<string, string> strMap;
		while (getline(cin, input)) {
			if (input.empty()) {
				break;
			}

			string rvr(input);
			reverse(rvr.begin(), rvr.end());
			strMap[rvr] = input;
			if ((int)input.length() > len)
				len = (int)input.length();
		}

		for (auto it : strMap) {
			printf("%*s\n", len, it.second.c_str());
		}
		if (!cin.eof()) cout << endl;
	}

	return 0;
}