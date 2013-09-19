/* Alex Velazquez
 * Start: Thu Apr 26 22:12:36 EDT 2012
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

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef unsigned long long ULL;
typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isPrime( int N )
{
	for( int i=3; i*i<=N; i+=2 )
		if( !(N%i) )
			return false;
	return true;
}

int main ()
{
    int LIMIT = 200000;
    vector<int> primes;
    vector<bool> numbers(LIMIT, false);
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    while (i*i <= LIMIT)
    {
          for (int j=i+i;j<=LIMIT;j+=i)
              numbers[j] = true;    
          i++;
          while (numbers[i])
                i++;
    }
    for (int i=0;i<LIMIT;++i)
        if (!numbers[i])
           primes.push_back(i);
    
    int size = primes.size();
    vector<ULL> B;
	REP( i, size-1 )
	{
		FOR( j, i+1, size )
		{
			B.push_back( (ULL)primes[i]*primes[j] );
		} 
	}
	cout << "There are " << B.size() << " bazinga numbers" << endl;
	sort( B.begin(), B.end() );
	cout << B[1500000] << endl;
	
}
