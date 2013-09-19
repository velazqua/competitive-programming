/* Alex Velazquez
 * Start: Fri May  4 00:59:36 EDT 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	map<string,int> M;
	M["negative"] = -1;
	string S[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven"
		,"twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	REP( i, 21 )
		M[S[i]] = i;
	M["thirty"] = 30; M["forty"] = 40;M["fifty"] = 50;M["sixty"] = 60;M["seventy"] = 70;M["eighty"] = 80;
	M["ninety"] = 90;M["hundred"] = 100;M["thousand"] = 1000;M["million"]=1000000;
	string line;
	while( getline( cin, line ) )
	{
		stringstream lineStream( line );
		string token;
		int sign = 1;
		int total = 0;
		while( lineStream >> token )
		{
			if( M["negative"] == -1 )
				sign *= -1;
			else 
				
		}
	}
}
