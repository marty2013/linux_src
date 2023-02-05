// Some practice with vectors
#include <iostream>
#include <vector>
using namespace std;

void print_vector( vector<int> v)
{
  for(int i: v)
    cout << i << " ";

  cout << "\n";
}

int main()
{
  vector<int> v = {0,1,2,3,4,5,6,7,8};
  print_vector(v);

  // sub-vector
  auto i1 = v.begin() + 2;
  auto i2 = v.begin() + 5;
  vector<int> v_sub(i1,i2);
  print_vector(v_sub);

  // first and second half of vector
  // remember that the end is 1 beyond what you need to grab
  cout << "Check split on an odd length array" << "\n";
  vector<int> h1(v.begin(), v.begin() + v.size()/2);
  vector<int> h2(v.begin() + v.size()/2, v.end());

  print_vector(h1);
  print_vector(h2);

  // check for an even length array
  cout << "Check split on an even length array" << "\n";
  vector<int> e = {0,1,2,3,4,5,6,7,8,9};
  print_vector(e);
  
  vector<int> e1(e.begin(), e.begin() + e.size()/2);
  vector<int> e2(e.begin() + e.size()/2, e.end());

  print_vector(e1);
  print_vector(e2);


}


