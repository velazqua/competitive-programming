/* Alex Velazquez
 * Start: Tue Mar 27 23:56:07 EDT 2012
 * End  : Wed Mar 28 00:23:52 EDT 2012
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
#include <cctype>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

string tolowercase( string S )
{
	int size = S.size();
	string newS = "";
	REP( i, size )
	{
		int X = S[i]-'A'; 
		if( X >= 0 && X <= 25 )
			newS += S[i]+32;
		else
			newS += S[i];
	}
	return newS;
}

int main ()
{
	string word="", line;
	set<string> allWords;
	while( getline( cin, line ) )
	{
		//cout << "line: " << line << endl;
		word = "";
		int size = line.size();
		//cout << "size: " << size << endl;
		REP( c, size )
		{
			if( isalpha( line[c] ) )
				word += line[c];
			else
			{
				//cout << "word: " << word << endl;
				if( (int)word.size() != 0 )
					allWords.insert( tolowercase( word ) );
				word = "";
			}
		}
			
		if( (int)word.size() != 0 )
			allWords.insert( tolowercase( word ) );
	}	
	for( set<string>::iterator it=allWords.begin(); it!=allWords.end(); ++it )
		cout << *it << endl;
}
