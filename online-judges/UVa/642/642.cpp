/* Alex Velazquez
 * Start: Mon Mar 26 22:45:57 EDT 2012
 * End  : Mon Mar 26 22:55:29 EDT 2012
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
	string lineSep = "XXXXXX";
	string outSep  = "******";
	map<string,set<string> > M;
	string S;
	bool isDict = true;
	while( cin >> S )
	{
		if( !S.compare( lineSep ) && isDict )
		{
			isDict = false;
			continue;
		}
		else if( !S.compare( lineSep ) )
			break;
		if( isDict )
		{
			string originalS = S;
			sort( S.begin(), S.end() );
			//cout << "S: " << S << ". originalS: " << originalS << endl;
			M[S].insert( originalS );
		}
		else
		{
			sort( S.begin(), S.end() );
			set<string> f = M[S];
			if( (int)f.size() == 0 )
				cout << "NOT A VALID WORD" << endl;
			else
			{
				for( set<string>::iterator it=f.begin();it!=f.end();++it )
					cout << *it << endl;
			}
			cout << outSep << endl;
		}
	}
}
