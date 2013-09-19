/* Alex Velazquez
 * Start: Tue Jan 24 20:58:55 EST 2012
 * End  : Tue Jan 24 22:17:15 EST 2012
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
#define DEBUG 0

typedef long long int LL;

using namespace std;

string intToStr( int X )
{
	stringstream ss;
	ss << X;
	return ss.str();
}

int strToInt( string X )
{
	istringstream ss( X );
	int val;
	ss >> val;
	return val;
}

bool kaprekar( int X ) 
{
	string S = intToStr( X*X );
	int size = S.size();
	#if DEBUG
		cout << "X: " << X << endl;
		cout << "S: " << S << endl;
	#endif
	if( size <= 1 ) 
		return false;
	for( int i=1; i<size; ++i )
	{
		string part1 = S.substr( 0, i );
		string part2 = S.substr( i );
		int num1 = strToInt( part1 );
		int num2 = strToInt( part2 );
		#if DEBUG
			cout << part1 << " " << part2 << endl;
		#endif
		if( num1 > 0 && num2 > 0 && num1+num2 == X )
			return true;
	}
	return false;
}

int main ()
{
	int T;
	cin >> T;
	vector<int> M( 40005, -1 );
	REP( i, T )
	{
		int A, B;
		cin >> A >> B;
		cout << "case #" << i+1 << endl;
		int counter = 0;
		FOR( k, A, B+1 )
		{
			if( M[k] == 1 )
			{
				cout << k << endl;
				counter++;
			}
			else if( M[k] == 0 )
				continue;
			else if( kaprekar( k ) )
			{
				++counter;
				M[k] = 1;
				cout << k << endl;
			}
			else
				M[k] = 0;
		}
		if( !counter ) 
			cout << "no kaprekar numbers" << endl;
		if( i != T-1 ) 
			cout << endl;
	}
}
