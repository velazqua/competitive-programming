/* Name: Alex Velazquez
 * Start Date: September 03, 2011 @ 01:22AM
 * End Date:   ???
 * Purpose: To solve the Project Euler problem #88
 * Link: http://projecteuler.net/index.php?section=problems&id=88
 * */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef unsigned long long ULL;

void calcMinPS (vector<ULL> &minPS, ULL N, ULL &L, ULL &W, ULL currSum, ULL currMult, ULL currL)
{
	if (currL >= L) return;
	for (ULL k=N;k<W;++k)
	{
		if (currL+(k*currMult)-(k+currSum) <= 12000ULL && currMult*k < minPS[currL+(k*currMult)-(k+currSum)])
		{
			minPS[currL+(k*currMult)-(k+currSum)] = currMult*k;
		}
		calcMinPS(minPS,k,L,W,k+currSum,k*currMult,currL+1);
	}
}

int main ()
{
	set<ULL> uniq_nums;
	ULL W=16ULL, L=20ULL, H=11ULL;
	ULL inf=200000000ULL;
	vector<ULL> minPS;
	for (ULL i=0ULL;i<12001ULL;++i)
		minPS.push_back(inf); // initialize all values
	ULL LIMIT=6ULL;
	for (ULL i=2ULL;i<H+1;++i)
		calcMinPS(minPS,i,L,W,i,i,2);
	for (ULL i=2ULL;i<LIMIT+1;++i)
	{
		if (minPS[i] == inf)
		{
			cout << "k=" << i << ": " << minPS[i]<< endl;
			break;
		}
		uniq_nums.insert(minPS[i]);
	}
	
	ULL SUMM = 0ULL;
	ULL c=0;
	for (set<ULL>::iterator it = uniq_nums.begin(); it!=uniq_nums.end(); ++it)
	{
		++c;
		SUMM += *it;
	}
	cout << c << endl;
	cout << SUMM << endl;
}
