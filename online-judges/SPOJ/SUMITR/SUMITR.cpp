#include <iostream>
using namespace std;int main(){int n,m,i,j,k;cin>>n;for(i=0;i<n;i++){cin>>m;int L[m][m];for(j=1;j<=m;j++)for(k=0;k<j;k++)cin>>L[j-1][k];for(j=m-1;j>0;j--)for(k=0;k<j;k++)L[j-1][k]+=max(L[j][k],L[j][k+1]);cout<<L[0][0]<<'\n';}}
