#include <iostream>

using namespace std;

int max (int a, int b)
{
	return a>b?a:b;
}

int main ()
{
	int W, n;
	while (1)
	{
		cin >> W >> n;
		if (W == 0 && n == 0)
			break;
		
		int P[n][2];
		for (int i=0;i<n;++i)
		{
			cin >> P[i][0] >> P[i][1];
		}
		
		int V[n+1][W+1];
		for (int i=0;i<n+1;++i)
			V[i][0]=0;
		for (int i=0;i<W+1;++i)
			V[0][i]=0;
			
		
		for (int i=1;i<n+1;++i)
		{
			//cout << P[i-1][0] << " " << P[i-1][1] << endl;
			for (int j=1;j<W+1;++j)
			{
				if (P[i-1][0] > j)
					V[i][j] = V[i-1][j];
				else
					V[i][j] = max(V[i-1][j],V[i-1][j-P[i-1][0]]+P[i-1][1]);
			}
		}
		
		/*
		for (int i=0;i<n+1;++i)
		{
			for (int j=0;j<W+1;++j)
			{
				cout << V[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << V[n][W] << endl;
		
		
	}
}
