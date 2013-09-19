/* Alex Velazquez
 * Start: Fri Sep 28 23:54:33 EDT 2012
 * End  : Sat Sep 29 00:04:15 EDT 2012
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
typedef vector<bool> vb;

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		string S;
		cin >> S;
		LL a1, b1, a2, b2, a3, b3;
		a1 = 0; b1 = 1; a2 = 1; b2 = 1; a3 = 1; b3 = 0;
		REP( i, SZ(S) )
		{
			if( S[i] == 'R' )
			{
				a1 = a2;
				b1 = b2;
				a2 = a2+a3;
				b2 = b2+b3;
			}
			else
			{
				a3 = a2;
				b3 = b2;
				a2 = a1+a2;
				b2 = b1+b2;
			}
		}
		cout << a2 << "/" << b2 << endl;
	}
}
