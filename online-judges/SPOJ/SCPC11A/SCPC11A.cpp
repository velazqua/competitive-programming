/* Name: Alex Velazquez
 * Start Date: October 22, 2011 @ 11:33PM
 * End Date:   October 22, 2011 @ ??:??PM
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int N, w;
	while( cin >> N >> w )
	{
		if( N == 0 && w == 0 )
			break;
		int n;
		int highest=0;
		vector<int> nums;
		for( int i=0; i<N; ++i)
		{
			cin >> n;
			if( n > highest )
				highest = n;
			nums.push_back(n);
		}
		int numIntervals = highest/w +1;
		vector<int> occIntervals(numIntervals);
		for( vector<int>::iterator it = nums.begin(); it != nums.end(); ++it )
		{
			++occIntervals[*it/w];
		}
		vector<int> occIHighest = occIntervals;
		sort( occIHighest.begin(), occIHighest.end() );
		double scale = *(occIHighest.end()-1);
		double summ = 0.01;
		int k = numIntervals-1;
		for( vector<int>::iterator it = occIntervals.begin(); it != occIntervals.end(); ++it )
		{
			//cout << k << "/" << (numIntervals-1) << " * ";
			//cout << *it << "/" << scale << endl;
			summ += ((double)k/(numIntervals-1))*(*it/scale);
			--k;
		}
		printf("%.6f\n", summ);
	}
}
