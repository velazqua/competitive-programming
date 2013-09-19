#include <iostream>

using namespace std;

int main ()
{
    int N, M;
    cin >> N >> M;
    int A[N][M];
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j)
            cin >> A[i][j];
    
    //cout << A[3][2] << endl;
    /*
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            cout << A[i][j] << " ";}
        cout << endl;}
    */    
    for (int i=N-2;i>=0;--i)
    {
        for (int j=0;j<M;++j)
        {
          //  cout << A[i][j] << " " << A[i+1][j-1] << " " << A[i+1][j] << " " << A[i+1][j+1];
            if (j == 0)
               A[i][j] += (A[i+1][j+1] < A[i+1][j])?A[i+1][j+1]:A[i+1][j];    
            else if (j == M-1)
               A[i][j] += (A[i+1][j] > A[i+1][j-1])?A[i+1][j-1]:A[i+1][j];
            else{
               //A[i][j] += (A[i+1][j-1] < A[i+1][j])?(A[i+1][j-1] < A[i+1][j+1]?A[i+1][j-1]:A[i+1][j+1]):(A[i+1][j] < A[i+1][j+1]?A[i+1][j]:A[i+1][j+1]);  
               if (A[i+1][j-1] <= A[i+1][j] && A[i+1][j-1] <= A[i+1][j+1])
                  A[i][j] += A[i+1][j-1];
               else if (A[i+1][j] <= A[i+1][j-1] && A[i+1][j] <= A[i+1][j+1])
                  A[i][j] += A[i+1][j];
               else
                  A[i][j] += A[i+1][j+1];
               
               }
            
        }    
    }
    
    
    
    int min=10000000;
    for (int i=0;i<M;++i)
    {
        if (A[0][i] < min)
           min = A[0][i];    
    } 
    
    cout << min << endl;
}
