/******************************************************************************
  CS2040C AY2017/18 Semester 2
  sidewayssorting.cpp
  This program sorts a given array of string of characters lexicographically 
  from left to right.
  Lee Kok Teng
  C04
 ****************************************************************************/

#include <iostream>
#include <limits>
#include <cctype>

#define MAX 15

using namespace std;

/* Function Prototypes */
void mergeSort(string *line, int low, int high);
void merge(string *line, int low, int mid, int high);

int main(void) {
	int r, c;
	string lines[MAX];

	// Read number of lines and characters
	cin >> r >> c;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while ((r > 0) && (c > 0)) {
		// Read strings input
		for (int lineIdx = 0; lineIdx < r; lineIdx++) {
			getline(cin, lines[lineIdx]);
		}
		
		// Sort the strings accordingly (Merge sort)
		for (int lineIdx = 0; lineIdx < r; lineIdx++) {
			mergeSort(&lines[lineIdx], 0, c-1);	
		}

		// Output the sorted strings
		for (int lineIdx = 0; lineIdx < r; lineIdx++) {
			cout << lines[lineIdx] << endl;
		}
		cout << endl;

		// Read number of lines and characters again
		cin >> r >> c;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return 0;
}

void mergeSort(string *line, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(line, low, mid);
		mergeSort(line, mid+1, high);
		merge(line, low, mid, high);
	}

	return;
}

void merge(string *line, int low, int mid, int high) {
	int N = high - low + 1;
	char *tempArray = new char[N];
	int left = low, right = mid+1, arrIdx = 0;

	while ((left <= mid) && (right <= high)) {
		tempArray[arrIdx++] = ((tolower(line->at(left)) <= tolower(line->at(right))) ? line->at(left++) : line->at(right++));
	}
	while (left <= mid) tempArray[arrIdx++] = line->at(left++);
	while (right <= high) tempArray[arrIdx++] = line->at(right++);

	for (int i = 0; i < N; i++) {
		line->at(low+i) = tempArray[i];
	}	

	delete[] tempArray;

	return;
}
