#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
    unsigned int lim = 10000, i, j;
    lim += 1;
	vector<bool> primes( lim, false );
    for (i = 2; i*i <= lim-1; i++)
        if (!primes[i])
            for (j = i * i; j <= lim-1; j += i)
                primes[j] = true;
	
	vector<int> P;
    for (i = 2; i <= lim-1; i++)
	    if (!primes[i])
			P.push_back( i );
	
	for( int i=6; i<10000000; i+=4 )
	{
		cout << i << endl;
	}
}
