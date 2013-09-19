/* Alex Velazquez
 * Start: Mon Feb 20 19:18:55 EST 2012
 * End  : Mon Feb 20 19:42:42 EST 2012
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

struct Pilot {
	string name;
	int min;
	int sec;
	int ms;
	Pilot( string n, int mi, int s, int ms_ ) : name(n), min(mi), sec(s), ms( ms_ ) {}
};

string toLowercase( string S )
{
	int size = S.size();
	string newS = "";
	REP( i, size ) 
	{
		if( (int)S[i] >= 65 && (int)S[i] <=90 )
			newS += char((int)S[i]+32);
		else
			newS += S[i];
	}
	return newS;
}

bool comp( Pilot const& A, Pilot const& B )
{
	if( A.min < B.min ) return true;
	else if( A.min > B.min ) return false;
	else
	{
		if( A.sec < B.sec ) return true;
		else if( A.sec > B.sec ) return false;
		else
		{
			if( A.ms < B.ms ) return true;
			else if( A.ms > B.ms ) return false;
			else
			{
				string n1 = toLowercase( A.name );
				string n2 = toLowercase( B.name );
				if( n1.compare( n2 ) < 0 )
					return true;
				else
					return false;
			}
		}
	}
}

int main ()
{
	int N;
	while( cin >> N )
	{
		vector<Pilot> P;
		REP( i, N )
		{
			string name;
			int min, sec, ms;
			string t;
			cin >> name >> t >> min >> t >> sec >> t >> ms >> t;
			P.push_back( Pilot( name, min, sec, ms ) );
		}
		sort( P.begin(), P.end(), comp );
		int r = 1;
		REP( i, N )
		{
			if( i%2 == 0 )
				cout << "Row " << r++ << endl;
			cout << P[i].name << endl;
		}
		cout << endl;
	}
}
