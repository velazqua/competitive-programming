/* Alex Velazquez
 * Start: Tue Apr  3 20:11:01 EDT 2012
 * End  : Tue Apr  3 20:33:35 EDT 2012
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

string intToStr( int X )
{
	stringstream ss;
	ss << X;
	return ss.str();
}

string lookAndSay( string S )
{
	int occur = 0;
	int size = S.size();
	char prev = S[0];
	string newS = "";
	for( int i=0; i<size; ++i )
	{
		if( (int)newS.size() > 1000 )
			break;
		if( S[i] == prev )
		{
			occur++;
		}
		else
		{
			newS += occur+48;
			newS += prev;
			occur = 1;
			prev = S[i];
		}
	}
	newS += intToStr( occur ) + prev;
	return newS;
}

int main ()
{
	string X;
	int i, j;
	while( cin >> X >> i >> j )
	{
		if( !X.compare( "0" ) && i == 0 && j == 0 )
			break;
		REP( k, i-1 )
		{
			X = lookAndSay( X );
		}
		cout << X[j-1] << endl;
	}
}
