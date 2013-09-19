/* Name: Alex Velazquez
 * Start Date: October 22, 2011 @ 07:39PM
 * End Date:   October 22, 2011 @ 07:43PM
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int x, y, z;
	while( cin >> x >> y >> z )
	{
		vector<int> nums;
		if( x == 0 && y == 0 && z == 0 )
		{
			break;
		}
		nums.push_back(x);
		nums.push_back(y);
		nums.push_back(z);
		sort( nums.begin(), nums.end() );
		if( nums[0]*nums[0] + nums[1]*nums[1] == nums[2]*nums[2] )
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
}
