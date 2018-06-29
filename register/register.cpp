/******************************************************************************
  CS2040C AY2017/18 Semester 2
  register.cpp
  This program computes the maximum possible increment before the computer blow
  Lee Kok Teng
  C04
 *****************************************************************************/

#include <iostream>

#define REG_SIZE 8

using namespace std;

/* Function Prototypes */
int incrementReg(int registers[REG_SIZE], int sizes[REG_SIZE], int index);

int main(void) {
	int registers[REG_SIZE] = { 0 };
	int registersSize[REG_SIZE] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	int blow = 0, increment = 0;
	
	for (int i = 0; i < REG_SIZE; i++) {
		cin >> registers[i];
	}

	while (blow == 0) {
		registers[0]++;
		blow = incrementReg(registers, registersSize, 0);
		if (blow == 0) increment++;
	}

	cout << increment << endl;

	return 0;
}

int incrementReg(int registers[REG_SIZE], int sizes[REG_SIZE], int index) {
	if ((registers[index] >= sizes[index]) && (index == REG_SIZE - 1)) {
		return 1;
	}
	else if (registers[index] >= sizes[index]) {
		registers[index++] = 0;
		registers[index]++;
		return incrementReg(registers, sizes, index);
	}
	else {
		return 0;
	}
}
