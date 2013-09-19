/* Alex Velazquez
 * Start: November 23, 2011 @ 10:15PM
 * End  : November 23, 2011 @ 10:18PM
*/

#include <iostream>

int power( int i, int k )
{
	if( k <= 0 ) return 1;
	int T = 1;
	for( int j=0; j<k; ++j )
		T *= i;
	return T;
}

using namespace std;

int main ()
{
	int N;
	int c = 1;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		cout << "Case " << c++ << ", N = " << N;
		cout <<", # of different labelings = ";
		cout << power( N, N-2 ) << endl;
	}
}
