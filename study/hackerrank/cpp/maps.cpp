#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
  int nq;
  cin >> nq;
  map<string,int> m;
  vector<tuple<int, string, int>> queries;
  
  int num;
  string name;
  int grade;

  for( int i = 0; i < nq; i++)
  {
    cin >> num >> name;
    if( num == 1)
      cin >> grade;
    else
      grade = 0;
    
    queries.push_back(make_tuple(num, name, grade));
  }

  for( auto q: queries)
  {
    num = get<0>(q);
    name = get<1>(q);
    grade = get<2>(q);
    auto it = m.find(name);

    if( num == 1)
      if( it != m.end())
        it->second += grade;
      else
        m.insert(make_pair(name,grade));
    else if( num == 2 && it != m.end())
        m.erase(name);
    else if( num == 3)
      if( it != m.end())
        cout << it->second << endl;
      else
        cout << 0 << endl;
  }
}

