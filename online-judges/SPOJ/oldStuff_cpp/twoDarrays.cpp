#include <iostream>

using namespace std;

void F ( int *A, int i, int j, size_t R, size_t C)
{
	cout << A[i*C+j] << endl;
}

int main ()
{
	int R=3,C=4;
	int A[R][C];
	A[0][0]=0;A[0][1]=0;A[0][2]=0;A[0][3]=1;
	A[1][0]=0;A[1][1]=0;A[1][2]=1;A[1][3]=1;
	A[2][0]=0;A[2][1]=1;A[2][2]=1;A[2][3]=0;
	for (int i=0;i<R;++i)
	{
		for (int j=0;j<C;++j)
		{
			cout << "(" << i << "," << j << ") = ";
			F(&A[0][0],i,j,R,C);
		}
	}
}
