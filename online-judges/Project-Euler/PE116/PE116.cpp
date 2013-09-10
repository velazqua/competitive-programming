#include <iostream>

using namespace std;

int main ()
{
	typedef unsigned long long ULL;
	const ULL LIMIT=51;
	ULL R[LIMIT];
	ULL F[LIMIT];
	ULL G[LIMIT];
	ULL B[LIMIT];
	F[0]=0LL; F[1]=0LL; F[2]=1LL; F[3]=1LL;
	R[0]=0LL; R[1]=0LL; R[2]=1LL; R[3]=2LL;
	G[0]=0LL; G[1]=0LL; G[2]=0LL; G[3]=1LL;
	B[0]=0LL; B[1]=0LL; B[2]=0LL; B[3]=0LL;
	for (ULL i=4;i<LIMIT;++i)
	{
		F[i] = F[i-1] + F[i-2];
		R[i] = R[i-1] + F[i];
		G[i] = G[i-1] + G[i-3] + 1;
		B[i] = B[i-1] + B[i-4] + 1;
	}
	cout << R[50]+G[50]+B[50] << endl;
}
