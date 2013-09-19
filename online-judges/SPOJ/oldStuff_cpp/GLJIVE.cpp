#include <iostream>

using namespace std;

int main ()
{
	int A[10];
	for (int i=0;i<10;++i)
	{
		cin >> A[i];
	}
	int c=0;
	for (int i=0;i<10;++i)
	{
		if (c>=100)
			break;
		if (A[i]+c < 100)
		{
			c += A[i];
		}
		else if (A[i]+c == 100)
		{
			c += A[i];
			break;
		}
		else if (c+A[i]>100 && ((100-c)==((c+A[i])-100)))
		{
			c += A[i];
			break;
		}
		else
		{
			break;
		}
	}
	cout << c << endl;
}
