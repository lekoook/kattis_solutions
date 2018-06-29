#include <iostream>

using namespace std;

int main(void) {
	int numLawns;
	double area, totalCost = 0, costPerSqM, width, length, totalArea;

	cin >> costPerSqM;
	cin >> numLawns;
	
	while (numLawns--) {
		cin >> width >> length;
		// Compute the area
		area = width * length;
		
		// Add to the running total area
		totalArea += area;
	}
	totalCost = totalArea * costPerSqM;
	printf("%0.7lf\n", totalCost);
	return 0;
}