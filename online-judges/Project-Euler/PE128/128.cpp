#include <iostream>
#include <map>
#include <utility>

using namespace std;

struct Cell {
	int a,b,c,d,e,f;
	Cell () :  a(0), b(0), c(0), d(0), e(0), f(0) {}
	Cell (int a_, int b_, int c_, int d_, int e_, int f_) : 
		a(a_), b(b_), c(c_), d(d_), e(e_), f(f_) {}
};

ostream& operator << (ostream& os, const Cell& c)
{
	os << "a: " << c.a << ". ";
	os << "b: " << c.b << ". ";
	os << "c: " << c.c << ". ";
	os << "d: " << c.d << ". ";
	os << "e: " << c.e << ". ";
	os << "f: " << c.f << ".\n";
	return os;
	 
}

int main ()
{
	map<int,Cell> H;
	H[1]=Cell(2,3,4,5,6,7);
	H[2]=Cell(0,0,0,1,0,0);H[3]=Cell(0,0,0,0,1,0);H[4]=Cell(0,0,0,0,0,1);
	H[5]=Cell(1,0,0,0,0,0);H[6]=Cell(0,1,0,0,0,0);H[7]=Cell(0,0,1,0,0,0);
	map<int,
	cout << H[2] << endl;
	for (int i=2;i<8;++i)
	{
		H[i].
	}
}
