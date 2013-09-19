#include <iostream>
#include <list>
#include <utility>
#include <stdio.h>

using namespace std;

void F (int *A, size_t i ,size_t j, size_t R, size_t C, list<pair<int,int> > &toVisit)
{
	if (i > 0)
	{
		// check row above
		//cout << " A[(i-1)*C+j] : " <<  A[(i-1)*C+j] << endl;
		if (A[(i-1)*C+j] == -1)
		{
			A[(i-1)*C+j] = A[i*C+j]+1;
			toVisit.push_back(make_pair(i-1,j));
		}
	}
	
	if (i < R-1)
	{
		// check row below
		//cout << "A[(i+1)*C+j]  :"<< A[(i+1)*C+j] << endl;
		if (A[(i+1)*C+j] == -1)
		{
			A[(i+1)*C+j] = A[i*C+j]+1;
			toVisit.push_back(make_pair(i+1,j));	
		}
	}
	
	if (j > 0)
	{
		// check column left
		//cout << "A[i*C+j-1] : " <<  A[i*C+j-1] << endl;
		if (A[i*C+j-1] == -1)
		{
			A[i*C+j-1] = A[i*C+j]+1;
			toVisit.push_back(make_pair(i,j-1));
		}
	}
	
	if (j < C-1)
	{
		// check column right
		//cout << "A[i*C+j+1] : " << A[i*C+j+1] << endl;
		if (A[i*C+j+1] == -1)
		{
			A[i*C+j+1] = A[i*C+j]+1;
			toVisit.push_back(make_pair(i,j+1));
		}
	}
}

int main ()
{
	int numCases;
	cin >> numCases;
	int R, C;
	for (int i=0;i<numCases;++i)
	{
		cin >> R >> C;
		int A[R][C];
		string t;
		list<pair<int,int> > next;
		int l=0;
		for (int j=0;j<R;++j)
		{
			cin >> t;
			l=0;
			for (string::iterator k=t.begin();k!=t.end();++k)
			{
				if (*k == '1')
					A[j][l] = 0;
				else
					A[j][l] = -1;
				if (*k=='1')
					next.push_back(make_pair(j,l));
				++l;
			}
		}
		
		
		while (1)
		{
			list<pair<int,int> > nextUp;
			for (list<pair<int,int> >::iterator it=next.begin();it!=next.end();++it)
			{
				//cout << it->first << " " << it->second << "===> " << endl;
				F(&A[0][0],it->first,it->second,R,C,nextUp);
			}			
			if (nextUp.empty())
				break;
			next=nextUp;
		}
		
		for (int j=0;j<R;++j)
		{
			for (int k=0;k<C;++k)
			{
				cout << A[j][k] << " ";
			}
			cout << endl;
		}
	}
}
