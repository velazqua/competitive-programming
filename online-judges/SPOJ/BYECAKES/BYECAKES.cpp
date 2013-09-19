/* Alex Velazquez
 * Start: October 29, 2011 @ 04:53PM
 * End  : October 29, 2011 @ 05:30PM
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
	while( 1 )
	{
		vector<int> nums;
		vector<int> divs;
		int n;
		bool end = true;
		int highDiv = 0;
		bool nothing = true;
		for( int i=0; i<8; ++i )
		{
			cin >> n;
			if( n != -1 )
				end = false;
			if( n != 0 && i < 4)
				nothing = false;
			nums.push_back( n );
			if( i > 3 )
			{
				int k = ceil( nums[i-4]/(double)n );
				k = ( k == 0 ) ? 1 : k;
				if( k > highDiv )
					highDiv = k;
				divs.push_back( k );
			}
		}
		if( end )
			break;
		if( nothing )
		{
			cout << "0 0 0 0" << endl;
			continue;
		}
		for( int i=0; i<4; ++i )
			cout << (( i == 0 )?"":" ") << highDiv*nums[i+4]-nums[i];
		cout << endl;
		
	}
}
