/* Alex Velazquez
 * Start: Sat Mar 10 23:48:22 EST 2012
 * End  : Sun Mar 11 00:01:41 EST 2012
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

int sumDigits( int N )
{
	int summ = 0;
	while( N )
	{
		summ += N%10;
		N /= 10;
	}
	return summ;
}

int sumDigits( string N )
{
	int summ = 0;
	int size = N.size();
	REP( i, size )
	{
		summ += N[i]-'0';
	}
	return summ;
}

int degree( int N )
{
	int digits = sumDigits( N );
	if( digits%9 == 0 )
	{
		if( digits > 9 )
			return 1 + degree( digits );
		else if( digits == 9 )
			return 1; 
	}
	else
		return -1;
}

int degree( string N )
{
	int digits = sumDigits( N );
	if( digits%9 == 0 )
	{
		if( digits > 9 )
			return 1 + degree( digits );
		else if( digits == 9 )
			return 1; 
	}
	else
		return -1;
}

int main ()
{
	string N;
	while( cin >> N )
	{
		if( N == "0" )
			break;
		int ans = degree( N );
		cout << N << " ";
		if( ans == -1 )
			cout << "is not a multiple of 9." << endl;
		else
			cout << "is a multiple of 9 and has 9-degree " << ans << "." << endl;
	}
}
