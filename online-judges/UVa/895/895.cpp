/* Alex Velazquez
 * Start: Sun Jan 15 21:11:12 EST 2012
 * End  : Sun Jan 15 22:04:32 EST 2012
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

int main ()
{
	multimap<string,vector<int> > dict;
	string word;
	while( cin >> word )
	{
		if( word[0] == '#' )
			break;
		vector<int> temp( 26, 0 );
		REP( i, word.size() )
			temp[word[i]-'a']++;
		dict.insert( pair<string,vector<int> >( word, temp ) );
	}
	string line;
	getline( cin, line );
	while( getline( cin, line ) )
	{
		if( line[0] == '#' )
			break;
		stringstream newLine( line );
		string possibleWords;
		string token;
		vector<int> tokens( 26 );
		while( getline( newLine, token, ' ' ) )
			tokens[token[0]-'a']++;
	
		// loop through all words
		int counter = 0;
		for( map<string,vector<int> >::iterator it=dict.begin();it!=dict.end();++it)
		{
			// check that all digits match
			bool found = true;
			REP( j, 26 )
			{
				if( it->second[j] > tokens[j] )
				{
					found = false;
					break;
				}
			}
			if( found )
				++counter;
		}
		cout << counter << endl;
	}
}
