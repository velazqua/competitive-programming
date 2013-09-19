/* Alex Velazquez
 * Start: Sun Jul 22 02:47:11 EDT 2012
 * End  : Sun Jul 22 02:55:39 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	string line;
	while( getline( cin, line ) )
	{
		if( !line.compare( "DONE" ) )
			break;
		int size = SZ(line);
		int i = 0, iEnd = size-1;
		bool isPalindrome = true;
		while( i < iEnd )
		{
			if( !isalpha( line[i] ) )
			{
				++i;
				continue;
			}
			if( !isalpha( line[iEnd] ) )
			{
				--iEnd;
				continue;
			}
			if( !( line[i] == line[iEnd] || abs(line[i]-line[iEnd]) == 32 ) )
			{
				isPalindrome = false;
				break;
			}
			else
			{
				++i;
				--iEnd;
			}
		}
		if( isPalindrome )
			cout << "You won't be eaten!" << endl;
		else
			cout << "Uh oh.." << endl;
	}
}
