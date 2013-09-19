/* Alex Velazquez
 * Start: Sun Apr 15 13:54:53 EDT 2012
 * End  : Sun Apr 15 15:02:35 EDT 2012
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

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		if( i == 0 )
			cin.ignore();
		string line;
		getline( cin, line );
		vector<LL> nums;
		vector<char> ops;
		int lineSize = line.size();
		LL num = 0LL;
		REP( c, lineSize )
		{
			if( line[c] == '+' || line[c] == '*' )
			{
				nums.push_back( num );
				ops.push_back( line[c] );
				num = 0LL;
			}
			else
			{
				if( num != 0LL )
					num *= 10LL;	
				num += line[c]-'0';
				if( c == lineSize-1 )
					nums.push_back( num );
			}
		}
		int sizeOps = ops.size();
		if( sizeOps == 0 )
		{
			cout << "The maximum and minimum are " << nums[0] << " and " << nums[0] << "." << endl;
			continue;
		}
		
		// get minimum
		LL minn = 0LL;
		vector<LL> newNums = nums;
		LL prod = 1LL;
		bool mult = false;
		int numsSize = nums.size();
		LL lastElement = nums[numsSize-1];
		if( *(ops.end()-1) == '+' )
			minn += lastElement;
		else
			nums[numsSize-2] *= lastElement;
		nums.erase( nums.end()-1 );
		REP( j, ops.size() )
		{
			if( ops[j] == '+' )
			{
				minn += ( mult ) ? prod*nums[j] : nums[j];
				mult = false;
				prod = 1LL;
			}
			else
			{
				mult = true;
				prod *= nums[j];
				if( j == (int)ops.size()-1 )
					minn += prod;
			}
		}
		// get maximum
		LL maxx = 1LL;
		nums = newNums;
		LL summ = 0LL;
		bool sumNow = false;
		numsSize = nums.size();
		lastElement = nums[numsSize-1];
		if( *(ops.end()-1) == '+' )
			nums[numsSize-2] += lastElement;
		else
			maxx *= lastElement;
		nums.erase( nums.end()-1 );
		REP( j, ops.size() )
		{
			if( ops[j] == '*' )
			{
				maxx *= ( sumNow ) ? summ+nums[j] : nums[j];
				sumNow = false;
				summ = 0LL;
			}
			else
			{
				sumNow = true;
				summ += nums[j];
				if( j == (int)ops.size()-1 )
					maxx *= summ;
			}
		}
		cout << "The maximum and minimum are " << maxx << " and " << minn << "." << endl;
	}
}
