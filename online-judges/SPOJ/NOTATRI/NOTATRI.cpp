/* Alex Velazquez
 * Start: November 07, 2011 @ 10:00PM
 * End  : November 07, 2011 @ 10:36PM (Wrong Answer)
 * 		  November 07, 2011 @ 10:43PM (Accepted Answer)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define DEBUG 0

using namespace std;

int main ()
{
	int N;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		set<int> distinctNums;
		vector<int> nums;
		int t;
		for( int i=0; i<N; ++i )
		{
			cin >> t;
			//distinctNums.insert( t );
			nums.push_back( t ) ; 
		}
		//vector<int> nums( distinctNums.begin(), distinctNums.end() );
		sort( nums.begin(), nums.end() );
		int s = nums.size();
		vector<int>::iterator upBound;
		int ways = 0;
		for( int i=0; i<s-2; ++i )
		{
			for( int j=i+1; j<s-1; ++j )
			{
				#if DEBUG
					cout << nums[i] << " " << nums[j] << " ";
				#endif
				upBound = upper_bound( 	nums.begin()+j,
										nums.end(),
										nums[i]+nums[j] );
				#if DEBUG
					cout << "upBound: " << *upBound;
					cout << ". pos: " << int(upBound - nums.begin());
					cout << ". ways+= " << s-int(upBound - nums.begin()) << endl;
				#endif
				ways += s-int(upBound - nums.begin());
			}
		}
		cout << ways << endl;
	}
}
