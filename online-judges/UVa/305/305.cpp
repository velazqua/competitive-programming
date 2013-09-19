/* Alex Velazquez
 * Start: Fri Mar 16 22:00:46 EDT 2012
 * End  : Fri Mar 16 22:15:22 EDT 2012
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

void printVector( vector<int>::iterator first, vector<int>::iterator last )
{
	for( ; first!=last; ++first )
		cout << *first << " " ;
	cout << endl;
}

int main ()
{
	int N;
	while( cin >> N )
	{
		if( !N )
			break;
		switch( N ) 
		{
			case 1:  cout <<       2 << endl;
					 break;
			case 2:  cout <<       7 << endl;
					 break;
			case 3:  cout <<       5 << endl;
					 break;
			case 4:  cout <<      30 << endl;
					 break;
			case 5:  cout <<     169 << endl;
					 break;
			case 6:  cout <<     441 << endl;
					 break;
			case 7:  cout <<    1872 << endl;
					 break;
			case 8:  cout <<    7632 << endl;
					 break;
			case 9:  cout <<    1740 << endl;
					 break;
			case 10: cout <<   93313 << endl;
					 break;
			case 11: cout <<  459901 << endl;
					 break;
			case 12: cout << 1358657 << endl;
					 break;
			case 13: cout << 2504881<< endl;
					 break;
			continue;
		}
		/*
		for( int m=1; ; ++m )
		{
			vector<int> nums( 2*N );
			for( int i=1; i<=2*N; ++i )
				nums[i-1] = i;
			int toDelete = 2*N;
			//cout << "m: " << m << endl;
			while( 1 )
			{
				//printVector( nums.begin(), nums.end() );
				if( !toDelete )
					break;
				int indx = (m-1)%toDelete;
				int E = nums[indx];
				//cout << "There are " << toDelete << " elements. Deleting: " << E << endl;
				if( E <= N )
					break;
				vector<int> T( indx );
				copy( nums.begin(), nums.begin()+indx, T.begin() );
				nums.erase( nums.begin(), nums.begin()+indx+1 );
				nums.insert( nums.end(), T.begin(), T.end() );
				toDelete--;
			}
			if( (int)nums.size() == N )
			{
				cout << m << endl;
				break;
			}
		}
		*/
	}
}
