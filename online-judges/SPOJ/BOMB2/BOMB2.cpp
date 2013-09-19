/* Name: Alex Velazquez
 * Start Date: September 17, 2011 @ 07:50PM
 * End Date:   September 17, 2011 @ 08:05PM (TLE)
 * Purpose: To solve the SPOJ problem #9512 - "Bombing"
 * Link: https://www.spoj.pl/problems/BOMB2/
 * */
#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main ()
{
	int N, M, x, y, c, d;
	while (1)
	{
		scanf("%d %d", &N, &M);
		//cin >> N >> M;
		if (N == 0 && M == 0)
			break;
			
		map<int,set<int> > X, Y;
		// bomb locations
		for (int i=0;i<N;++i)
		{
			scanf("%d %d", &x, &y);
			//cin >> x >> y;
			X[x].insert(y);
			Y[y].insert(x);
		}
		// strike locations
		for (int i=0;i<M;++i)
		{
			scanf("%d %d", &c, &d);
			//cin >> c >> d;
			if (c == 0) // x = d
			{
				printf("%d\n",(int)X[d].size());
				// now delete those co-ordinates from both maps
				for (set<int>::iterator it=X[d].begin();it!=X[d].end();++it)
					Y[*it].erase(d);
				X[d].clear();
			}
			else // x = d
			{
				printf("%d\n",(int)Y[d].size());
				// now delete those co-ordinates from both maps
				for (set<int>::iterator it=Y[d].begin();it!=Y[d].end();++it)
					X[*it].erase(d);
				Y[d].clear();
			}
		}
	}
}
