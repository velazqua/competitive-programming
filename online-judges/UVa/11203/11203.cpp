/* Alex Velazquez
 * Start: Sat Jan 14 01:16:40 EST 2012
 * End  : Sat Jan 14 01:37:16 EST 2012
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
	int T;
	cin >> T;
	REP( i, T )
	{
		string line;
		cin >> line;
		int size = line.size();
		vector<int> O( 3, 0 );
		int numEs = 0, numMs = 0;
		bool done = false;
		int k = 0;
		REP( j, size )
		{
			// look for invalid string
			if( line[j] != '?' && line[j] != 'M' && line[j] != 'E' )  
			{
				done = true;
				break;
			} 
			//count number of occurrances of ? before M, before E, and after E
			else
			{
				if( k > 2 )
				{
					done = true;
					break;
				}
				if( line[j] == 'M' )
				{
					numMs++;
					++k;
				}
				else if( line[j] == 'E' )
				{
					numEs++;
					++k;
				}
				else
					O[k]++;
			}
		} 
		
		if( done || numMs != 1 || numEs != 1 )
		{
			cout << "no-theorem" << endl;
			continue;
		}
		else
		{
			if( O[0]+O[1] == O[2] && O[0]>0 && O[1]>0 && O[2]>1)
				cout << "theorem" << endl;
			else
				cout << "no-theorem" << endl;
		}
	}
}
