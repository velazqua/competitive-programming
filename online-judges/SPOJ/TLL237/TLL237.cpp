/* Alex Velazquez
 * Start: Fri Aug 17 00:50:33 EDT 2012
 * End  : Fri Aug 17 01:11:04 EDT 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	set< pair<int,int> > vp;
	REP( i, n )
		vp.insert( make_pair( 0, i ) );
	int size = SZ( s );
	REP( i, size )
	{
		set< pair<int,int> >::iterator smallest = vp.begin(), secondSmallest = vp.begin();
		++secondSmallest;
		/*
		cout << "========" << endl;
		for( set< pair<int,int> >::iterator it=vp.begin(); it!=vp.end(); ++it )
			cout << it->first << " " << it->second << endl;
		cout << "========" << endl;
		cout << endl;
		*/
		if( s[i] == '1' )
		{
			int indx = smallest->second;
			int val = smallest->first + 1;
			vp.erase( smallest );
			vp.insert( make_pair( val, indx ) );
		}
		else
		{
			int indx = secondSmallest->second;
			int val = secondSmallest->first + 1;
			vp.erase( secondSmallest );
			vp.insert( make_pair( val, indx ) );
		}
	}
	set< pair<int,int> >::iterator smallest = vp.begin(), secondSmallest = vp.begin();
	secondSmallest++;
	cout << smallest->first << " " << secondSmallest->first << endl;
}
