#include <iostream>

using namespace std;

int main ()
{
  int r = 1000;
  int R = r*r;
  int answer = 0;
  for( int a=-r; a<r+1; ++a )
  {
    for( int b=-r; b<r+1; ++b )
    {
      for( int c=-r; c<r+1; ++c )
      {
        if( a*a+b*b+c*c==R )
        {  //cout << a << " " << b << " " << c << endl;
          answer += (a>0)?a:-a;
          answer += (b>0)?b:-b;
          answer += (c>0)?c:-c;
        }
      }
    }
  }
  cout << answer << endl;
}
