/* Alex Velazquez
 * Start: November 17, 2011 @ 06:28PM
 * End  : November 17, 2011 @ ?????PM
*/

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	long long n;
	vector<long long> s;
	s.push_back( 0 );
	long long t = 0;
	for( int i=1; i<=17; i+=2 )
	{
		t += i;
		s.push_back( t );
	}
	while( cin >> n )
	{
		cout << 81 * ( n/9 ) + s[ n%9 ] << endl;
	}
}
