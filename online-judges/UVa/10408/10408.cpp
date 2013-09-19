/* Alex Velazquez
 * Start: Sat Mar 31 23:29:56 EDT 2012
 * End  : Sun Apr  1 00:16:46 EDT 2012
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

struct Fraction {
	int num;
	int den;
	Fraction( int n, int d ) : num(n), den(d) {}
};

bool operator < ( Fraction const& A, Fraction const& B )
{
	return ( ( A.num*B.den < B.num*A.den ) ? true : false );
}

int gcd( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main ()
{
	// calculate all farey sequences
	vector<vector<Fraction> > farey( 1001 );
	set<Fraction> currFractions;
	currFractions.insert( Fraction( 1, 1 ) );
	for( int D = 1; D<=1000; ++D )
	{
		for( int N=1; N<D; ++N )
		{
			if( gcd( D, N ) == 1 )
			{
				currFractions.insert( Fraction( N, D ) );
			}
		}
		//vector<Fraction> V( currFractions.begin(), currFractions.end() );
		//farey[D] = V;
		//copy( currFractions.begin(), currFractions.end(), back_inserter( farey[D] ) );
	}
	int n, k;
	while( cin >> n >> k )
	{
		vector<vector<Fraction> > farey( n+1 );
		set<Fraction> currFractions;
		currFractions.insert( Fraction( 1, 1 ) );
		for( int D = 1; D<=n; ++D )
			for( int N=1; N<D; ++N )
				if( gcd( D, N ) == 1 )
					currFractions.insert( Fraction( N, D ) );

		copy( currFractions.begin(), currFractions.end(), back_inserter( farey[n] ) );
		cout << farey[n][k-1].num << "/" << farey[n][k-1].den << endl;
	}
}
