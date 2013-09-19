#include <iostream>

using namespace std;

typedef unsigned long long ULL;

int main ()
{
	int T, N, C, n, p, q, v;
	cin >> T;
	ULL s;
	for (int i=0;i<T;++i)
	{
		cin >> N >> C;
		ULL A[N];
		for (int j=0;j<N;++j)
			A[j]=0LL;
		for (int j=0;j<C;++j)
		{
			cin >> n;
			if (n==0)
			{
				cin >> p >> q >> v;
				for (int k=p-1;k<q;++k)
					A[k] += v;
			}
			else if (n==1)
			{
				cin >> p >> q;
				s=0LL;
				for (int k=p-1;k<q;++k)
					s+=A[k];
				cout << s << endl;
			}
		}
	}
}
