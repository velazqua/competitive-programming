/* Alex Velazquez
 * Start: Wed Apr 18 19:49:53 EDT 2012
 * End  : Wed Apr 18 20:02:36 EDT 2012
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
#include <cctype>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

string toLowerCase( string S )
{
	int size = S.size();
	string newString = "";
	REP( i, size )
		newString += tolower( S[i] );
	return newString;
}

int main ()
{
	string word;
	map<string,vector<string> > M;
	while( cin >> word )
	{
		if( !word.compare( "#" ) ) break; 
		string S = toLowerCase( word );
		sort( S.begin(), S.end() ); 
		M[S].push_back( word );
	}
	
	set<string> orderS;
	for( map<string,vector<string> >::iterator it=M.begin(); it!=M.end(); ++it )
		if( it->second.size() == 1 )
			orderS.insert( it->second[0] );
			
	for( set<string>::iterator it=orderS.begin(); it!=orderS.end(); ++it )
		cout << *it << endl;
}
