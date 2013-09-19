/* Name: Alex Velazquez
 * Start Date: September 19, 2011 @ 10:10PM
 * End Date:   September 17, 2011 @ 10:13PM
 * Purpose: To solve the SPOJ problem #500 - "Turbo Sort"
 * Link: https://www.spoj.pl/problems/TSORT/
 * */
#include <cstdio>
#include <set>

using namespace std;

int main ()
{
	set<int> nums;
	int T, N;
	scanf("%d",&T);
	for (int i=0;i<T;++i)
	{
		scanf("%d",&N);
		nums.insert(N);
	}
	for(set<int>::iterator it=nums.begin();it!=nums.end();++it)
		printf("%d\n",*it);
}
