#include <iostream>
#include <vector>

using namespace std;

int S( int P )
{
	int ans = 0;
	int curr = 1;
	for( int i=2; i<=P; ++i )
	{
		curr *= i, curr %= P;
		if( i >= P-5 )
			ans += curr;
	}
	ans %= P;
	return ans;
}

int main ()
{
    unsigned int lim = 100, i, j;
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
	
	for( int i=0; i<2; ++i )
		P.erase( P.begin() );
	
	int size = P.size();
	int summ = 0 ;
	for( int i=0; i<size; ++i )
	{
		int Sp = S( P[i] );
		cout << P[i] << " -> S: " << Sp << endl;
		summ += Sp;
	}
	cout << summ << endl;
}
