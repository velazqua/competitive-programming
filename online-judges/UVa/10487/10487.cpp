/* Alex Velazquez
 * Start: Wed Jan  4 22:06:51 EST 2012
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
	int N;
	int c = 1;
	while( cin >> N )
	{
		if( N == 0 )
			break;
		
    set<int> nums;
		for( int i=0; i<N; ++ i ) {
      int num;
			cin >> num;
      nums.insert(num);
    }
		int Q;
		cin >> Q;
		cout << "Case " << c++ << ":" << endl;
		for( int i=0; i<Q; ++i )
		{
			int t;
			cin >> t;
			cout << "Closest sum to " << t << " is ";
      int minn = 2147000000;
      for(set<int>::iterator num = nums.begin(); 
          num != nums.end();
          num++) {
        set<int>::iterator it = lower_bound(nums.begin(), nums.end(), t-*num ), p;
        int val = *num+*it;
        if (it != nums.begin()) {
          p = it;
          p--;
          if (abs(*num+*p-t) < abs(*num+*it-t))
            val = *num+*p;
        }
        minn = min(minn, val);
      }
      cout << minn << endl;
    }
	}
}
