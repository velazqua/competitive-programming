/* Alex Velazquez
 * Start: Fri Sep 28 22:17:08 EDT 2012
 * End  : Fri Sep 28 22:49:05 EDT 2012
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
	while( cin >> N )
	{
		if( !N )
			break;
		vector<int> p( N, 0 );
		REP( i, N )
			cin >> p[i];
		int c = 0;
		REP( i, N )
		{
			if( i == 0 )
			{
				if( (p[i] > p[i+1] && p[i] > p[N-1]) || (p[i] < p[i+1] && p[i] < p[N-1]) )
					++c;
			}
			else if( i == N-1 )
			{
				if( (p[i] > p[0] && p[i] > p[i-1]) || (p[i] < p[0] && p[i] < p[i-1]) )
					++c;
			}
			else
			{
				if( (p[i] > p[i+1] && p[i] > p[i-1]) || (p[i] < p[i+1] && p[i] < p[i-1]) )
					++c;
			}
		}
		cout << c << endl;
	}
}
