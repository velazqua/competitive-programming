/* Alex Velazquez
 * Start: Mon Jan  2 21:30:16 EST 2012
 * End  :
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
#include <string>

using namespace std;

int main ()
{
	// precompute the values on top
	vector<int> nums;
	for( int i=1; i<100000; i+=2 )
	{
		if( i*(i+1)/2 > 10000000 )
			break;
		nums.push_back( i*(i+1)/2 );
		nums.push_back( i*(i+1)/2+1 );
	}
	int n = 8;
	vector<int>::iterator low = lower_bound( nums.begin(), nums.end(), n );
	int D = int( low-nums.begin() );
	cout << D << " " << *low << endl;
	/*
	int N;
	while( cin >> N )
	{
		
	}
	*/
}
