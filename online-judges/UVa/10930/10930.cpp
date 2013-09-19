/* Alex Velazquez
 * Start: Tue Apr  3 18:45:26 EDT 2012
 * End  : Tue Apr  3 20:08:15 EDT 2012
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

int sumToX( int X, int i, vector<int> &nums, vector<vector<int> > &DP )
{
	//cout << "f: " << X << " " << i << endl;
	if(X >= 0 && X<=1000 && i >= 0 && i <= 30 && DP[X][i] != -1 )
	{
		//cout << "1) DP[" << X << "][" << i << "]=" << DP[X][i] << endl;
		return DP[X][i];
	}
	else if( i == 0 )
	{
		DP[X][i] = ( nums[i] == X ) ? 1: 0; 
		//cout << "2) DP[" << X << "][" << i << "]=" << DP[X][i] << endl;
		return DP[X][i];
	}
	else
	{
		DP[X][i] = (( sumToX( X, i-1, nums, DP ) ) ||		
			   ( nums[i] == X ) ||  
			   ( sumToX( (( X-nums[i] >= 0 ) ? X-nums[i]:X ), i-1, nums, DP ) ) ); 
		//cout << "3) DP[" << X << "][" << i << "]=" << DP[X][i] << endl;
		return DP[X][i];
	}
}

int main ()
{
	int N;
	int c = 1;
	while( cin >> N )
	{
		vector<int> nums( N );
		set<int> isIn;
		cout << "Case #" << c++ << ":";
		int higher = 0;
		bool exitEarly = false;
		REP( i, N )
		{
			cin >> nums[i];
			if( nums[i] < 0 )
				exitEarly = true;
			if( nums[i] > higher )
				higher = nums[i];
			else
				exitEarly = true;
			cout << " " << nums[i];
			isIn.insert( nums[i] );
		}
		cout << endl;
		if( nums.size() != isIn.size() || exitEarly )
		{
			cout << "This is not an A-sequence." << endl;
		}
		else
		{
			vector<vector<int> > DP( 1011, vector<int>( 41, -1 ) );
			int size = nums.size();
			bool found = true;
			REP( i, size )
				DP[nums[i]][i] = 1;
			FOR( i, 1, size )
			{
				//cout << nums[i] << " " << i-1 << endl;
				if( sumToX( nums[i], i-1, nums, DP ) == 1 )
				{
					cout << "This is not an A-sequence." << endl;
					found = false;
					break;
				}
			} 
			if( found )
			{
				cout << "This is an A-sequence." << endl;
			}
		}
		
	}
}
