/* Name: Alex Velazquez
 * Start Date: October 28, 2011 @ 07:25PM
 * End Date:   October 28, 2011 @ 07:32PM (Time limit exceeded)
 * 			   October 28, 2011 @ 07:42PM (Time limit exceeded again)	
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

struct Law {
	bool active;
	bool cancel;
	int num;
	Law( bool a, bool c ) : active(a), cancel(c), num(-1) {}
	Law( bool a, bool c, int n ) : active(a), cancel(c), num(n) {}
};

int main ()
{
	int T, L;
	scanf( "%d\n", &T );
	char s[8];
	int lawNum;
	for( int i=0; i<T; ++i )
	{
		scanf( "%d\n", &L );
		vector<Law> laws;
		for( int j=0; j<L; ++j )
		{
			scanf( "%s", s );
			if( strcmp( s, "declare" ) == 0 )
				laws.push_back(Law(true,false));
			else
			{
				scanf( "%d\n", &lawNum );
				laws.push_back(Law(true,true,lawNum));
				int ind = j+1;
				while( laws[ind-1].cancel )
				{
					int k = laws[ind-1].num;
					laws[k-1].active = ( laws[k-1].active ) ? false : true;
					ind = k;
				}
			}
		}
		vector<int> activeLaws;
		int c = 0;
		for( int k=0; k<L; ++k )
		{
			if( laws[k].active )
			{
				++c;
				activeLaws.push_back( k+1 );
			}
		}
		printf( "%d\n", c );
		int size = activeLaws.size();
		for( int k=0; k<size; ++k )
			printf( "%s%d", ( ( k == 0 ) ? "" : " "), activeLaws[k] ); 
		printf( "\n" );
	}
}
