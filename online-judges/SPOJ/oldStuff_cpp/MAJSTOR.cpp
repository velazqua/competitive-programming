#include <iostream>

using namespace std;

int p (char P1, char P2)
{
	if (P1 == 'R')
	{
		if (P2 == 'S')
			return 2;
		else if (P2 == 'R')
			return 1;
		else
			return 0;
	}
	else if (P1 == 'S')
	{
		if (P2 == 'P')
			return 2;
		else if (P2 == 'S')
			return 1;
		else
			return 0;
	}
	else // paper
	{
		if (P2 == 'R')
			return 2;
		else if (P2 == 'P')
			return 1;
		else
			return 0;
	}
}

int m (int a, int b)
{
	return (a > b) ? a : b;
}

int m (int a, int b, int c)
{
	return m(m(a,b),c);
}

int main ()
{
	int R, N;
	cin >> R;
	char P1[R+1];
	for (int i=0;i<R;++i)
		cin >> P1[i];
	cin >> N;
	char F[N][R+1];
	for (int i=0;i<N;++i)
		for (int j=0;j<R;++j)
			cin >> F[i][j];
			
	int a=0;
	int h[3];
	int H=0;
	h[0]=0;h[1]=0;h[2]=0;
	for (int j=0;j<R;++j)
	{
		h[0]=0;h[1]=0;h[2]=0;
		for (int i=0;i<N;++i)
		{
			a += p(P1[j],F[i][j]);
			h[0] += p('R',F[i][j]);
			h[1] += p('P',F[i][j]);
			h[2] += p('S',F[i][j]);
		}
		H+=m(h[0],h[1],h[2]);
	}
	cout << a << endl;
	cout << H << endl;
}
