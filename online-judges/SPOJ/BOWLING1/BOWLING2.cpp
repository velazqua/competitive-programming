
/* Alex Velazquez
 * Start: October 30, 2011 @ 10:22PM
 * End  : October 31, 2011 @ 12:23AM (SIGSEGV)
 * 		  October 31, 2011 @ 12:41AM (SIGSEGV)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>

using namespace std;

int strInt( string x )
{
	int val;
	istringstream X( x );
	X >> val;
	return val;
}

int main ()
{
	int T;
	scanf( "%d\n", &T );
	for( int i=0; i<T; ++i )
	{
		int totalScore = 0;
		vector<int> scores;
		int f = 0, number;
		int turn = 1;
		while ( f < 9 )
		{
			cin >> number;
			if( number == 10 )
			{
				++f;
			}
			else if( turn == 1 )
			{
				turn = 2;
			}
			else if( turn == 2 )
			{
				turn = 1;
				++f;
			}
			scores.push_back( number );
		}
		int x, y;
		cin >> x >> y;
		scores.push_back( x );
		scores.push_back( y );
		if( x == 10 || x+y == 10 )
		{
			cin >> x;
			scores.push_back( x );
		}	
		
		int len = scores.size();
		int j = 0;
		turn = 1;
		int frames = 0;
		for( ; frames < 9; ++j )
		{
			if( scores[j] == 10 ) // strike
			{
				++frames;
				totalScore += scores[j] + scores[j+1] + scores[j+2];
			}
			else if( turn == 1 )
			{
				totalScore += scores[j];
				turn = 2;
			}
			else if( turn == 2 )
			{
				totalScore += scores[j];
				if( scores[j]+scores[j-1] == 10 ) // spare
					totalScore += scores[j+1];
				turn = 1;
				++frames;
			}
		}
		for( int k = j; k<len; ++k )
		{
			totalScore += scores[k];
		}
		cout << totalScore << endl;
	}
}
