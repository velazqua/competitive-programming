/* Alex Velazquez
 * Start: Sat Jan 14 22:00:09 EST 2012
 * End  : Sat Jan 14 22:22:04 EST 2012
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

int reverseNum( int N )
{
	deque<int> nums;
	while( N >= 10 )
	{
		nums.push_front( N%10 );
		N /= 10;
	}
	nums.push_front( N );
	int t = 1;
	int newNum = 0;
	REP( i, nums.size() )
	{
		newNum += nums[i]*t;
		t *= 10;
	}
	return newNum;
}

int main ()
{
    int LIMIT = 1000001;
    vector<int> primes;
    vector<bool> numbers(LIMIT);
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    while (i <= int(sqrt(LIMIT)))
    {
          for (int j=i+i;j<=LIMIT;j+=i)
              numbers[j] = true;    
          i++;
          while (numbers[i] == true)
                i++;
    }
    for (int i=0;i<LIMIT;++i)
        if (numbers[i] == false)
           primes.push_back(i);
	
	int N;
	while( cin >> N )
	{
		if( !numbers[N] )
		{
			int Nrev = reverseNum( N );
			if( Nrev == N )
				cout << N << " is prime." << endl;
			else if( !numbers[Nrev] )
				cout << N << " is emirp." << endl;
			else
				cout << N << " is prime." << endl;
		}
		else // not a prime
			cout << N << " is not prime." << endl;
	}
}
