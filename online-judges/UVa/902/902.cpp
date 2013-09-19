/* Alex Velazquez
 * Start: Wed Feb  8 20:48:07 EST 2012
 * End  : Wed Feb  8 21:05:04 EST 2012
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

int main ()
{
	int N;
	string S;
	while( cin >> N >> S )
	{
		map<string,int> M;
		string s = S.substr( 0, N );
		++M[s];
		int size = S.size();
		for( int i=0; i<size-N; ++i )
		{
			s.erase( 0, 1 );
			s += S[N+i];
			++M[s];
		}
		int maxx = 0;
		string sMax;
		for( map<string,int>::iterator it=M.begin(); it!=M.end(); ++it )
		{
			//cout << it->first << " " << it->second << endl;
			if( it->second > maxx )
			{
				maxx = it->second;
				sMax = it->first;
			}
		}
		cout << sMax << endl;
	}
}
