/* Alex Velazquez
 * Start: Mon Apr  2 22:41:58 EDT 2012
 * End  : Mon Apr  2 23:07:34 EDT 2012
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
	int numTeams;
	int i = 1;
	while( cin >> numTeams )
	{
		if( numTeams == 0 ) break;
		int numElements;
		cout << "Scenario #" << i++ << endl;
		vector<set<int> > teamQs;
		REP( i, numTeams )
		{
			cin >> numElements;
			set<int> e;
			int num;
			REP( j, numElements )
			{
				cin >> num;
				e.insert( num );
			}
			teamQs.push_back( e );
		}
		string COMMAND;
		deque<pair<set<int>,deque<int> > > teamQueue;
		while( cin >> COMMAND )
		{
			if( !COMMAND.compare( "STOP" ) )
				break;
			if( !COMMAND.compare( "ENQUEUE" ) )
			{
				int num;
				cin >> num;
				// look for a team
				int size = teamQueue.size();
				bool found = false;
				REP( k, size )
				{
					if( teamQueue[k].first.count( num ) > 0 )
					{
						found = true;
						teamQueue[k].first.insert( num );
						teamQueue[k].second.push_back( num );
					}
				}
				if( !found )
				{
					deque<int> dq;
					dq.push_back( num );
					set<int> s;
					REP( k, numTeams )
					{
						if( teamQs[k].count( num ) > 0 )
						{
							teamQueue.push_back( make_pair( teamQs[k], dq ) );
							break;
						}
					}  
				}
			}
			else
			{
				// output element and delete from teamQueue
				REP( k, numTeams )
				{
					if( (int)teamQueue[k].second.size() > 0 )
					{
						cout << teamQueue[k].second[0] << endl;
						teamQueue[k].second.pop_front();
						if( teamQueue[k].second.size() == 0 )
							teamQueue.pop_front();
						break;
					}
				}
			}
		}
		cout << endl;
	}
}
