/* Alex Velazquez
 * Start: Tue Mar 20 19:23:16 EDT 2012
 * End  : Tue Mar 20 19:37:13 EDT 2012
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int sumDigits( int N )
{
	int S = 0;
	while( N )
	{
		S += N%10;
		N /= 10;
	}
	if( S >= 10 )
		return sumDigits( S );
	else
		return S;
}

int main ()
{
	string S1, S2;
	while( getline( cin, S1 ) && getline( cin, S2 ) )
	{
		int N1=0, N2=0;
		REP( i, S1.size() )
		{
			if( S1[i] >= 'A' && S1[i] <= 'Z' )
				N1 += S1[i]-'A'+1;
			if( S1[i] >= 'a' && S1[i] <= 'z' )
				N1 += S1[i]-'a'+1;
		}
		
		REP( i, S2.size() )
		{
			if( S2[i] >= 65 && S2[i] <= 90 )
				N2 += S2[i]-'A'+1;
			if( S2[i] >= 97 && S2[i] <= 122 )
				N2 += S2[i]-'a'+1;
		}
		
		N1 = sumDigits( N1 );
		N2 = sumDigits( N2 );
		
		if( N1 == 0 || N2 == 0 )
			cout << "0.00 %" << endl;
		else
			printf( "%.2f %%\n", (double) min(N1,N2)/max(N1,N2) * 100.00  );
	}
}
