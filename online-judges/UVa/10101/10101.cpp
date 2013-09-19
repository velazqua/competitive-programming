/* Alex Velazquez
 * Start: Thu Dec  1 20:31:55 EST 2011
 * End  :
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <string>

using namespace std;

typedef long long LL;

string LLtoStr( LL x )
{
	stringstream ss;
	ss << x;
	return ss.str();
}

int power10( int x )
{
	int t = 1;
	for( int i=0; i<x; ++i )
		t *= 10;
	return t;
}

int main ()
{
	int t=1;
	LL x;
	vector<string> bangla;
	bangla.push_back( "shata" );
	bangla.push_back( "hajar" );
	bangla.push_back( "lakh" );	
	bangla.push_back( "kuti" );
	vector<int> amounts;
	amounts.push_back( 1 );
	amounts.push_back( 2 );
	amounts.push_back( 2 );
	amounts.push_back( 2 );
	while( cin >> x )
	{
		bool e = false;
		string answer = "";
		if( x%100 != 0 )
			answer = LLtoStr( x%100 );
		else
			e = true;
		if( t < 10 )
			cout << "   ";
		else if( t < 100 )
			cout << "  ";
		else if( t < 1000 )
			cout << " ";
		else
			cout << "";
		cout <<  t++ << ". ";
		if( x == 0LL )
		{
			cout << 0 << endl;
			continue;
		}
		x /= 100;
		int i = 0;
		while( x/10 > 0 )
		{
			if( x%power10(amounts[i%4]) != 0 )
			{
				answer = bangla[i%4] + " " + answer;
				answer = LLtoStr(x%power10(amounts[i%4])) + " " + answer;
			}
			x /= power10(amounts[i%4]);
			++i;
		}
		if( x > 0 )
		{
			answer = bangla[i%4] + " " + answer;
			answer = LLtoStr(x) + " " + answer;
		}
		if( e )
			cout << answer.substr( 0, answer.size()-1 ) << endl;
		else
			cout << answer << endl;
	}
}
