#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int elem;

  for( int i = 0; i < n; i++)
  {
    cin >> elem;
    v.push_back(elem);
  }

  int nq;
  cin >> nq;

  vector<int> queries;

  for( int i = 0; i < nq; i++)
  {
    int q;
    cin >> q;
    queries.push_back(q);
  }

  for( int q: queries)
  {
    auto lbit = lower_bound(v.begin(), v.end(), q);
    cout << (*lbit == q ? "Yes ": "No ") << lbit - v.begin() + 1 << endl;
  }
}
