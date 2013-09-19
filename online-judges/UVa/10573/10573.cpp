/* Alex Velazquez
 * Start: Tue Jan 17 22:18:40 EST 2012
 * End  :
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

#define PI 3.14159265
#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

double toDouble( string S )
{
	istringstream ss(S);
	double val;
	ss >> val;
	return val;
}

int main ()
{
	int N;
	cin >> N;
	REP( i, N )
	{
		string line;
		if( i == 0 )
			cin.ignore();
		getline( cin, line );
		stringstream newLine( line );
		string token;
		//cout << "line:" << line << endl;
		vector<string> vals;
		while( getline( newLine, token, ' ' ) )
		{
			vals.push_back( token );
			//cout << "token: " << token << endl;
		}
		if( vals.size() == 1 )
			cout << "IMPOSSIBLE" << endl;
		else
		{
			double r1 = toDouble(vals[0]), r2 = toDouble(vals[1]);
			double r3 = (2*r1+2*r2)/2.0;
			printf( "%.4f\n", 2*acos(0)*(r3*r3-r1*r1-r2*r2) );
		}
	}
}
