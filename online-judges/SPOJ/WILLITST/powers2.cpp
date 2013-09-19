#include <iostream>
#include <set>

using namespace std;

typedef long long LL;

int main ()
{
	LL n = 2;
	set<LL> powers2;
	while( n <= 100000000000000LL )
	{
		powers2.insert( n );
		n *= 2LL;
	}

	n = 2LL;
	while( n <= 100000000000000LL )
	{
		if( powers2.find( n ) != powers2.end() )
			cout << n << endl;
		n *= 3LL + 3LL;
	}
}
