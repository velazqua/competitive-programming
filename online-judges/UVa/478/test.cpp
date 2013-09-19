/* Alex Velazquez
 * Start: Fri Sep 28 21:09:39 EDT 2012
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

bool pointInRectangle( double x, double y, double x1, double y1, double x2, double y2 )
{
	if( x > x1 && x < x2 && y < y1 && y > y2 )
		return true;
	else
		return false;
}

bool pointInCircle( double x, double y, double x1, double y1, double r )
{
	if( r > sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y) ) )
		return true;
	else
		return false;
}

double sign(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y)
{
  return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

bool pointInTriangle( double x, double y, double x1, double y1, double x2, double y2, double x3, double y3 )
{
  bool b1, b2, b3;

  double a = sign(x, y, x1, y1, x2, y2);
  double b = sign(x, y, x2, y2, x3, y3);
  double c = sign(x, y, x3, y3, x1, x1);
  if( a == 0.0 || b == 0.0 || c == 0.0 )
	return false;
  else if( (a > 0.0 && b > 0.0 && c > 0.0 ) || (a < 0.0 && b < 0.0 && c < 0.0) )
	return true;
  else
    return false;
}

int main ()
{
	cout << sign( 1.0, 0.0, 0.0, 0.0, 2.0, 2.0 ) << endl; 
}
