#include <iostream>
#include <utility>
#include <list>

using namespace std;

int main ()
{
	int T;
	
	while (1)
	{
		bool end=false;
		list<pair<int,int> > cars;
		cin >> T;
		if (T == 0)
			break;
		int A[T];
		int a, b;
		for (int i=0;i<T;++i)
		{
			A[i]=-1;
			cin >> a >> b;
			cars.push_back(make_pair(a,b));
		}
		
		int i=0;
		for(list<pair<int,int> >::iterator it=cars.begin();it!=cars.end();++it,++i)
		{
			b = it->second;
			if (b < -1*T || b > T-i-1)
			{
				cout << -1 << endl;
				end=true;
				break;
			}
		}

		int k=0;
		for(list<pair<int,int> >::iterator it=cars.begin();it!=cars.end()&&!end;++it)
		{
			A[k+it->second] = it->first;
			++k;
		}
		
		for (int i=0;i<T&&!end;++i)
		{
			if (A[i] == -1)
			{
				cout << -1 << endl;
				end=true;
				break;
			}
		}		
		
		for (int i=0;i<T&&!end;++i)
		{
			cout << A[i] << ((i!=T-1)?" ":"\n");
		}
	}
}
