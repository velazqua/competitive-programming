/* Alex Velazquez
 * Start: Sun Aug  5 22:27:05 EDT 2012
 * End  : Sun Aug  5 23:27:49 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	string nos = "n";
	string vos = "v";
	nos += char(243);
	vos += char(243);
	nos += "s       ";
	vos += "s       ";
	vector<string> pronouns;
	pronouns.PB( "eu        " );
	pronouns.PB( "tu        " );
	pronouns.PB( "ele/ela   " );
	pronouns.PB( nos );
	pronouns.PB( vos );
	pronouns.PB( "eles/elas " );
	
	
	int tc = 0;
	string line;
	while( getline( cin, line ) )
	{
		string verb, englishVerb;
		stringstream ss( line );
		ss >> verb;
		int tokens = 0;
		string token;
		while( ss >> token )
		{
			if( tokens == 0 )
				tokens ++;
			else
				englishVerb += ' ';

			englishVerb += token;
		}
		
		if( tc != 0 )
			cout << endl;
		tc++;
		cout << verb << " (to " << englishVerb << ")" << endl;
		int size = SZ( verb );
		if( size < 2 )
			cout << "Unknown conjugation" << endl;
		else
		{
			string root = "";
			REP( i, size-2 )
				root += verb[i];
			string conjugation = "";
			conjugation += verb[size-2];
			conjugation += verb[size-1];
			vector<string> tv( 3, "" );
			tv[0] = "a";
			tv[1] = "e";
			tv[2] = "i";
			if( !conjugation.compare( "ar" ) || !conjugation.compare( "er" ) )
			{
				int num = ( ( !conjugation.compare( "ar" ) ) ? 0 : 1 );
				REP( i, SZ( pronouns ) )
				{
					if( i == 3 )
					{
						cout << "n";
						putchar(243);
						cout << "s       ";
						cout << root;
					}	
					else if( i == 4 )
					{
						cout << "v";
						putchar(243);
						cout << "s       ";
						cout << root;
					}
					else
						cout << pronouns[i] << root;
					
					if( i == 0 )
						cout << "o" << endl;
					else
					{
						cout << tv[num];
						if( i == 1 )
							cout << "s";
						else if( i == 3 )
							cout << "mos";
						else if( i == 4 )
							cout << "is";
						else if( i == 5 )
							cout << "m";
						cout << endl;
					}
				}
			}
			else if( !conjugation.compare( "ir" ) )
			{
				REP( i, SZ( pronouns ) )
				{
					if( i == 3 )
					{
						cout << "n";
						putchar(243);
						cout << "s       ";
						cout << root;
					}	
					else if( i == 4 )
					{
						cout << "v";
						putchar(243);
						cout << "s       ";
						cout << root;
					}
					else
						cout << pronouns[i] << root;
					
					if( i == 0 )
						cout << "o" << endl;
					else
					{
						if( i == 3 || i == 4 )
							cout << tv[2];
						if( i == 1 )
							cout << "es";
						else if( i == 2 )
							cout << "e";
						else if( i == 3 )
							cout << "mos";
						else if( i == 4 )
							cout << "s";
						else if( i == 5 )
							cout << "em";
						cout << endl;
					}
				}
			}
			else
				cout << "Unknown conjugation" << endl;
		}
		
	}
}
