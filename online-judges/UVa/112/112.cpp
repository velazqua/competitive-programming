/* Alex Velazquez
 * Start: Sat Mar 31 20:50:13 EDT 2012
 * End  : Sat Mar 31 22:52:10 EDT 2012
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

int countChar( char c, string const& S, int const& size )
{
	int counter = 0;
	REP( i, size )
		if( S[i] == c )
			++counter;
	return counter;
}

bool treeTrace( stringstream &ss, vector<int> &T, int currSum )
{
	if( ss.rdbuf()->in_avail() == 0 )
		return false;
	char leftBracket;
	ss >> leftBracket;
	int integer;
	ss >> integer;
	bool leftTree;
	if( ss.fail() )
	{
		ss.clear();
		char otherBracket;
		ss >> otherBracket;
		return false;
	}
	else
	{
		leftTree = treeTrace( ss, T, currSum+integer );
	}
	bool rightTree = treeTrace( ss, T, currSum+integer );
	if( !leftTree && !rightTree )
	{
		T.push_back( currSum+integer );
	}
	char rightBracket;
	ss >> rightBracket;
	return true;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		int numLeftBrackets = 0;
		int numRightBrackets = 0;
		string tree = "";
		string S;
		do
		{
			cin >> S;
			tree += S;
			int size = S.size();
			numLeftBrackets += countChar( '(', S, size );
			numRightBrackets += countChar( ')', S, size );	   
		} while( numLeftBrackets != numRightBrackets );
		vector<int> rootToLeaf;
		stringstream ss( tree );
		treeTrace( ss, rootToLeaf, 0 );
		int size = rootToLeaf.size();
		bool found = false;
		REP( i, size )
		{
			//cout << rootToLeaf[i] << endl;
			if( rootToLeaf[i] == N ) 
				found = true;
		}
		cout << ( ( found ) ? "yes" : "no" ) << endl;
		
	} 
}
