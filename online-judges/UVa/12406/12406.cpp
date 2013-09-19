/* Alex Velazquez
 * Start: Mon Sep 10 22:02:55 EDT 2012
 * End  : Mon Sep 10 22:24:09 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	vector<LL> twoPowerQ( 18, 1LL );
	for( int i=1; i<18; ++i )
		twoPowerQ[i] = 2LL * twoPowerQ[i-1];
	int T;
	cin >> T;
	REP( t, T )
	{
		cout << "Case " << t+1 << ":";
		int p, q;
		cin >> p >> q;
		//calculate smallest number
		bool found = false;
		long long theSmallest = 2222222222222222222LL, theBiggest = 0LL;
		for( int i=0; i<(1<<p); ++i )
		{
			long long smallest = 0LL;
			long long currentDigit = 1LL;
			for( int k=0; k<p; ++k )
			{
				if( (i&(1<<k)) > 0 )
				{
					smallest += ( 2LL * currentDigit ); 
				}
				else
				{
					smallest += currentDigit;
				}
				currentDigit *= 10LL;
			}
			#if DEBUG
				cout << "smallest: " << smallest << endl;
			#endif
			if( smallest > 0LL && smallest % twoPowerQ[q]  == 0 )
			{
				found = true;
				theSmallest = min( theSmallest, smallest );
				theBiggest = max( theBiggest, smallest );
			}
		}
		if( found )
		{
			if( theSmallest == theBiggest )
				cout << " " << theSmallest << endl;
			else
				cout << " " << theSmallest << " " << theBiggest << endl;
		}
		else
			cout << " impossible" << endl;
	}
	
}
