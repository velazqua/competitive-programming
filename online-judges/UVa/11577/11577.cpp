/* Alex Velazquez
 * Start: Sat Jan 14 00:40:48 EST 2012
 * End  : Sat Jan 14 01:16:12 EST 2012
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
#include <functional>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;

using namespace std;

struct Freq {
	char letter;
	int occurrance;
	Freq( char l, int o ) : letter( l ), occurrance( o ) {}
};

bool operator < ( Freq const& A, Freq const& B ) 
{
	if( A.occurrance > B.occurrance )
		return true;
	else if( A.occurrance < B.occurrance )
		return false;
	else
		return ( A.letter < B.letter ) ? true : false;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		if( i == 0 )
			cin.ignore();
		string line;
		getline( cin, line );
		set<Freq> L;
		map<char,int> freq;
		#if DEBUG
			cout << "line: " << line << endl;
		#endif
		int size = line.size();
		REP( j, size )
		{
			if( line[j] >= 65 && line[j] <= 90 )
				++freq[char(line[j]+(97-65))];
			else if( line[j] >= 97 && line[j] <= 122 )
				++freq[char(line[j])];
		}
		
		map<char,int>::iterator it = freq.begin(), itEnd = freq.end();
		for( ; it != itEnd; ++it )
			L.insert( Freq( it->first, it->second ) );
		set<Freq>::iterator sIt = L.begin(), sItEnd = L.end();
		int maxx = sIt->occurrance;
		cout << sIt->letter;
		++sIt;
		for( ; sIt != sItEnd; ++sIt )
		{
			if( maxx == sIt->occurrance )
				cout << sIt->letter;
			else
				break;
		}
		cout << endl;
		
	}
}
