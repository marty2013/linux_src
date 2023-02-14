#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int e;

  for( int i = 0; i < n; i++)
  {
    cin >> e;
    v.push_back(e);
  }

  int q1, q2a, q2b;
  cin >> q1 >> q2a >> q2b;

  v.erase(v.begin() + q1 - 1);
  v.erase(v.begin() + q2a - 1, v.begin() + q2b - 1);

  cout << v.size() << endl;
  for( int i: v)
    cout << i << " ";
  cout << endl;

}
