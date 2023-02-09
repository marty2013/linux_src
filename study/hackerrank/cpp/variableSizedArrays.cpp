#include <iostream>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;  

  int *arr[n];

  for( int i = 0; i < n; i++)
  {
    int nn;
    cin >> nn;
    int arrarr[nn];
    arr[i] = new int[nn];    
  
    for( int j = 0; j < nn; j++)
      cin >> arr[i][j];
  }  

  int queries[q][2];

  for( int k = 0; k < q; k++)
    cin >> queries[k][0] >> queries[k][1];

  for( int k = 0; k < q; k++)
    cout << arr[queries[k][0]][queries[k][1]] << endl;  

  for( int i = 0; i < n; i++)
    delete[] arr[i];

}
