/* Name: Alex Velazquez
 * Start Date: November 06, 2011 @ 04:51PM
 * End Date:   November 06, 2011 @ ?????PM
*/

#include <iostream>
#include <set>
#include <vector>

#define DEBUG 1

using namespace std;

int maxx( int x, int y )
{
	return ( x > y ) ? x : y;
}

int minn( int x, int y )
{
	return ( x < y ) ? x : y;
}

struct Point {
	int x;
	int y;
	Point( int x_, int y_ ) : x( x_ ), y( y_ ) {}
};

int main ()
{
	int M, N;
	while( cin >> M >> N )
	{
		if( M == 0 && N == 0 )
			break;
		if( M == N )
		{
			cout << 0 << endl;
			continue;
		}
		long long int ways = 0LL;
		Point origin( 0, 0 );
		int move = 0;
		int xM = 0, yM = 0;
		int d = 0;
		bool gameOn = true;
		while( gameOn )
		{
			switch( move%4 )
			{
				case 0: // move up right
					d = minn( M-origin.x, N-origin.y ); 
					xM = d;
					yM = d;
					break;
				case 1: // move down right
					d = minn( M-origin.x, N );
					xM = d;
					yM = -1*d;
					break;
				case 2: // move down left
					d = minn( M, origin.y);
					xM = -1*d;
					yM = -1*d;
					break;
				case 3: // move up left
					d = minn( origin.x, N);
					xM = -1*d;
					yM = d;
					break;
			}
			origin.x += xM;
			origin.y += yM; 
			#if DEBUG
				cout << "move: " << move << endl;
				cout << "(" << origin.x << ", " << origin.y << ")" << endl;
			#endif
			if( ( origin.x == 0 && origin.y == N ) || 
				( origin.x == M && origin.y == N )|| 
				( origin.x == M && origin.y == 0 )||
				( origin.x == 0 && origin.y == 0 ) )
			{
				if( move == 0 )
				{
					cout << 0 << endl;
				}
				else
				{
					cout << ways*4LL << endl;
				}
				gameOn = false;
			}
			else
			{
				++ways;
			} 
			++move;
		}
		
	}
}
