#include <iostream>
using namespace std;
int main(){
     int t,c,d,e,j,s,p,i=0;
     cin>>t;
     for(;i<t;++i)
     {
         j=0;
         cin>>c;
         s=c*(c+1)/2;
         int A[s];
         for (;j<s;++j)
             cin>>A[j];
         d=c-1;
         j=s-c-1;
         e=0;
         for(;j>=0;--j)
         {
			if(e==d){--d;e=0;}
			p=j+d;
            A[j]+=A[p]>A[p+1]?A[p]:A[p+1];
			++e;
         }
         cout<<A[0]<<endl;
     }     
}
