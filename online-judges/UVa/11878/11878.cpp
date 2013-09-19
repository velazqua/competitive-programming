/* Alex Velazquez
 * Start: Mon Feb 20 14:32:26 EST 2012
 * End  : Mon Feb 20 14:39:47 EST 2012
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
	int a, b, c;
	char f, s, t;
	string line;
	int correctAnswers = 0;
	while( getline( cin, line ) )
	{
		stringstream newLine( line );
		if( line[line.size()-1] == '?' )
			continue;
		while( newLine >> a >> f >> b >> s >> c )
		{
			switch( f )
			{
				case '+' :
				{
					if( a + b == c )
						correctAnswers++;
					break;
				}
				case '-' :
				{
					if( a - b == c )
						correctAnswers++;
					break;
				}
			}
		}
	}
	cout << correctAnswers << endl;
}
