#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
  int nq;
  cin >> nq;
  vector<pair<int,int>> queries;

  for( int i = 0; i < nq; i++)
  {
    pair<int,int> query;
    cin >> query.first >> query.second;
    queries.push_back(query);
  }

  set<int> s;

  for( int i = 0; i < nq; i++)
  {
    pair<int,int> q = queries[i];
    int val = q.second;
    auto it = s.find(val);
    bool inSet = it != s.end();

    if( q.first == 1)
      s.insert(val);
    else if( q.first == 2 && inSet)
      s.erase(val);
    else if( q.first == 3)
    {
      if( inSet)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}
