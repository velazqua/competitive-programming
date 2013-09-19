/* Alex Velazquez
 * Start: Mon Mar 26 23:21:48 EDT 2012
 * End  : Mon Mar 26 23:26:20 EDT 2012
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
	int d, s;
	cin >> d >> s;
	map<string,int> M;
	int val;
	string dict;
	REP( i, d )
	{
		cin >> dict >> val;
		M[dict] = val;
	}
	string line;
	int total = 0;
	while( getline( cin, line ) )
	{
		if( !line.compare( "." ) )
		{
			cout << total << endl;
			total = 0;
			continue;
		}
		stringstream streamLine( line );
		string token;
		while( streamLine >> token ) 
		{
			int X = M[token];
			if( X )
				total += X;
		}
	}
}
