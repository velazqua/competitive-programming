#include <iostream>
#include <map>

using namespace std;

int A (int i, int k, map<int,int> &a, map<int,int> &b, map<int,int> &c)
{
	if (i<=k)
	{
		a[i] = b[i];
		return a[i];
	}
	else
	{
		for (int j=1;j<=k;++j)
		{
			--i;
			a[i] += c[j]*A(i,k,a,b,c);
		} 
		return a[i];
	}
}

int main ()
{
	
	typedef map<int,int> MAP;
	typedef MAP::iterator MAP_ITER;

	int cases;
	cin >> cases;
	int k;
	int n;
	for (int i=0;i<cases;++i)
	{
		cin >> k;
		MAP a, b, c;
		for (int j=0;j<k;++j)
			cin >> b[j+1];
		for (int j=0;j<k;++j)
			cin >> c[j+1];
		cin >> n;
		cout << A(n,k,a,b,c) << endl;
	}	
}
