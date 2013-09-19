#include <iostream>
#include <set>
#include <cmath>
int main ()
{
	std::set<int>s;for(int i=0;i<31625;++i)s.insert(i*i);int b,c;while(std::cin>>c){int w=0;for(std::set<int>::iterator a=s.begin();a!=s.end();++a){if(*a>c/2)break;b=sqrt(c-*a);if(ceil(b)==floor(b)&&*a+b*b==c)++w;}std::cout<<w<<"\n";}
}
