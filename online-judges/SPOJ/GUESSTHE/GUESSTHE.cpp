/* Alex Velazquez
 * Start: October 29, 2011 @ 06:00PM
 * End  : October 29, 2011 @ 06:15PM
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

LL GCD( LL a, LL b )
{
	LL t;
	while( b != 0 )
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
} 

LL LCM( LL a, LL b )
{
	return ( a / GCD( a, b ) ) * b;
}

int main ()
{
	string s;
	while( cin >> s )
	{
		if( s == "*" )
			break;
		if( s[0] == 'N' )
		{
			cout << -1 << endl;
			continue;
		}
		int size = s.size();
		vector<LL> notMultiples;
		LL currAnswer = 1;
		for( int i=1; i<size; ++i )
		{
			if( s[i] == 'Y' )
			{
				//cout << currAnswer << " " << i+1 << endl;
				currAnswer = LCM( currAnswer, (LL)i+1LL );
			}
			else
				notMultiples.push_back( (LL)i+1LL );
		}
		bool contradiction = false;
		for( vector<LL>::iterator it = notMultiples.begin(); it!=notMultiples.end(); ++it )
		{
			if( currAnswer%*it == 0 ) // contradiction
				contradiction = true;
		}
		if( contradiction )
			cout << -1 << endl;
		else
			cout << currAnswer << endl;
	}
}
