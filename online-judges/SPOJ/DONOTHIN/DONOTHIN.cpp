/* Name: Alex Velazquez
 * Start Date: October 08, 2011 @ 09:20PM
 * End Date:   October 08, 2011 @ 09:23PM
 */

#include <iostream>

using namespace std;

typedef unsigned long long ULL;

int main ()
{
	int N, M;
	while (cin >> N >> M)
	{
		if (N == -1 && M == -1)
			break;
		ULL total = 0ULL, t, k=(ULL)N;
		for (int i=0;i<N;++i)
		{
			cin >> t;
			total += t*k;
			--k;
		}
		cout << (ULL)M*total << endl;
	}
}
