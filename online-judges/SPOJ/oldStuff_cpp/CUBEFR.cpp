#include <iostream>

using namespace std;

int power3 (const int &x)
{
	return x*x*x;
}

int main ()
{
	int A[1000001];
	int k=1;
	for (int i=2;i<101;++i)
	{
		k=1;
		while (k*power3(i) <= 1000000)
		{
			A[k*power3(i)] = -1;
			++k;			
		}
	}
	k=0;
	int k1=0;
	for (int i=1;i<1000001;++i)
	{
		if (A[i] != -1)
		{
			++k;
			A[i] = k;
		}
		else
		{
			++k1;
		}
	}
	int T;
	cin >> T;
	int n;
	for (int i=1;i<=T;++i)
	{
		cin >> n;
		cout << "Case " << i << ": ";
		if (A[n]!=-1)
			cout << A[n];
		else
			cout << "Not Cube Free";
		cout << endl;
	}
	
}
