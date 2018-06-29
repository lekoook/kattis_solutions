#include <iostream>

using namespace std;

int main(void) {
	int crosses, switches;
	
	cin >> crosses >> switches;

	if (switches % 2 == 0) cout << "possible" << endl;
	else cout << "impossible" << endl;
		
		
	return 0;
}