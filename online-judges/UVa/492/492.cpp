/* Alex Velazquez
 * Start: Fri May 11 19:58:20 EDT 2012
 * End  : Fri May 11 20:15:38 EDT 2012
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

bool isLetter( char a )
{
	if( (a >= 'a' && a <= 'z' ) 
				|| (a >= 'A' && a <= 'Z' ) )
		return true;
	else
		return false;
}

int main ()
{
	string line;
	while( getline( cin, line ) )
	{
		line.append( "\n" );
		bool startWord = true;
		int size = line.size();
		set<char> vowels;
		string v = "aeiouAEIOU";
		REP( i, v.size() )
			vowels.insert( v[i] );
		string wordAppend = "";
		string actualWord = "";
		REP( i, size )
		{
			if( startWord && vowels.find( line[i] ) != vowels.end() )
			{
				actualWord += line[i];
				wordAppend += "ay";
				startWord = false;
			}
			else if( !startWord && vowels.find( line[i] ) != vowels.end() )
			{
				actualWord += line[i];
			}
			else if( startWord && isLetter( line[i] ) )
			{
				wordAppend += line[i];
				wordAppend += "ay";
				startWord = false;
			}
			else if( !startWord && isLetter( line[i] )  )
			{
				actualWord += line[i];
			}
			else
			{
				cout << actualWord;
				cout << wordAppend; 
				cout << line[i];
				startWord = true;
				wordAppend = "";
				actualWord = "";
			}
		}
	}
}
