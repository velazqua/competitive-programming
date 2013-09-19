/* Alex Velazquez
 * Start: Mon May 21 01:29:27 EDT 2012
 * End  :
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
	int T;
	cin >> T;
	REP( i, T )
	{
		string line;
		if( i == 0 ) cin.ignore();
		getline( cin, line );
		stringstream lineStream( line );
		string word;
		int maxx = 0 ;
		int curr = 0;
		int currLen = 0;
		int ans = 0;
		while( lineStream >> word )
		{
			int size = word.size();
			if( currLen == size )
			{
				++curr;
			}
			else
			{
				if( curr > maxx )
				{
					maxx = curr;
					ans = currLen;
				}
				curr = 1;
				currLen = size;
			}
		}
		if( curr > maxx )
			maxx = curr;
		cout << maxx << endl;
	}
}
