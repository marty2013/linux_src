// Merge Sort
// Divide and conquer.
// Split array in halves down to having the individual items.
// Now merge back in correct sorted order as we rebuild.
// Done by a recursive algo.

#include <bits/stdc++.h>
using namespace std;

// implement merge step
vector<int> merge( vector<int> a, vector<int> b)
{
  vector<int> merged_array;
  
  while( !a.empty() && !b.empty())
  {
    if( a[0] > b[0])
    {
      merged_array.push_back(b[0]);
      b.erase(b.begin());
    }
    else
    {
      merged_array.push_back(a[0]);
      a.erase(a.begin());
    }
  }
  
  // at this point either a or b is empty

  while( !a.empty())
  {
    merged_array.push_back(a[0]);
    a.erase(a.begin());
  }  

  while( !b.empty())
  {
    merged_array.push_back(b[0]);
    b.erase(b.begin());
  }  

  return merged_array;

}

vector<int> merge_sort(vector<int> a)
{
  auto n = a.size();

  if(n == 1)
    return a;

  vector<int> a1(a.begin(), a.begin() + n/2);
  vector<int> a2(a.begin() + n/2, a.end());

  a1 = merge_sort(a1);
  a2 = merge_sort(a2);

  return merge( a1, a2);
}


int main()
{
  vector<int> array = {2,8,5,3,9,4,1,7};
  auto sorted = merge_sort(array);
  for( int i: sorted)
    cout << i << "\n";

}
