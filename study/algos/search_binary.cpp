// Binary Search algorithm
//

#include <iostream>
#include <vector>

using namespace std;

int binary_search( vector<int> values, int value)
{
  int left = 0;
  int right = values.size()-1;
  
  while(left <= right)
  {
    int mid = (right+left)/2;
    
    if( values[mid] == value)
      return mid;
    else if( values[mid] < value)
      left = mid + 1;
    else
      right = mid - 1;

  }

  return -1;

}

int main()
{
  vector<int> values = {1,4,5,7,9,12,15,18,19,22,25,29,40,50};
  int search_value = 12;  
  int search_value_bad = 13;  

  cout << binary_search(values, search_value) << endl; 
  cout << binary_search(values, search_value_bad) << endl; 
}
