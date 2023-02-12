#include <iostream>

using namespace std;

class Box
{
  private:
    int l;
    int b;
    int h;
  public:

    Box(): l(0), b(0), h(0) {}

    Box( int length, int breadth, int height)
      : l(length), b(breadth), h(height)
    {}

    Box(const Box& b): l(b.l), b(b.b), h(b.h) {}

    int get_length() { return l;}    
    int get_breadth() { return b;}    
    int get_height() { return h;}    

    long long CalculateVolume() { return (long long) l * b * h;}

    friend bool operator<(const Box& a, const Box& b);
    friend ostream& operator<<( ostream& out, const Box& b);

};

ostream& operator<<( ostream& out, const Box& b)
{
  return out << b.l << " " << b.b << " " << b.h;
}

bool operator<(const Box& a, const Box& b)
{
  if( a.l < b.l)
    return true;
  else if( a.b < b.b && a.l == b.l)
    return true;
  else if( a.h < b.h && a.b == b.b && a.l == b.l)
    return true;
  else
    return false;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{

/*
  Box b_empty;
  cout << "Empty box: " << b_empty << endl;

  int l, b, h;
  cin >> l >> b >> h;
  Box b2( l, b, h);
  cout << endl;

  cout << "b2 length: " << b2.get_length() << endl;
  cout << "b2 breadth: " << b2.get_breadth() << endl;
  cout << "b2 height: " << b2.get_height() << endl;
  cout << "b2 volume: " << b2.CalculateVolume() << endl;
  cout << "empty_box < b2: " << (b_empty < b2) << endl;
  cout << "b2: " << b2 << endl;
*/

  check2();



}

