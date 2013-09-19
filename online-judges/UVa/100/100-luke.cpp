#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include<fstream>
std::map <int, int> check;
 
inline int printer(int n)
        {       int counter=0,temp=0;
                while (n!=1){
                //std::cout<< n<<std::endl;
                if (n%2==1) n=n*3+1;
                else n=n/2;
                counter++;
                };
        //std::cout<<n<<std::endl;
        temp=counter+1;check[n]=temp;
        return temp;
        };
 
 
 
inline void cal(int n, int k){
        int cycle_length=0, n_c=0,temp=0,kp=0,tn,tk;
        tn=n;tk=k;
        if ( n>k) { n^=k;k^=n;n^=k;};
       
        //std::list <int> n1;
        n_c=n;
        while(n_c!=k+1)
                {
                 if (check.count(n_c) >0 ) {temp =check[n_c];}
                else {temp=printer(n_c);};
                if (temp > kp){kp=temp;};
                n_c++;
                };
       
        std::cout<<tn<<" "<<tk<<" " <<kp<<std::endl;
 
};
 
 
int main(int argv ,char *argc[]){
        int n, k;
        while (std::cin>>n>>k) {
                cal(n,k);
               
        };
       
return 0;
};
