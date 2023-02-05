#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using namespace std;

struct record
{
  int numToRemove1;
  int numToRemove2;
  int numToRemove3;
  bool valid()
  {
    return numToRemove1 != -1 && numToRemove2 != -1 && numToRemove3 != -1;
  }
};

shared_ptr<record> make_record()
{
  auto newRecord = make_shared<record>();
  newRecord->numToRemove1 = -1;
  newRecord->numToRemove2 = -1;
  newRecord->numToRemove3 = -1;
  return newRecord;
}

int main()
{
  vector<int> h1{1,1,1,1,2};
  vector<int> h2{3,7};
  vector<int> h3{1,3,1};

  reverse(h1.begin(),h1.end());  
  reverse(h2.begin(),h2.end());  
  reverse(h3.begin(),h3.end());  

  map<int,shared_ptr<record>> cumulatives;
  
  int n1 = h1.size();
  int cum1 = 0;
  for(int i = 0; i < n1; i++)
  {
    cum1 += h1[i];
    cumulatives[cum1] = make_record();
    cumulatives[cum1]->numToRemove1 = n1-i-1;
  }

  int n2 = h2.size();
  int cum2 = 0;
  for(int i = 0; i < n2; i++)
  {
    cum2 += h2[i];
    if(cumulatives.find(cum2) == cumulatives.end())
      cumulatives[cum2] = make_record();
  
    cumulatives[cum2]->numToRemove2 = n2-i-1;
  }

  int n3 = h3.size();
  int cum3 = 0;
  for(int i = 0; i < n3; i++)
  {
    cum3 += h3[i];
    if(cumulatives.find(cum3) == cumulatives.end())    
      cumulatives[cum3] = make_record();

    cumulatives[cum3]->numToRemove3 = n3-i-1;
  }

  int maxCum = 0;
  for( auto const& x: cumulatives)
  {
    if(x.second->valid())
    {
      maxCum = x.first > maxCum ? x.first: maxCum;
    }
  }

  cout << maxCum << endl;

}
