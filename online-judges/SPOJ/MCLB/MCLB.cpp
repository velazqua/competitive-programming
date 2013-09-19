/* Alex Velazquez
 * Start: November 19, 2011 @ 08:37PM
 * End  : November 19, 2011 @ 09:11PM
*/

#include <iostream>

using namespace std;

typedef unsigned long long ULL;

ULL power2 ( int n )
{
	ULL x = 1LL;
	for( int i=0; i<n; ++i )
		x *= 2LL;
	return x;
}

ULL stringToULL ( string s )
{
	ULL x = 0LL;
	int e = 63;
	for( string::iterator it = s.begin(); it!=s.end(); ++it )
	{
		if( *it == 'B' ) x += power2( e );
		--e;
	}
	return x;
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		string S, E;
		cin >> S;
		cin >> E;
		string endString = "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
		if( S.compare( endString ) == 0 || E.compare( endString ) == 0 )
			cout << "Case " << i+1 << ": The goal state will never be reached!" << endl;
		else
		{
			if( S.compare( E ) > 0 )
			{
				ULL s1 = stringToULL( S );
				ULL e1 = stringToULL( E );
				cout << "Case " << i+1 << ": The goal state could be reached after " << e1-s1 << " laser beams." << endl;
			}
			else if( S.compare( E ) == 0 )
				cout << "Case " << i+1 << ": The goal state could be reached after " << 0 << " laser beams." << endl;
			else
			{
				cout << "Case " << i+1 << ": The goal state will never be reached!" << endl;
			}
		}
	}
}
