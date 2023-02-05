#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n; cin >> n;

  cout << "Please enter " << n << " space-separated values..." << endl;

  vector<int> v(n);

  for( int i = 0; i < n; i++)
    cin >> v[i];

  cout << "You entered.." << endl;
  for( int i = 0; i < n; i++)
  {
    cout << v[i];
    if(i < n-1)
      cout << " ";
  }

  cout << endl << "...thanks and bye" << endl;

}
