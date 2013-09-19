/* Alex Velazquez
 * Start: Sat Nov 26 22:29:04 EST 2011
 * End  : Sat Aug 25 17:31:48 EDT 2012
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

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int checkWinner( vector< vector<int> > &vals, int N, int M, int K )
{
	// horizontal
	for( int i=0; i<M; ++i )
	{
		for( int j=0; j<N-K+1; ++j ) 
		{
			int result = vals[i][j];
			bool same = true;
			for( int x=0; x<K; ++x )
				same = same && ( result == vals[i][j+x] );
				
			if( same && result )
				return result;
		}
	}
	
	#if DEBUG
		cout << "No horizontal" << endl;
	#endif
	
	// vertical
	for( int i=0; i<M-K+1; ++i )
	{
		for( int j=0; j<N; ++j )
		{
			int result = vals[i][j];
			bool same = true;
			for( int x=0; x<K; ++x )
				same = same && ( result == vals[i+x][j] );
				
			if( same && result )
				return result;
		}
	}
	
	#if DEBUG
		cout << "No vertical" << endl;
	#endif
		
	// right down diagonals
	for( int i=0; i<M-K+1; ++i )
	{
		for( int j=0; j<N-K+1; ++j )
		{		
			int result = vals[i][j];
			bool same = true;
			for( int x=0; x<K; ++x )
				same = same && ( result == vals[i+x][j+x] );
				
			if( same && result )
				return result;
		}
	}
	
	#if DEBUG
		cout << "No right down diagonals" << endl;
	#endif
	
	// right up diagonals
	for( int i=K-1; i<M; ++i )
	{
		for( int j=0; j<N-K+1; ++j )
		{
			int result = vals[i][j];
			bool same = true;
			for( int x=0; x<K; ++x )
				same = same && ( result == vals[i-x][j+x] );
				
			if( same && result )
				return result;
		}
	}
	
	#if DEBUG
		cout << "No right up diagonals" << endl;
	#endif
	
	return 0;
}

int main ()
{
	int T;
	scanf( "%d\n", &T );
	int P1 = 0, P2 = 0;
	for( int i=0; i<T; ++i )
	{
		#if DEBUG
			cout << "===== Case #" << i+1 << " ========" << endl;
		#endif 
		int N, M, K;
		scanf( "%d %d %d\n", &N, &M, &K );
		vector<string> B;
		vector< vector<int> > vals( M, vector<int>( N, 0 ) );
		string line;
		for( int j=0; j<M; ++j )
		{
			cin >> line;
			for( int k=0; k<N; ++k )
				if( line[k] == 'x' )
					vals[j][k] = 1;
				else if( line[k] == 'o' )
					vals[j][k] = 2;
				else
					vals[j][k] = 0;
		}
		int isThereWinner = checkWinner( vals, N, M, K );
		if( isThereWinner == 1 )
			P1++;
		else if( isThereWinner == 2 )
			P2++;
		#if DEBUG
			cout << "Current game: " << P1 << ":" << P2 << endl;
		#endif
	}
	cout << P1 << ":" << P2 << endl;
}
