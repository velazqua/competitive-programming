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
		string str;
		//getline( cin, str );
		char c;
		while( 1 )
		{
			c = getchar( );
			if( c == '\n' || c == '\r' )
				break;
			str += c;
		} 
		stringstream line( str );
		string token;
		vector<int> scores;
		while ( line >> token )
		{
			int num = strInt( token );
			scores.push_back( num );
		}
		int len = scores.size();
		int turn = 1;
		int j = 0;
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
