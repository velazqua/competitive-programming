/* Name: Alex Velazquez
 * Start Date: October 25, 2011 @ 12:48PM
 * End Date:   October 25, 2011 @ ??:??PM
*/

#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>

typedef unsigned long long ULL;
using namespace std;

int main ()
{
	int T;
	cin >> T;
	// precalculate all square numbers
	set<ULL> sqs;
	for( int i=0; i<=1000000; ++i )
	{
		sqs.insert((ULL)i*i);
	}
	ULL b, c;
	for( int i=0; i<T; ++i )
	{
		scanf( "%lld\n", &c );
		for( set<ULL>::iterator a = sqs.begin(); a != sqs.end(); ++a )
		{
			if( *a > c )
			{
				cout << "No" << endl;
				break;
			}
			b = sqrt(c-*a);
			if( ceil(b) == floor(b) && *a + b*b == c )
			{
				//cout << c << " = " << *a << " + " << b*b << endl;
				cout << "Yes" << endl;
				break;
			}
		}
	}
}
