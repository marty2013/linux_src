#include <string>
#include <iostream>
#include <vector>

using namespace std;

// From Cracking the Coding Interview
// Find permutations of a string within a larger string

int main()
{
  string s = "abbc";
  string b = "cbabadcbbabbcbbaabccbabc";

  // find permutations of s in the string b.
  if( b.length() < s.length())
    cout << 0 << endl;

  vector<string> substrings;
  for(int i = 0; i < b.length() - 3; i++)
    substrings.push_back(b.substr(i,4));

  char xor_s;
  for( char c: s)
    xor_s ^= c;
  
  int numPerms = 0;
  for(auto ss: substrings)
  {
    char xor_ss;
    for( char c: ss)
      xor_ss ^= c;

    if(xor_ss^xor_s == 0)
      numPerms++;
  }

  cout << numPerms << endl;


}
