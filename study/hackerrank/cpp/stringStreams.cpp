#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> parseInts(string s)
{
  vector<int> ints;
  stringstream ss(s);
  char delim;
  while(!ss.eof()){
    int val;
    ss >> val >> delim;
    ints.push_back(val);
  }

  return ints;
}

int main()
{
  string s = "23,4,56";
  auto vals = parseInts(s);
  for( auto i: vals)
    cout << i << endl;

}
