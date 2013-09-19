#include <iostream>

using namespace std;

int main ()
{
    int B=500001;
    int A[B];
    for (int i=0;i<B;++i)
       A[i]=0;
    int j;
    int c;
    for (int i=1;i<=(B-1)/2;++i)
    {
       j=i;
       c=j;
       while (j<=(B-1)/2)
       {
          A[j]+=c;
          j+=c;      
       }
    }
    int T;
    cin >> T;
    int N;
    for (int i=0;i<T;++i)
    {
        cin >> N;
        cout << A[N]-N << endl;
    }
}
