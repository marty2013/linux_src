#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int T;
  cin >> T;

  cout << setw(0xf) << internal;
  while(T--)
  {
    double A; cin >> A;
    double B; cin >> B;
    double C; cin >> C;

    // Note for the first one that to get it to print to hex we
    // need to truncate the double value. This is done by casting
    // to an integer type.
    //
    // Input: 100.345 Output: 0x64
    cout << left << hex << showbase << nouppercase << setprecision(0) << (long long) A << endl;
    
    // Input: 2006.008 Output: _______+2006.01
    cout << setw(15) << dec << setfill('_') << right << showpos << fixed << setprecision(2) << B << endl;

    // Input: 2331.41592653498 Output: 2.331415927E+03
    cout << noshowpos << scientific << uppercase << setprecision(9) << C << endl;
  }


}
