/* Alex Velazquez
 * Start: November 09, 2011 @ 09:11PM
 * End  : November 07, 2011 @ 09:32PM
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

int main ()
{
	LL n = 2;
	set<LL> powers2;
	while( n <= 100000000000000LL )
	{
		powers2.insert( n );
		n *= 2LL;
	}

	cin >> n;
	if( n <= 1 || powers2.find( n ) != powers2.end() )
		cout << "TAK" << endl;
	else
		cout << "NIE" << endl;
}
