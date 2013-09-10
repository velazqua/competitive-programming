#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ULL;

int main ()
{
	set<ULL> isS;
	int LIMIT = 10000000;
	for( ULL i=1ULL; i<=(ULL)LIMIT; ++i )
	{
		isS.insert ( i*i );
	}
	
	int C = 0;
	ULL sumL = 0ULL;
	for( ULL b=2ULL; C<12; ++b )
	{
		ULL h1 = 2ULL*b+1ULL;
		ULL h2 = 2ULL*b-1ULL;
		ULL L1 = b*b+h1*h1;
		ULL L2 = b*b+h2*h2;
		if( isS.count( L1 ) > 0 )
		{
			++C;
			sumL += sqrt(L1);
			cout << "#" << C << ":" << endl;
			cout << "h: " << h1 << ". b: " << b << ". L: " << sqrt(L1) << endl;
		}
		if( isS.count( L2 ) > 0 )
		{
			++C;
			sumL += sqrt(L2);
			cout << "#" << C << ":" << endl;
			cout << "h: " << h2 << ". b: " << b << ". L: " << sqrt(L2) << endl;
		}
	} 
}
