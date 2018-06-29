/******************************************************************************
CS2040C AY2017/18 __
__.cpp
This program __
Lee Kok Teng
C04
***************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define MAX_SIZE 30
#define MAX_TESTS 10
#define MIN -1000000
#define MAX 1000000

using namespace std;

/* Function Prototypes */
int getMin(int *data, int size);
int getMax(int *data, int size);
int getRange(int *data, int size);

int main(void) {
	int *dataList[MAX_TESTS];
	int dataListSizes[MAX_TESTS];
	int testIdx = 0;
	string line;

	while (getline(cin, line)) {
		if (line.empty()) {
			break;
		}
		stringstream lineStream(line);
		int n;
		lineStream >> n;
		int intCount = n;
		dataListSizes[testIdx] = n;
		int *data = new int[intCount];

		for (int i = 0; i < intCount; i++) {
			lineStream >> n;
			data[i] = n;
		}
		
		dataList[testIdx++] = data;
	}


	for (int i = 0; i < testIdx; i++) {
		cout << "Case " << i+1 << ": ";
		cout << getMin(dataList[i], dataListSizes[i]) << " ";
		cout << getMax(dataList[i], dataListSizes[i]) << " ";
		cout << getRange(dataList[i], dataListSizes[i]) << endl;
	}
	return 0;
}

int getMin(int *data, int size) {
	int min = MAX;
	for (int i = 0; i < size; i++) {
		if (*(data + i) < min) {
			min = *(data + i);
		}
	}

	return min;
}

int getMax(int *data, int size) {
	int max = MIN;
	for (int i = 0; i < size; i++) {
		if (*(data + i) > max) {
			max = *(data + i);
		}
	}

	return max;
}

int getRange(int *data, int size) {
	int min, max;

	min = getMin(data, size);
	max = getMax(data, size);

	return max - min;
}
