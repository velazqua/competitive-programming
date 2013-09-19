/* Alex Velazquez
 * Start: Sun Jan 15 20:38:58 EST 2012
 * End  : Sun Jan 15 22:04:23 EST 2012
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

typedef long long int LL;

using namespace std;

struct Figure {
	char type;
	double x;
	double y;
	double r;
	double xUL;
	double yUL;
	double xBR;
	double yBR;
	
	// circle constructor
	Figure( char T, double X, double Y, double R )
	{
		type = T;
		x = X;
		y = Y;
		r = R;
	}
	
	// rectangle construcor
	Figure( char T, double XUL, double YUL, double XBR, double YBR )
	{
		type = T;
		xUL = XUL;
		yUL = YUL;
		xBR = XBR;
		yBR = YBR;
	}
};

struct Point {
	int x;
	int y;
	Point( int X, int Y ) : x( X ), y( Y ) {}
};

bool pointInRectangle( double x, double y, double x1, double y1, double x2, double y2 ) 
{
	return ( x>x1 && x<x2 && y<y1 && y>y2 ) ? true : false;
}

bool pointInCircle( double x, double y, double xc, double yc, double r ) 
{
	double X = abs( x-xc );
	double Y = abs( y-yc );
	return ( sqrt( X*X+Y*Y ) < r ) ? true : false ;
}

int main ()
{
	vector<Figure> F;
	// read all figures
	char t;
	while( cin >> t )
	{
		if( t == '*' )
			break;
		else if( t == 'r' )
		{
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			Figure f( t, x1, y1, x2, y2 ); 
			F.push_back( f );
		}
		else
		{
			double x, y, r;
			cin >> x >> y >> r;
			Figure f( t, x, y, r );
			F.push_back( f );
		}
	}
	// read all points
	double x, y;
	int c = 1;
	while( cin >> x >> y )
	{
		if( x == 9999.9 && y == 9999.9 )
			break;
		bool contained = false;
		REP( i, F.size() )
		{
			bool in = false;
			if( F[i].type == 'r' ) // check if point is inside triangle
				in = pointInRectangle( x, y, F[i].xUL, F[i].yUL, F[i].xBR, F[i].yBR );
			else // check if point is inside triangle
				in = pointInCircle( x, y, F[i].x, F[i].y, F[i].r );
				
			if( in )
			{
				contained = true;
				cout << "Point " << c << " is contained in figure " << i+1 << endl;
			}
		} 
		if( !contained )
			cout << "Point " << c << " is not contained in any figure" << endl;
		c++;
	}
}
