/* Alex Velazquez
 * Start: Thu Apr 19 20:06:48 EDT 2012
 * End  : Thu Apr 19 20:43:08 EDT 2012
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

struct Word {
	string W;
	Word( string w ) : W(w) {} 
};

bool operator <( Word const& A, Word const& B )
{
	int S1 = A.W.size();
	int S2 = B.W.size();
	if( S1 > S2 )
		return true;
	else if( S1 < S2 )
		return false;
	else
		return  (( A.W.compare( B.W ) < 0 ) ? true : false );
}

int main ()
{
	int F, N;
	while( cin >> F >> N )
	{
		vector<string> fingers;
		set<int> Fs;
		int t;
		REP( i, F )
		{
			cin >> t;
			Fs.insert( t );
		}
		fingers.push_back( "" );
		fingers.push_back( "qaz" );
		fingers.push_back( "wsx" );
		fingers.push_back( "edc" );
		fingers.push_back( "rfvtgb" );
		fingers.push_back( " " );
		fingers.push_back( " " );
		fingers.push_back( "yhnujm" );
		fingers.push_back( "ik," );
		fingers.push_back( "ol." );
		fingers.push_back( "p;/" );
		set<char> A;
		REP( i, fingers.size() )
			REP( j, fingers[i].size() )
				if( Fs.count( i ) == 0 )
					A.insert( fingers[i][j] );
		string word;
		set<Word> Words;
		REP( i, N )
		{
			cin >> word;
			bool canType = true;
			REP( j, word.size() )
			{
				if( A.count( word[j] ) == 0 )
				{
					canType = false;
					break;
				}
			}
			if( canType )
				Words.insert( Word( word ) );
		}
		int size = Words.size();
		//cout << "size: " << size << endl;
		if( size == 0 )
		{
			cout << 0 << endl;
			continue;
		}
		int maxx = Words.begin()->W.size();
		int count = 0;
		string answer = "";
		for( set<Word>::iterator it=Words.begin();it!=Words.end();++it)
		{
			if( (int)it->W.size() == maxx )
			{
				++count;
				answer += it->W + "\n";
			}
		}	
		cout << count << endl;
		cout << answer;
	}
}
