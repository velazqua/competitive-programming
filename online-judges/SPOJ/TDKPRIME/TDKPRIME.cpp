/* Alex Velazquez
 * Start: October 31, 2011 @ 10:52PM
 * End  : October 31, 2011 @ ???????
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    unsigned int lim = 86029000, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    i = 2;
    for (j = i * i; j <= lim-1; j += i)
		primes[j] = true;
    for (i = 3; i*i <= lim-1; i+=2)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<int> P;
	P.push_back( 2 );
    for (i = 3; i <= lim-1; i+=2 )
	    if (!primes[i])
			P.push_back( i );
	
    int T, num;
    cin >> T;
    for( int i=0; i<T; ++i )
    {
		cin >> num;
		cout << P[num-1] << endl;
	}
	
}
