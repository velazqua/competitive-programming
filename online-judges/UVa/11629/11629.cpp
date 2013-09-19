/* Alex Velazquez
 * Start: Wed Mar 28 00:59:44 EDT 2012
 * End  :
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

int strToInt( string S ) 
{
	int val;
	istringstream ss( S );
	ss >> val;
	return val;
}

int main ()
{
	int p, g;
	cin >> p >> g;
	string party;
	double val;
	map<string,double> votes;
	REP( i, p )
	{
		cin >> party >> val;
		votes[party] = val;
	}
	
	REP( i, g )
	{
		if( i == 0 ) cin.ignore();
		string line;
		getline( cin, line );
		stringstream streamLine( line );
		string token;
		//cout << "line: " << line << endl;
		string comp;
		double summ = 0.0;
		int num;
		string comparators = "<=>=";
		while( streamLine >> token )
		{
			//cout << "token: " << token << endl;
			if( votes[token] ) // is it a party?
				summ += votes[token];
			else if( !token.compare( "+" ) )
				continue;
			else if( comparators.find( token ) != string::npos )
				comp = token;
			else
				num = strToInt( token );
		}
		cout << "Guess #" << i+1 << " was ";
		if( !comp.compare( "<" ) )
			cout << ( ( summ < num ) ? "correct" : "incorrect" );
		if( !comp.compare( "<=" ) )
			cout << ( ( summ <= num ) ? "correct" : "incorrect" );
		if( !comp.compare( ">" ) )
			cout << ( ( summ > num ) ? "correct" : "incorrect" );
		if( !comp.compare( ">=" ) )
			cout << ( ( summ >= num ) ? "correct" : "incorrect" );
		if( !comp.compare( "=" ) )
			cout << ( ( summ == num ) ? "correct" : "incorrect" );
		cout << "." << endl;
	}
}
