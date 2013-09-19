
#include <stdio.h>

using namespace std;

int main ()
{
	int numBanks,c=0,t,totalCost,reducedCost;
	while (1)
	{
		scanf("%d",&numBanks);
		if (numBanks == 0)
			break;
		
		int B[numBanks];
		for (int i=0;i<numBanks;++i)
			B[i]=0;
		
		totalCost=0; reducedCost=0;
		for (int i=0;i<numBanks;++i)
		{
			for (int j=0;j<numBanks;++j)
			{
				scanf("%d",&t);
				totalCost += t;
				B[i] -= t;
				B[j] += t;
			}
		}
		
		++c;
		for (int i=0;i<numBanks;++i)
			reducedCost += (B[i] > 0)? B[i]:0;
			
		printf("%d. %d %d\n",c,totalCost,reducedCost);
	}
}
