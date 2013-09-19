#include <iostream>

using namespace std;

int min (int a, int b)
{
	return (a < b) ? a : b;
}

int min (int a, int b, int c)
{
	return min(min(a,b),c);
}

int min (int a, int b, int c, int d)
{
	return min(min(a,b,c),d);
}

int main ()
{
	int T;
	int c=0;
	while (1)
	{
		cin >> T;
		if (T==0)
			break;
		++c;
		int A[T][3];
		for (int i=0;i<T;++i)
			for (int j=0;j<3;++j)
				cin >> A[i][j];
		
		A[0][0]=A[0][1];
		A[0][2]+=A[0][1];
		int j;
		for (int i=1;i<T;++i)
		{
			j=0;
			A[i][j]+=min(A[i-1][j],A[i-1][j+1]);
			++j;
			A[i][j]+=min(A[i-1][j-1],A[i-1][j],A[i-1][j+1],A[i][j-1]);
			++j;
			A[i][j]+=min(A[i-1][j-1],A[i-1][j],A[i][j-1]);
		}
		cout << c << ". " << A[T-1][1] << endl;
	}
}
