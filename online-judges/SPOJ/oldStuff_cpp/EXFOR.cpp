#include <iostream>

using namespace std;

int f (int x1, int x2, int x3, int x4, int x5, int x6,int  x7, int x8, int x9, int x10)
{ return (x1 || x2)^(x1 || x3)^(x1 || x4)^(x1 || x5)^(x1 || x6)^(x1 || x7)^(x1 || x8)^(x1 || x9)^(x1 || x10)^(x2 || x3)^(x2 || x4)^(x2 || x5)^(x2 || x6)^(x2 || x7)^(x2 || x8)^(x2 || x9)^(x2 || x10)^(x3 || x4)^(x3 || x5)^(x3 || x6)^(x3 || x7)^(x3 || x8)^(x3 || x9)^(x3 || x10)^(x4 || x5)^(x4 || x6)^(x4 || x7)^(x4 || x8)^(x4 || x9)^(x4 || x10)^(x5 || x6)^(x5 || x7)^(x5 || x8)^(x5 || x9)^(x5 || x10)^(x6 || x7)^(x6 || x8)^(x6 || x9)^(x6 || x10)^(x7 || x8)^(x7 || x9)^(x7 || x10)^(x8 || x9) ^ (x8 || x10) ^ (x9 || x10) ^ (x1 || x2 || x3) ^ (x1 || x2 || x4) ^ (x1 || x2 || x5) ^ (x1 || x2 || x6) ^(x1 || x2 || x7) ^ (x1 || x2 || x8) ^ (x1 || x2 || x9) ^ (x1 || x2 || x10) ^ (x1 || x3 || x4) ^ (x1 || x3 || x5) ^(x1 || x3 || x6) ^ (x1 || x3 || x7) ^ (x1 || x3 || x8) ^ (x1 || x3 || x9) ^ (x1 || x3 || x10) ^ (x1 || x4 || x5) ^(x1 || x4 || x6) ^ (x1 || x4 || x7) ^ (x1 || x4 || x8) ^ (x1 || x4 || x9) ^ (x1 || x4 || x10) ^ (x1 || x5 || x6) ^(x1 || x5 || x7) ^ (x1 || x5 || x8) ^ (x1 || x5 || x9) ^ (x1 || x5 || x10) ^ (x1 || x6 || x7) ^ (x1 || x6 || x8) ^(x1 || x6 || x9) ^ (x1 || x6 || x10) ^ (x1 || x7 || x8) ^ (x1 || x7 || x9) ^ (x1 || x7 || x10) ^ (x1 || x8 || x9) ^(x1 || x8 || x10) ^ (x1 || x9 || x10) ^ (x2 || x3 || x4) ^ (x2 || x3 || x5) ^ (x2 || x3 || x6) ^ (x2 || x3 || x7) ^(x2 || x3 || x8) ^ (x2 || x3 || x9) ^ (x2 || x3 || x10) ^ (x2 || x4 || x5) ^ (x2 || x4 || x6) ^ (x2 || x4 || x7) ^(x2 || x4 || x8) ^ (x2 || x4 || x9) ^ (x2 || x4 || x10) ^ (x2 || x5 || x6) ^ (x2 || x5 || x7) ^ (x2 || x5 || x8) ^(x2 || x5 || x9) ^ (x2 || x5 || x10) ^ (x2 || x6 || x7) ^ (x2 || x6 || x8) ^ (x2 || x6 || x9) ^ (x2 || x6 || x10) ^(x2 || x7 || x8) ^ (x2 || x7 || x9) ^ (x2 || x7 || x10) ^ (x2 || x8 || x9) ^ (x2 || x8 || x10) ^ (x2 || x9 || x10) ^(x3 || x4 || x5) ^ (x3 || x4 || x6) ^ (x3 || x4 || x7) ^ (x3 || x4 || x8) ^ (x3 || x4 || x9) ^ (x3 || x4 || x10) ^(x3 || x5 || x6) ^ (x3 || x5 || x7) ^ (x3 || x5 || x8) ^ (x3 || x5 || x9) ^ (x3 || x5 || x10) ^ (x3 || x6 || x7) ^(x3 || x6 || x8) ^ (x3 || x6 || x9) ^ (x3 || x6 || x10) ^ (x3 || x7 || x8) ^ (x3 || x7 || x9) ^ (x3 || x7 || x10) ^(x3 || x8 || x9) ^ (x3 || x8 || x10) ^ (x3 || x9 || x10) ^ (x4 || x5 || x6) ^ (x4 || x5 || x7) ^ (x4 || x5 || x8) ^(x4 || x5 || x9) ^ (x4 || x5 || x10) ^ (x4 || x6 || x7) ^ (x4 || x6 || x8) ^ (x4 || x6 || x9) ^ (x4 || x6 || x10) ^(x4 || x7 || x8) ^ (x4 || x7 || x9) ^ (x4 || x7 || x10) ^ (x4 || x8 || x9) ^ (x4 || x8 || x10) ^ (x4 || x9 || x10) ^(x5 || x6 || x7) ^ (x5 || x6 || x8) ^ (x5 || x6 || x9) ^ (x5 || x6 || x10) ^ (x5 || x7 || x8) ^ (x5 || x7 || x9) ^(x5 || x7 || x10) ^ (x5 || x8 || x9) ^ (x5 || x8 || x10) ^ (x5 || x9 || x10) ^ (x6 || x7 || x8) ^ (x6 || x7 || x9) ^(x6 || x7 || x10) ^ (x6 || x8 || x9) ^ (x6 || x8 || x10) ^ (x6 || x9 || x10) ^ (x7 || x8 || x9) ^ (x7 || x8 || x10) ^(x7 || x9 || x10) ^ (x8 || x9 || x10);}

int main ()
{
	int cases;
	cin >> cases;
	for (int i=0;i<cases;++i)
	{
		int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
		cin >> x1>>x2>>x3>>x4>>x5>>x6>>x7>>x8>>x9>>x10;
		cout << f(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10) << endl;
	}
}
