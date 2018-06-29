#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;
vector<int> triangle;
int tc;

void checkTriangle (int vertex) {
    vector<int> neighbours;
    for (int i = 0; i < tc; i++) if (v[vertex][i]) neighbours.push_back(i);
    
    if (neighbours.size() > 1) {
        for (int i = 0; i < (int)neighbours.size(); i++) {
            for (int k = 0; k < (int)neighbours.size(); k++) {
                if (v[neighbours[i]][neighbours[k]]) {
                    triangle[vertex] = 1;
                    triangle[neighbours[i]] = 1;
                    triangle[neighbours[k]] = 1;
                }
            }
        }
    }
}

int main () {
    while(cin >> tc, tc != -1) {
        v.assign(tc, vector<int>());
        triangle.assign(tc, 0);
        
        for (auto &it : v) it.assign(tc, 0);
        
        for (int i = 0; i < tc; i++)
            for (int j = 0; j < tc; j++)
                cin >> v[i][j];
        
        for (int i = 0; i < tc; i++) if (!triangle[i]) checkTriangle(i);
        for (int i = 0; i < tc; i++) if(!triangle[i]) cout << i << " ";
        cout << endl;
    }
    
    return 0;
}