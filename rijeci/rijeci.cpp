#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int t1 = 0, t2 = 1, nextTerm = 0;
	int K;
	vector<int> sequence;


    for (int i = 1; i <= 46; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            sequence.push_back(t1);
            continue;
        }
        if(i == 2)
        {
         	sequence.push_back(t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        sequence.push_back(nextTerm);
    }
	
	cin >> K;

	cout << sequence[K - 1] << " " << sequence[K] << endl;

	return 0;
}