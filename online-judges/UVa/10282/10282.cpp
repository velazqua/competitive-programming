/* Alex Velazquez
 * Start: Mon Mar 26 23:01:52 EDT 2012
 * End  : Mon Mar 26 23:17:50 EDT 2012
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
	// read dictionary
	string line;
	map<string,string> M;
	while( getline( cin, line ) )
	{
		if( !line.compare( "" ) )
			break;
		stringstream streamLine( line );
		string englishWord, foreignWord;
		streamLine >> englishWord >> foreignWord;
		M[foreignWord] = englishWord;
	}
	string S;
	while( cin >> S )
	{
		string A = M[S];
		if( (int)A.size() != 0  )
			cout << A << endl;
		else
			cout << "eh" << endl;
	}
}
