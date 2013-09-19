/* Alex Velazquez
 * Start: Thu Sep 27 21:58:39 EDT 2012
 * End  :
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define SZ(A) (A).size()

typedef long long int LL;

string sortNum3(LL N)
{
	vector<int> nums(10,0);
	while(N)
	{
		nums[N%10]++;
		N /= 10;
	}
	string S;
	REP(i,10)
		REP(j,nums[i])
			S += char(48+i);
	return S;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	map<string,vector<LL> > M;
	for( LL x = 1LL; x<1000000LL; ++x )
	{
		LL y = x*x;
		M[sortNum3(y)].push_back( y );
	}
	
	vector<LL> A;
	for(map<string,vector<LL> >::iterator it=M.begin();it!=M.end();++it)
		if(SZ(it->second)>1)
			for( vector<LL>::iterator it2 = it->second.begin(); it2!=it->second.end(); ++it2 )
				A.push_back( *it2 );
	sort(A.begin(),A.end());
	int X, Y;
	cin>>X>>Y;
	string S;

	REP(i,Y-X+1)
		cout << A[X+i-1] << "\n";
}
