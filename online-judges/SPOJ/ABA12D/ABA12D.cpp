/* Alex Velazquez
 * Start: Sun Jan 15 10:46:02 EST 2012
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
#include <bitset>

using namespace std;

int sieve_size;
bitset<1000010> numbers;

int sumDiv ( int N )
{
	if( N == 1 )
		return 1;
	int S = 1+N;
	for( int i=2; i*i<=N; ++i )
	{
		if( N%i == 0 )
		{
			if( i != N/i )
				S += i+N/i;
			else
				S += i;
		}
	}
	return S;
}

bool isPrime( int N, vector<int> &primes )
{
	if( N <= 1000000 )
		return !numbers[N];
	else
	{
		int S = primes.size();
		for( int i=0; i<S; ++i )
			if( N%primes[i] == 0 )
				return false;
		return true;
	}
}

void sieve( int upperbound, vector<int> &primes )
{
	int sieve_size = upperbound + 1;
	numbers.set();
	numbers[0] = numbers[1] = 0;
	for( int i=2; i<= sieve_size; ++i )
	{
		if( numbers[i] )
		{
			for( int j=i*i; j<=sieve_size; j+=i )
				numbers[j] = 0;
			primes.push_back(i);
		}
	}
}

int main ()
{
	/*
    int LIMIT = 2500;
    vector<int> primes( 80000 );
    vector<bool> numbers(LIMIT);
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    int x = 0;
    while (i <= int(sqrt(LIMIT)))
    {
		  primes[x++] = i;
          for (int j=i+i;j<=LIMIT;j+=i)
              numbers[j] = true;    
          i++;
          while (numbers[i] == true)
                i++;
    }
    for ( ;i<LIMIT;++i)
        if (numbers[i] == false)
           primes[x++] = i;
    */
    bitset<1000010> numbers;
    vector<int> primes;
    
    // precalculate prime sum divisors
    vector<int> sumDivisors( 1000001, 0 );
    sumDivisors[0] = 0;
    for( int k=1; k<=1000000; ++k )
    {
		int X = sumDiv( k );
		sumDivisors[k] = sumDivisors[k-1];
		sumDivisors[k] += isPrime(X,primes)?1:0;
		
	}
	int N;
	cin >> N;
	for( int k=0; k<N; ++k )
	{
		int A, B;
		cin >> A >> B;
		cout << sumDivisors[B]-sumDivisors[A-1] << endl;
	}
}
