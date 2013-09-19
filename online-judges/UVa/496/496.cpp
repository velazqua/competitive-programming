/* Alex Velazquez
 * Start: Sun Apr 15 23:04:10 EDT 2012
 * End  : Sun Apr 15 23:17:31 EDT 2012
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

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int subset( vector<int> &A, vector<int> &B, int const& sizeA, int const& sizeB )
{
	set<int> setB;
	for( int i=0; i<sizeB; ++i )
		setB.insert( B[i] );
	int c = 0;
	for( int i=0; i<sizeA; ++i )
	{
		pair<set<int>::iterator,bool> result = setB.insert( A[i] );
		if( result.second == false ) ++c; 
	}
	return c;
}

int main ()
{
	string line1, line2;
	while( getline( cin, line1 ) )
	{
		getline( cin, line2 );
		stringstream line1Stream( line1 );
		stringstream line2Stream( line2 );
		int N;
		vector<int> setA;
		vector<int> setB;
		while( line1Stream >> N ) setA.push_back( N );
		while( line2Stream >> N ) setB.push_back( N );
		int sizeA = setA.size();
		int sizeB = setB.size();
		int aToB = subset( setA, setB, sizeA, sizeB );
		int bToA = subset( setB, setA, sizeB, sizeA );
		if( aToB == 0 && bToA == 0 )
			cout << "A and B are disjoint" << endl;
		else if( aToB == bToA && sizeA == sizeB && aToB == sizeB )
			cout << "A equals B" << endl;
		else if( aToB == bToA && ( aToB == sizeA || bToA == sizeB ) )
		{
			if( sizeA > sizeB ) 
				cout << "B is a proper subset of A" << endl;
			else
				cout << "A is a proper subset of B" << endl;
		}
		else
			cout << "I'm confused!" << endl;
	}
}
