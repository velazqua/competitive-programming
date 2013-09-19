/* Alex Velazquez
 * Start: Sun Mar 25 01:28:05 EDT 2012
 * End  : Sun Mar 25 01:40:29 EDT 2012
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
	string S1, S2;
	int i = 0;
	while( getline( cin, S1 ) )
	{
		if( i == 0 ) cin.ignore();
		++i;
		getline( cin, S2 );
		vector<int> alphabet( 26, 0 );
		string answer = "";
		int size = S1.size();
		REP( i, size )
		{
			int x = S1[i]-'a';
			if( x >= 0 && x <= 25 )
				alphabet[x]++;
		}
		size = S2.size();
		REP( i, size )
		{
			int x = S2[i]-'a';
			if( x >= 0 && x <= 25 && alphabet[x] > 0 )
			{
				alphabet[x]--;
				answer += S2[i];
			}
		}
		sort( answer.begin(), answer.end() );
		cout << answer << endl;
	}
}
