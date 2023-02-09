#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  int a, b;
  cin >> a;
  cin >> b;

  if( b < a)
  {
    cout << "b < a" << endl;
    return 1;
  }

  if( a < 0 || b < 0)
  {
    cout << "a or b is out of bounds" << endl;
    return 1;
  }

  auto nums = std::vector<std::string>{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  for( int i = a; i <= b; i++)
  {
    if( 1 <= i && i <= 9)
      cout << nums[i] << endl;
    else if( i%2 == 0)
      cout << "even" << endl;
    else
      cout << "odd" << endl;
  }

}
