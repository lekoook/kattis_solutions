#include <iostream>
#include <unordered_map> 
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

bool comparePairs(tuple<int, string>& lhs, tuple<int, string>& rhs)
{
  if (get<0>(lhs) > get<0>(rhs)) return true;
  else if (get<0>(lhs) < get<0>(rhs)) return false; 
  else if (get<0>(lhs) == get<0>(rhs))
    return get<1>(lhs) < get<1>(rhs); 
}

int main()
{
  unordered_map <string, tuple<int, unordered_set<string> > > wordList;
  unordered_set <string> userList; 
  int numLines; 
  cin >> numLines; 
  cin.get(); 
  
  for (int i=0; i<numLines; i++)
  {
    string user; 
    string temp; 
    string line; 
    stringstream ss;
    getline(cin, line);
    ss.str(line); 
    ss >> user; 
    userList.insert(user); 
    
    while (ss >> temp)
    {
      get<0>(wordList[temp])++; 
      get<1>(wordList[temp]).insert(user); 
    }
  }

  vector <tuple<int, string> > result; 
  for (auto &elem: wordList)
  {
    if (get<1>(elem.second).size() == userList.size())
      result.push_back(make_tuple(get<0>(elem.second), elem.first));
  }
  sort(result.begin(), result.end(), comparePairs);
  
  if (result.size() == 0) {cout << "ALL CLEAR" << endl; return 0; }
  
  for (auto &c: result)
    cout << get<1>(c) << endl; 
  
  return 0; 
}
