#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v;
  v.push_back(1);
  
  try{
// example 1:    int j = v.at(99);
// example 2:
  auto i = 5;
  if( i > v.size())
    throw out_of_range("Past the point of no return");
  
  }
  catch( out_of_range& oor)
  {
    cout << "You idiot: " << oor.what() << endl;
  }
  catch( exception& e)
  {
    // always catch an exception bu ref otherwise you will
    // get slicing and lose info about the original exception
    // type thrown
    cout << "Something else: " << e.what() << endl;
  }
  return 0;
}
// The keyword noexcept does NOT mean that the function
// cannot or will not throw an exception. It just means
// that it wont throw an exception that is worth catching.
// That is, if one is thrown anyway we probably cant handle
// it.
// Advantages: expressivity, performance.
// Usually a simple function that works and if it did indeed
// throw an exception it would be in extremely abnormal
// circumstances and the program should probably terminate
// in that scenario.
// Can set noexcept(false). This says I might throw an
// exception. Usually seen in template metaprogramming
// but can be done if you think that there is a possibility.
// If a noexcept function throws - the app terminates with
// possibly no stack unwind !! Wont get a chance to catch the
// exception.
// For move operations - if an exception is thrown while moving
// there may be no guarantee that the whole operation
// can be wound back. Hence a lot of the operation in std::
// will only call noexcept functions. So there will be a propensity
// to call functions for moving that are marked noexcept otherwise
// they may be avoided and copies done instead. Hence mark functions
// that use move semantics as noexcept.
//
//
//
//
