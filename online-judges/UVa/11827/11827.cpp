/* Alex Velazquez
 * Start: Sun Mar 25 00:35:12 EDT 2012
 * End  : Sun Mar 25 00:50:54 EDT 2012
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

int GCD( int a, int b )
{
	int t;
	while( b != 0 )
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int strToInt( string S )
{
	int val;
	istringstream X( S );
	X >> val;
	return val;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		if( i == 0 ) cin.ignore();
		string nums;
		getline( cin, nums );
		stringstream lines( nums );
		string token;
		vector<int> N;
		while( lines >> token )
		{
			//cout << "token: " << token << endl;
			N.push_back( strToInt( token ) );
		}
		sort( N.begin(), N.end(), greater<int>() );
		int size = N.size();
		int maxGCD = 0;
		FOR( j, 0, size-1 )
		{
			//cout << "N[j]: " << N[j] << endl;
			if( maxGCD >= N[j] )
				break;
			FOR( k, j+1, size )
			{
				//cout << "N[k]: " << N[k] << endl;
				maxGCD = max( GCD( N[k], N[j] ), maxGCD );
			}
		}
		cout << maxGCD << endl;
	}
}
