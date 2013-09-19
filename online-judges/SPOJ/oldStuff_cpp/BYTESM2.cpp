#include <iostream>

using namespace std;

int maxx (int a, int b)
{
	return a > b ? a : b;
}

int maxx (int a, int b, int c)
{
	return maxx(c,maxx(a,b));
}

int main ()
{
	int T;
	cin >> T;
	int h, w;
	for (int i=0;i<T;++i)
	{
		cin >> h >> w;
		int A[h][w];
		for (int j=0;j<h;++j)
		{
			for (int k=0;k<w;++k)
			{
				cin >> A[j][k];
				
				if (j>0)
				{
					if (w >= 3)
					{
						if (k==0)
						{
							A[j][k] += maxx(A[j-1][k],A[j-1][k+1]);
						}
						else if (k == w-1)
						{
							A[j][k] += maxx(A[j-1][k-1],A[j-1][k]);
						}
						else // in between
						{
							A[j][k] += maxx(A[j-1][k],A[j-1][k+1],A[j-1][k-1]);
						}
					}
					else if (w == 2)
					{
						if (k==0)
							A[j][k] += maxx(A[j-1][k],A[j-1][k+1]);						
						else
							A[j][k] += maxx(A[j-1][k],A[j-1][k-1]);
					}
					else // w == 1
					{
						A[j][k] += A[j-1][k];						
					}
				}
			}
		}
		int highest=0;
		for (int l=0;l<w;++l)
		{
			 if (A[h-1][l] > highest)
				highest = A[h-1][l];
		}
		cout << highest << endl;
		
	}
}
