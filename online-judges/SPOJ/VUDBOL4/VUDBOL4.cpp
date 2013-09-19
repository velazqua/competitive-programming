/* Alex Velazquez
 * Start: Fri May  4 23:56:25 EDT 2012
 * End  : Sat May  5 00:11:36 EDT 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int N;
	while( cin >> N )
	{
		if( !N ) break;
		REP( i, N )
		{
			string S;
			cin >> S;
			string output = "";
			REP( j, N )
			{
				output += S[j];
				output += S[j];
			}
			cout << output << endl;
			cout << output << endl;
		}
	}
}
