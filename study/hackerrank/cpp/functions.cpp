#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_of_four(int a, int b, int c, int d)
{
  auto nums = vector<int>{a,b,c,d};
  return *max_element(begin(nums),end(nums));
}

int main()
{
  int a, b, c, d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  cout << max_of_four(a, b, c, d) << endl;
}
