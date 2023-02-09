#include <iostream>
#include <cmath>

using namespace std;

void update( int *pa, int *pb)
{
  int a = *pa;
  int b = *pb;
  *pa = a + b;
  *pb = abs(a - b);
}

int main()
{
  int a, b;
  cin >> a;
  cin >> b;

  update(&a, &b);

  cout << a << endl;
  cout << b << endl;  
}
