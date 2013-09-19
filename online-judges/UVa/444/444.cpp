/* Alex Velazquez
 * Start: Sat Feb 18 16:53:51 EST 2012
 * End  : Sat Feb 18 17:34:04 EST 2012
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

int reverseInt( int X )
{
	int newInt = 0;
	vector<int> digits;
	while( X )
	{
		digits.push_back( X%10 );
		X /= 10;
	}
	reverse( digits.begin(), digits.end() );
	int T = 1;
	REP( i, digits.size() )
		newInt += T*digits[i], T *= 10;
	return newInt;
}

int strToInt( string S )
{
	int val;
	istringstream ss( S );
	ss >> val;
	return val;
}

string intToStr( int V )
{
	stringstream ss;
	ss << V;
	return ss.str();
}

int main ()
{
	string S;
	while( getline( cin, S ) )
	{
		if( (int)S[0]>=48 && (int)S[0]<=57 )
		{
			// decode message
			string newS = "";
			while( S.size() )
			{
				string X = S.substr( 0, 2 );
				S.erase( 0, 2 );
				reverse( X.begin(), X.end() );
				int R = strToInt( X );
				if( (R >= 65 && R <= 90) || 
					(R >= 97 && R <= 99) ||
					 R == 32 || R == 33 || R == 44 ||
					 R == 46 || R == 58 || R == 59 ||
					 R == 63 )
				{
					newS += char( R );
				}
				else
				{
					X = S[0] + X;
					S.erase( 0, 1 );
					newS += char( strToInt( X ) );
				}
			}
			reverse( newS.begin(), newS.end() );
			cout << newS << endl;		
		}
		else
		{
			// enconde message
			for( int i=S.size()-1; i>=0; --i )
			{
				string X = intToStr( (int)S[i] );
				reverse( X.begin(), X.end() );
				cout << X;
			}
			cout << endl;
		}
	}
}
