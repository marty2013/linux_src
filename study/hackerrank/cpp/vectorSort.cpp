#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v;

  for(int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.push_back(val);
  }

  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++)
    cout << v[i] << " ";

  cout << "\n"; 

}
