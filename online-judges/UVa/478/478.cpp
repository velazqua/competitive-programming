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
	vector< pair<char,vector<double> > > shapes;
	char f;
	while( cin >> f )
	{
		if( f == 'r' )
		{
			vector<double> p;
			REP( i, 4 )
			{
				double x;
				cin >> x;
				p.push_back( x );
			}
			shapes.PB( make_pair( f, p ) );
			
		}
		if( f == 'c' )
		{
			vector<double> p;
			REP( i, 3 )
			{
				double x;
				cin >> x;
				p.push_back( x );
			}
			shapes.PB( make_pair( f, p ) );			
		}
		if( f == 't' )
		{
			vector<double> p;
			REP( i, 6 )
			{
				double x;
				cin >> x;
				p.push_back( x );
			}
			shapes.PB( make_pair( f, p ) );			
		}
		if( f == '*' )
			break;
	}
	int size = SZ(shapes);
	double x, y;
	int c = 1;
	while( cin >> x >> y )
	{
		if( x == 9999.9 && y == 9999.9 )
			break;
		bool nothing = false;
		REP( i, size )
		{
			if( shapes[i].first == 'r' && pointInRectangle( x, y, shapes[i].second[0], shapes[i].second[1], shapes[i].second[2], shapes[i].second[3] ) )
			{
				nothing = true;
				cout << "Point " << c << " is contained in figure " << i+1 << endl;
			}
			
			if( shapes[i].first == 't' && pointInTriangle( x, y, shapes[i].second[0], shapes[i].second[1], shapes[i].second[2], shapes[i].second[3], shapes[i].second[4], shapes[i].second[5]  ) )
			{
				nothing = true;
				cout << "Point " << c << " is contained in figure " << i+1 << endl;
			}
			
			if( shapes[i].first == 'c' && pointInCircle( x, y, shapes[i].second[0], shapes[i].second[1], shapes[i].second[2] ) )
			{
				nothing = true;
				cout << "Point " << c << " is contained in figure " << i+1 << endl;
			}
		}
		
		if( !nothing )
			cout << "Point " << c << " is not contained in any figure" << endl;
			
		++c;
	}
}
