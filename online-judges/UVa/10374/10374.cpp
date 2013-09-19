/* Alex Velazquez
 * Start: Mon Mar 26 23:31:50 EDT 2012
 * End  : Mon Mar 26 23:56:46 EDT 2012
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
		if( i != 0 )
			cout << endl;
		int C;
		cin >> C;
		string candidateName, candidateParty;
		map<string,string> party;
		map<string,int> votes;
		REP( k, C )
		{
			if( k == 0 ) cin.ignore();
			while( 1 )
			{
				getline( cin, candidateName );
				if( candidateName.compare( "" ) )
					break;
			}
			while( 1 )
			{
				getline( cin, candidateParty );
				if( candidateParty.compare( "" ) )
					break;
			}
			//cout << candidateName << " - " << candidateParty << endl;
			party[candidateName] = candidateParty;
		}
		int V;
		cin >> V;
		REP( k, V )
		{
			if( k == 0 ) cin.ignore();
			while( 1 )
			{
				getline( cin, candidateName );
				if( candidateName.compare( "" ) )
					break;
			}
			votes[candidateName]++;
		}
		int maxx = 0;
		string maxCandidate;
		vector<int> countVotes( V );
		int k = 0;
		for( map<string,int>::iterator it=votes.begin(); it!=votes.end(); ++it )
		{
			countVotes[k++] = it->second;
			//cout << it->first << " " << it->second << endl;
			if( it->second > maxx )
			{
				maxx = it->second;
				maxCandidate = it->first;
			}
		}
		sort( countVotes.begin(), countVotes.end(), greater<int>() );
		//cout << maxx << endl;
		int size = countVotes.size();
		if( size == 0 || ( size >= 2 && countVotes[0] == countVotes[1] ) )
			cout << "tie" << endl;
		else
			cout << party[maxCandidate] << endl;
	}
}
