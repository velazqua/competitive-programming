/* Alex Velazquez
 * Start: Sun Apr 22 12:44:05 EDT 2012
 * End  : Sun Apr 22 13:32:28 EDT 2012
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

vector<pair<string,int> > genWords( string word, int l )
{
	vector<pair<string,int> > allWords;
	REP( i, l )
	{
		allWords.push_back( make_pair( word, i ) );
		char firstChar = word[0];
		word.erase( 0, 1 );
		word.append( 1, firstChar );
	}
	return allWords;
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		if( i != 0 )
			cout << endl;
		int l;
		string word ="", w;
		cin >> l;
		int m = 0;
		//cout << "l: " << l << endl;
		cin.ignore();
		while( getline( cin, w ) )
		{
			//cout << "w: " << w << endl;
			//if( m++ == 0 ) cin.ignore();
			if( !w.compare( "" ) )
				break;
			word += w;
		}
		//cout << "word: " << word << endl;
		vector<pair<string,int> > allWords = genWords( word, l );
		sort( allWords.begin(), allWords.end() );
		
		//look for S1
		int k = 0;
		for( vector<pair<string,int> >::iterator it=allWords.begin(); it!=allWords.end(); ++it )
		{
			if( it->second == 1 )
			{
				cout << k << endl;
				break;
			}
			++k;
		}
		if( k >= l )
			cout << 0 << endl;
		
		// string from last column
		string lastColString = "";
		REP( j, l )
			lastColString += allWords[j].first[l-1];
		
		// print 50 char per line
		while( lastColString.size() > 50 )
		{
			cout << lastColString.substr( 0, 50 ) << endl;
			lastColString.erase( 0, 50 );
		}
		cout << lastColString << endl;
	}
}
