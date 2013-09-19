/* Alex Velazquez
 * Start: November 07, 2011 @ 09:17PM
 * End  : November 07, 2011 @ ?????PM
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
} 

struct Point {
	int x;
	int y;
	int xSign;
	int ySign;
	int oSign;
	Point( int x_, int y_, int xS, int yS, int oS )
		: x( x_ ), y( y_ ), xSign( xS ), ySign( yS ), oSign( oS ) {}
	Point( int x_, int y_ ) 
	{
		if( x_ == 0 )
		{
			x = 0;
			xSign = 0;
		}
		else if( x_ > 0 )
		{
			x = x_;
			xSign = 1;
		}
		else
		{
			x = -1*x_;
			xSign = -1;
		}
		if( y_ == 0 )
		{
			y = 0;
			ySign = 0;
		}
		else if( y_ > 0 )
		{
			y = y_;
			ySign = 1;
		}
		else
		{
			y = -1*y_;
			ySign = -1;
		}
		int gcd = GCD( x, y );
		cout << "x: " << x << ". y: " << y << ". GCD: " << gcd << endl;
		if( gcd != 0 )
		{
			x /= gcd;
			y /= gcd;	
		}
		oSign = xSign*ySign;
	}
};

bool operator < (Point const& P1, Point const& P2 )
{
	if( P1.x < P2.x )
		return true;
	else if( P1.x > P2.x )
		return false;
	else
	{
		if( P1.y < P2.y )
			return true;
		else if( P1.y > P2.y )
			return false;
		else
		{
			if( P1.oSign != P2.oSign )
				return true;
			else
				return false;
		}
	}
}

int main ()
{
	int T;
	while( cin >> T )
	{
		if( T == 0 )
			break;
		int x, y;
		vector<Point> allPoints;
		set<Point> slopes;
		for( int i=0; i<T; ++i )
		{
			cin >> x >> y;
			Point p( x, y );
			for( vector<Point>::iterator it = allPoints.begin(); 
											  it!=allPoints.end();
											  ++it ) {
				if( p.x == it->x )
					slopes.insert( Point( 0, 0, -1, 1, 0 ) );
				else
					slopes.insert( Point( p.x-it->x, p.y-it->y ) );
			}
			allPoints.push_back( p );		
		}
		for( set<Point>::iterator it = 	slopes.begin();
										it!=slopes.end();
										++it ){
			cout << it->x << " " << it->y;
			cout << " " << it->oSign << endl;
		}
	}
}
