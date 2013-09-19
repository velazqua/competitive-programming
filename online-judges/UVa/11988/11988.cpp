/* Alex Velazquez
 * Start: Wed Apr 18 20:16:19 EDT 2012
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
	string line;
	stringstream output;
	while( getline( cin, line ) )
	{
		string beiju = "";
		string::iterator whereInsert = beiju.end();
		string S = "";
		int size = line.size();
		REP( i, size )
		{
			if( line[i] == '[' )
			{
				beiju.insert( whereInsert, S.begin(), S.end() );
				whereInsert = beiju.begin();
				S = "";
			}
			else if( line[i] == ']' ) 
			{
				beiju.insert( whereInsert, S.begin(), S.end() );
				whereInsert = beiju.end();
				S = "";
			}
			else
			{
				//S.append( 1, line[i] );
				S += line[i];
			}
		}
		if( S.size() > 0 )
			beiju.insert( whereInsert, S.begin(), S.end() );
		beiju += '\n';
		output << beiju;
	}
	cout << output.str() << endl;
}
