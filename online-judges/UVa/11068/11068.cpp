/* Alex Velazquez
 * Start: Fri Sep 28 22:40:03 EDT 2012
 * End  : Fri Sep 28 23:20:28 EDT 2012
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
	double a1, b1, c1, a2, b2, c2;
	while( cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 )
	{
		if( a1 == 0 && b1 == 0 && c1 == 0 && a2 == 0 && b2 == 0 && c2 == 0  )
			break;
		if( (b1*a2-b2*a1 == 0) || ( b1 == 0 && b2 == 0) || ( a1 == 0 && a2 == 0 )  )
			cout << "No fixed point exists." << endl;
		else
		{
			double x = (b1*c2-b2*c1)/(b1*a2-b2*a1);
			double y = -a1/b1*x+c1/b1;
			printf( "The fixed point is at %.2f %.2f.\n", x, y );
		}
	}
}
