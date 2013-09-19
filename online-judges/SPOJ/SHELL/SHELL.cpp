/* Alex Velazquez
 * Start: Wed Dec 28 22:01:59 EST 2011
 * End  :
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

void doSwap( vector<bool> &pos, int i, int j )
{
	bool temp = pos[i];
	pos[i] = pos[j];
	pos[j] = temp;
}

int main ()
{
	string ball;
	getline( cin, ball );
	if( ball.compare("") == 0 || ball.size() <= 3 )
	{
		//do nothing
	}
	else
	{
		vector<bool> pos( 3, false );
		if( ball.compare( "left" ) == 0 )
			pos[0] = true;
		else if( ball.compare( "center" ) == 0 )
			pos[1] = true;
		else
			pos[2] = true;
		int N;
		cin >> N;
		for( int i=0; i<N; ++i )
		{
			string swapA, swapB;
			cin >> swapA >> swapB;
			int indA, indB;
			if( swapA.compare( "left" ) == 0 )			indA = 0;
			else if( swapA.compare( "center" ) == 0 )	indA = 1;
			else 										indA = 2;
			
			if( swapB.compare( "left" ) == 0 )			indB = 0;
			else if( swapB.compare( "center" ) == 0 )	indB = 1;
			else 										indB = 2;
			doSwap( pos, indA, indB );
		}
		if( pos[0] ) 
			cout << "left" ;
		else if( pos[1] )
			cout << "center" ;
		else
			cout << "right" ;
	}
}
