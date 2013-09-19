/* Alex Velazquez
 * Start: Sat Sep 15 23:45:59 EDT 2012
 * End  : Sun Sep 16 00:17:23 EDT 2012
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
	int T;
	cin >> T;
	REP( t, T )
	{
		cout << "Test #" << t+1 << ": ";
		bool isSymmetric = true;
		char d1, d2;
		int N;
		cin >> d1 >> d2 >> N;
		bool done = false;
		vector< vector<LL> > M( N, vector<LL>( N, 0LL ) );
		REP( i, N )
		{
			REP( j, N )
			{
				cin >> M[i][j];
				if( M[i][j] < 0LL )
				{
					done = true;
					isSymmetric = false;
				}
			}
		}
		FOR( i, 0, N )
		{
			if( done ) 
				break;
			FOR( j, 0, N )
			{
				if( M[i][j] != M[N-1-i][N-1-j] )
				{
					done = true;
					break;
				}
			} 
		}
		if( done )
			isSymmetric = false;
		cout << ( ( isSymmetric ) ? "Symmetric." : "Non-symmetric." ) << endl;
	}
}
