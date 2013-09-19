/* Alex Velazquez
 * Start: Fri Aug 17 00:38:49 EDT 2012
 * End  : Fri Aug 17 00:42:26 EDT 2012
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

pair<int,int> orientation( pair<int,int> P, bool r )
{
	if( r )
		return make_pair( P.second, P.first );
	else
		return P;
}

struct Point {
	int l;
	int w;
	Point( int L, int W ) : l(L), w(W) {}
};

bool operator < ( Point const& A, Point const& B )
{
	if( A.l < B.l ) 
		return true;
	else if( A.l > B.l )
		return false;
	else
		return A.w < B.w;
}

void updateAnswer( int l, int w, set<Point> &P, int &lowest )
{
	int A = l*w;
	if( A < lowest )
	{
		lowest = A;
		P.clear();
		P.insert( Point(min(l,w),max(l,w)) );
	}
	else if( A == lowest )
	{
		P.insert( Point(min(l,w),max(l,w)) );
	}
	else
	{
		// do nothing
	}
}

int main ()
{
	vector<pair<int,int> > recs;
	vector<int> perms( 4, 0 );
	for( int i=0; i<4; ++i )
	{
		int l, w;
		cin >> l >> w;
		recs.push_back( make_pair( l, w ) );
		perms[i] = i;
	}
	int lowest = 2000000000;
	set<Point> P;
	do
	{
		for( int i=0; i<16; ++i )
		{
			pair<int,int> valA = orientation( recs[perms[0]], ((i%2)?true:false));
			pair<int,int> valB = orientation( recs[perms[1]], (((i/2)%2)?true:false));
			pair<int,int> valC = orientation( recs[perms[2]], (((i/4)%2)?true:false));
			pair<int,int> valD = orientation( recs[perms[3]], ((i>=8)?true:false));
			int layout1_length = valA.first+valB.first+valC.first+valD.first;
			int layout1_width = max(valA.second,max(valB.second,max(valC.second,valD.second)));
			updateAnswer( layout1_length, layout1_width, P, lowest );
			int layout2_length = max(valA.first,valB.first+valC.first+valD.first);
			int layout2_width = valA.second+max(valB.second,max(valC.second,valD.second));
			updateAnswer( layout2_length, layout2_width, P, lowest );
			int layout3_length = max(valA.first,valB.first+valC.first)+valD.first;
			int layout3_width = max(valA.second+max(valB.second,valC.second),valD.second);
			updateAnswer( layout3_length, layout3_width, P, lowest );
			int layout4_length = valA.first+max(valB.first,valC.first)+valD.first;
			int layout4_width = max(valA.second,max(valD.second,valB.second+valC.second));
			updateAnswer( layout4_length, layout4_width, P, lowest );
			//int layout5_length = ;
			//int layout5_width = ;
			//updateAnswer( layout5_length, layout5_width, P, lowest );
			int layout6_length = max(valA.first+valB.first,valC.first+valD.first);
			if( valA.second>valB.second )
				layout6_length = max( layout6_length, valA.first+valD.first );
			else if( valA.second<=valB.second )
				layout6_length = max( layout6_length, valC.first+valB.first );
			int layout6_width = max(valA.second+valC.second,valB.second+valD.second);
			/*
			if( valA.first == 3 && valA.second == 6 && 
				valB.first == 5 && valB.second == 5 &&
				valC.first == 4 && valC.second == 3 &&
				valD.first == 4 && valD.second == 4 )
			{
				cout << "HELLO?!" << endl;
				cout << layout6_length << " " << layout6_width << endl;
			}
			*/
			updateAnswer( layout6_length, layout6_width, P, lowest );
		}
	} while( next_permutation( perms.begin(), perms.end() ) );
	cout << lowest << endl;
	for( set<Point>::iterator it=P.begin(); it!=P.end(); ++it )
	{
		cout << it->l << " " << it->w << endl;
	}

}
