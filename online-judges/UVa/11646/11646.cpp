/* Alex Velazquez
 * Start: Wed Feb  8 21:13:34 EST 2012
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

#define PI 3.14159265
#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

int main ()
{
	double a, b;
	char semiColon;
	int i = 1;
	while( cin >> a >> semiColon >> b )
	{
		double L = 400.0/(2+PI*(a/b));
		double W = (a/b)*L;
		cout << "Case " << i++ << ": " << L << " " << W << endl;
	}
}
