#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> permutationsOfString( const string& str)
{
  if( str.length() == 1)
    return vector<string>{str};
  
  auto lastChar = str[str.length()-1];
  cout << "lastChar:" << lastChar << endl;

  auto substring = str.substr(0,str.length()-1);
  cout << "substring:" << substring << endl;

  auto subPerms = permutationsOfString(substring);
  
  auto newPerms = vector<string>();

  for(string subPerm: subPerms)
  {
    cout << "subPerm:" << subPerm << endl;
    newPerms.push_back(lastChar + subPerm);
    newPerms.push_back(subPerm + lastChar);  
    for( int i = 1; i < subPerm.length(); i++)
      newPerms.push_back( subPerm.substr(0,i) + lastChar + subPerm.substr(i+1,str.length()-(i+1)));
  }

  return newPerms;

}

int main()
{
  string str; cin >> str;
  
  cout << "Permutations of '" << str << "' are..." << endl;
  auto perms = permutationsOfString(str);
  for( auto s: perms)
    cout << s << endl;
  
 
}
