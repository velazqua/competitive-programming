#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int bigPowMod( int a, int b )
{
	LL X = 1LL;
	for( int i=0; i<b; ++i )
		X *= a, X %= 100000000;
	return X;
}

int square( int x )
{
	return (x%100000000*x%100000000)%100000000;
}

int bigPowMod2( int a, int b )
{
	//cout << "a: " << a << ". b: " << b << endl;
	if( b == 0 )
		return 1;
	if( b == 1 )
		return a;
	if( b %2 == 0 )
	{
		return square( bigPowMod2( a, b/2 )%100000000 )%100000000;
	}
	else
	{
		return ((square( bigPowMod2( a, b/2 )%100000000 )%100000000) * (a%100000000))%100000000;
	}
}

int main ()
{
	cout << bigPowMod( 3, 27 ) << endl;
	cout << bigPowMod2(3, 27 ) << endl;
}
