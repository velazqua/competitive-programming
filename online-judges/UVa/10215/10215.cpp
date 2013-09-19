/* Alex Velazquez
 * Start: Tue Jan 17 23:14:03 EST 2012
 * End  : Wed Jan 18 00:52:05 EST 2012
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
#define EPS 1e-8

typedef long long int LL;

using namespace std;

int main ()
{
	double L, W;
	while( cin >> L >> W )
	{
		double D = L+W;
		double X1 = (4*D+sqrt(16*D*D-48*L*W))/24.0;
		double X2 = (4*D-sqrt(16*D*D-48*L*W))/24.0;
		map<double,double> Vs;
		double V1 = (L-2*X1)*(W-2*X1)*(X1);
		double V2 = (L-2*X2)*(W-2*X2)*(X2);
		//cout << X1 << ":" << Vs[X1] << " " << X2 << " :" << Vs[X2] << endl;
		
		Vs[X1] = (V1<EPS)?0.0:V1;
		Vs[X2] = (V2<EPS)?0.0:V2;
		Vs[0.0] = 0.0;
		//cout << X1 << ":" << Vs[X1] << " " << X2 << " :" << Vs[X2] << endl;
		double maxx = (Vs[X1]>Vs[X2])?X1:(Vs[X2]>Vs[0.0])?X2:0.0;
		double minn = (Vs[X1]<Vs[X2])?X1:(Vs[X2]<Vs[0.0])?X2:0.0;
		printf( "%.3f ", maxx+EPS );
		if( V2 < 0.0 )
		{
			printf("0.000\n");
		}
		else
		{
			printf("0.000 %.3f\n", min(L,W)/2.0+EPS );
		}
	}
}
