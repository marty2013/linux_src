// Sort: Selection Sort
// Start with a miniumum candidate at the start of the array.
// Search thru the remainder of the array for an element that is smaller.
// If found then swap with the current minimum and then move to the
// next candidate.

#include <bits/stdc++.h>
using namespace std;

vector<int> sort_selection( vector<int> array)
{
  int n = array.size();
  for(int j = 0; j < n-1; j++)
  { 
    int iMin = j;

    for( int i = j+1; i<n; i++)
    {
      if(array[i]<array[iMin])
        iMin = i;
    }

    if( iMin != j)
      swap(array[j], array[iMin]);
  }

  return array; 
}

int main()
{
  vector<int> array = {2,8,5,3,9,4,1};
  auto array_sorted = sort_selection(array);
  for(int i: array_sorted)
    cout << i << endl;
  
}
