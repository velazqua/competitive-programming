/* Alex Velazquez
 * Start: Sun Jul 15 18:42:17 EDT 2012
 * End  : Sun Jul 15 19:03:58 EDT 2012
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
#define EPS			 10e-7

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	double p, q, r, s, t, u;
	while( cin >> p >> q >> r >> s >> t >> u )
	{
		double high = 1.0;
		double low = 0.0;
		bool solFound = false;
		for( int i=0; i<100; ++i )
		{
			double x = (high+low)/2.0;
			double res = p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
			#if DEBUG
				cout << "high: " << high << ". low: " << low << endl;
				cout << "Guess: " << x << endl;
				cout << "res: " << res << endl;
			#endif	
			if( high <= low )
				break;
			if( res <= EPS && res >= -EPS )
			{
				printf( "%.4f\n", x );
				solFound = true;
				break;
			}
			else if( res < EPS )
			{
				high = x;
			}
			else if( res > EPS )
			{
				low = x;
			}
		}
		if( !solFound )
			cout << "No solution" << endl;
	}
}
