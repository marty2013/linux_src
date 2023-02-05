// Quick Sort
// Recursive
// Uses a pivot
// - The pivot is in its correct position in the final sorted array.
//   ie, all items to the left are smaller and all items to the right are larger

#include <bits/stdc++.h>
#include "../../cpp/headers/__mgall.h"

using namespace std;

int partition( vector<int>& array, int start, int stop, int pivot_index)
{
  // partition vector into two groups
  // values smaller than or equal to pivot
  // values larger than pivot
  // return location of pivot element

  swap(array[start], array[pivot_index]);

  // partition values
  auto low = start + 1;
  auto high = stop;
  while(low<high)
  {
    if(array[low]<array[start])
      low++;
    else if(array[--high]<array[start])
      swap(array[low], array[high]);
  }

  // then swap pivot back into place
  swap(array[start], array[--low]);

  return low;

}

void quicksort( vector<int>& array, int low, int high)
{
  if(low < high)
  {
    // select the pivot value  
    int pivot_index = (low+high)/2;

    // partition the vector
    pivot_index = partition(array, low, high, pivot_index);
    
    // sort the two sub vectors
    if(low < pivot_index)
      quicksort(array, low, pivot_index);
    
    if(pivot_index < high)
      quicksort(array, pivot_index+1, high);
  }
}

int main()
{
  cout << "Quick Sort demo...:" << "\n";
  vector<int> array = {2,6,5,3,8,7,1,0};
  mg::print_vector(array);  

  cout << "Result..." << "\n";
  quicksort(array, 0, array.size());
  mg::print_vector(array);  

}
