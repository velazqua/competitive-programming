/* Alex Velazquez
 * Start: Thu Dec  8 20:52:01 EST 2011
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

LL power10( int N ) 
{
	LL t= 1LL;
	for( int i=0; i<N; ++i )
		t *= 10;
	return t;
}

int main ()
{
	map<LL,int> ones;
	ones[1LL] = 1; ones[11LL] = 2;
	LL x = 11LL;
	for( int i=2; i<=18; ++i )
	{
		x += power10(i);
		ones[x] = i;
	}
	int N;
	while( cin >> N )
	{
		map<LL,int>::iterator it=ones.begin();
		++it;
		bool found = false;
		for( ;it!=ones.end();++it )
		{
			if( (it->first)%N == 0 )
			{
				found = true;
				cout << N << " " << it->second + 1 << endl;
				break;
			}
		}
		if( !found )
			cout << N << " " << 0 << endl;
	}
}
