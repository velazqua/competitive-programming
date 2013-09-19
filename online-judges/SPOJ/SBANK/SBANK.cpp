/* Alex Velazquez
 * Start: Tue May  8 00:55:09 EDT 2012
 * End  : Tue May  8 01:17:51 EDT 2012
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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct BankAccount{
	int a, b, c, d, e, f, count;
	BankAccount( int A, int B, int C, int D, int E, int F, int COUNT ) : 
		a(A), b(B), c(C), d(D), e(E), f(F), count(COUNT) {} 
};

bool operator <( BankAccount const& A, BankAccount const& B )
{
	if( A.a < B.a )	return true;
	else if( A.a > B.a ) return false;
	else
	{
		if( A.b < B.b )	return true;
		else if( A.b > B.b ) return false;
		else
		{
			if( A.c < B.c )	return true;
			else if( A.c > B.c ) return false;
			else
			{
				if( A.d < B.d ) return true;
				else if( A.d > B.d ) return false;
				else
				{
					if( A.e < B.e )	return true;
					else if( A.e > B.e ) return false;
					else
					{
						if( A.f < B.f ) return true;
						else return false;
					}	
				}		
			}	
		}	
	}
}

int main ()
{
	int T, N, a, b, c, d, e, f;
	scanf( "%d\n", &T );
	REP( i, T )
	{
		scanf( "%d\n", &N );
		set<BankAccount> accounts;
		REP( j, N )
		{
			scanf( "%d %d %d %d %d %d\n", &a, &b, &c, &d, &e, &f );
			pair<set<BankAccount>::iterator,bool> result = accounts.insert( BankAccount( a, b, c, d, e, f, 1 ) );
			if( result.second == false )
			{
				int newCount = result.first->count+1;
				accounts.erase( result.first );
				accounts.insert( BankAccount( a, b, c, d, e, f, newCount ) );
			}
		}
		for( set<BankAccount>::iterator it=accounts.begin(); it!=accounts.end(); ++it )
		{
			printf( "%02d %08d %04d %04d %04d %04d %d\n", it->a, it->b, it->c, it->d, it->e, it->f, it->count );	
		}
		if( i != T-1 )
		{ 
			scanf( "\n" );
			printf( "\n" );
		}
	}
}
