/* Alex Velazquez
 * Start: Fri Sep 21 12:27:54 EDT 2012
 * End  :
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
typedef vector<bool> vb;

int main ()
{
	int N;
	cin >> N;
	vector< vector<int> > G;
	G.PB( vector<int>() );
	vector< vector<int> > maxx;
	REP( i, N )
	{
		int n;
		cin >> n;
		vector<int> temp( n, 0 );
		maxx.PB( temp );
		REP( j, n )
		{
			cin >> temp[j];
		}
		G.PB( temp );
	}
	
}
