/* Alex Velazquez
 * Start: Fri Jul  6 23:08:13 EDT 2012
 * End  : Fri Jul  6 23:17:47 EDT 2012
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
	int N;
	while( cin >> N )
	{
		vector<int> nums( N );
		REP( i, N )
			cin >> nums[i];
		int A = 0;
		FOR( i, 0, N-1 )
			FOR( j, i+1, N )
				if( nums[i] > nums[j] )
					++A;
		cout << "Minimum exchange operations : " <<  A << endl;
	} 
}
