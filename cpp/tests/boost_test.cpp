// test the boost install
// boost files installed at /usr/lib/x86_64-linux-gnu

#include <iostream>
#include <boost/array.hpp>

using namespace std;

int main()
{
  boost::array<int,4> arr = {1,2,3,4};
  for( int i: arr)
  {   
    cout << i << endl;
  }
}
