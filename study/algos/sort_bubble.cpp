// Bubble Sort
// Simply move consecutively thru the array and swap any out of order pairs.
// Repeat this process until the array is sorted.

#include <bits/stdc++.h>
#include "../../cpp/headers/__mgall.h"

using namespace std;

vector<int> bubble_sort( vector<int> a)
{
  auto sorted_array = a;
  auto n = sorted_array.size();

  for(int i = 1; i <= n; i++)
  {
    for( int j = 0; j < n - 1; j++)
    {
      if( sorted_array[j] > sorted_array[j+1])
        swap(sorted_array[j], sorted_array[j+1]);
    }
  }
  
  return sorted_array;
}

int main()
{
  cout << "Bubble Sort demo...:" << "\n";
  vector<int> a = {2,8,5,3,9,4,1};
  mg::print_vector(a);

  cout << "Result..." << "\n";
  auto sorted_array = bubble_sort(a);
  mg::print_vector(sorted_array);
}
