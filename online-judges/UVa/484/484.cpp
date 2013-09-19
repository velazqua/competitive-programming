/* Alex Velazquez
 * Start: Mon Mar 26 22:32:21 EDT 2012
 * End  : Mon Mar 26 22:38:49 EDT 2012
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

int main ()
{
	int X;
	map<int,int> M;
	vector<int> nums;
	set<int> isIn;
	while( cin >> X )
	{
		pair<set<int>::iterator,bool> result = isIn.insert( X );
		M[X]++;
		if( result.second == true )
			nums.push_back( X );
	}
	int size = nums.size();
	REP( i, size )
		cout << nums[i] << " " << M[nums[i]] << endl;
}
