/* Alex Velazquez
 * Start: November 19, 2011 @ 09:33PM
 * End  : November 19, 2011 @ 09:42PM
*/

#include <iostream>
#include <set>

using namespace std;

int main ()
{
	// pre-calculate all beehive numbers
	// less than 10^9
	set<int> beeHives;
	for( int i=1; i<18259; ++i )
		beeHives.insert( 1+3*i*( i-1 ) );
	int N;
	while( cin >> N ) 
	{
		if( N == -1 )
			break;
		if( beeHives.find( N ) != beeHives.end() ) // found it
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
