/* Alex Velazquez
 * Start: October 30, 2011 @ 02:37AM
 * End  : October 30, 2011 @ 03:29AM (Wrong Answer)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void bestLineup( int &high, int currSum, int ratings[11][11], vector<bool> used, int level )
{
	if( level == 11 )
	{
		if( currSum > high )
			high = currSum;
	}
	else
	{
		for( int i=0; i<11; ++i )
		{
			if( /*ratings[level][i] != 0 &&*/ used[i] == false) 
			{
				used[i] = true;
				bestLineup( high, currSum+ratings[level][i], ratings, used, level+1 );
				used[i] = false;
			}
		}
	}
}

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int ratings[11][11];
		vector<bool> used( 10 );
		for(int j=0; j<11; ++j )
			for( int k=0; k<11; ++k )
			{
				scanf( "%d", &ratings[j][k] );
			}
		int high = 0;
		bestLineup( high, 0, ratings, used, 0 );
		cout << high << endl;
	}
}
