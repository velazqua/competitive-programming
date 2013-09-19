/* Alex Velazquez
 * Start: Wed Feb 15 21:48:37 EST 2012
 * End  : Wed Feb 15 21:52:15 EST 2012
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

typedef long long int LL;


int main ()
{	
	int N;
	cin >> N;
	REP( i, N )
	{
		LL a, b;
		cin >> a >> b;
		// every number can be expressed as the product of primes
		// therefore the answer is b, which is the upperbound
		cout << b << endl;
	}
}
