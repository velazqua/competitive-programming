#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

int main ()
{
	vector<ULL> S;
	set<ULL> isS;
	int LIMIT = 100;
	for( ULL i=1ULL; i<=(ULL)LIMIT; ++i )
	{
		S.push_back( i*i );
		isS.insert ( i*i );
	}
	
	for( int i=0; i<LIMIT-1; ++i )
	{
		vector<pair<ULL,ULL> > P;
		for( int j=i+1; j<LIMIT; ++j )
		{
			if( isS.count( 2ULL*S[j]-S[i] ) > 0 )
			{
				//cout << "x: " << S[j] << ". y: " << S[j]-S[i] << endl;
				P.push_back( make_pair( S[j]-S[i], S[j] ) );
			}
		}
	}
	sort( P.begin(), P.end() );
	int size = P.size();
	for( int i=0; i<size-1; ++i )
	{
		cout << P[i].first << " " << P[i].second << endl;
	}
}
