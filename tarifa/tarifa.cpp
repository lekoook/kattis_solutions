/******************************************************************************
  CS2040C AY2017/18 Semester 2
  tarifa.cpp
  This program 
  Lee Kok Teng
  C04
  ****************************************************************************/

#include <iostream>

using namespace std;

int main(void) {
	int X, N, P;
	int usage = 0;

	cin >> X >> N;
	for (int i = 0; i < N; i++) {
		cin >> P;
		usage += P;
	}	
	
	cout << (N+1)*X-usage << endl;
	return 0;
}
