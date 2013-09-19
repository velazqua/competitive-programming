#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
	string s;
	int c=0;
	double X1,X2,Y1,Y2;
	istringstream x1,x2,y1,y2;
	double total=0;
	while (getline(cin,s))
	{
		int lpar=s.rfind("(");
		int comm=s.rfind(",");
		int rpar=s.rfind(")");
		x1.str(s.substr(lpar+1,comm-lpar));
		y1.str(s.substr(comm+1,rpar-comm));
		if (c!=0)
		{
			X2 = X1;
			Y2 = Y1;
		}
		x1 >> X1;
		y1 >> Y1;
		if (c!=0)
		{
			total += sqrt(pow(X1-X2,2)+pow(Y1-Y2,2));
			cout << "The salesman has traveled a total of ";
			cout << setprecision(3) << fixed << total << " kilometers." << endl;
		}
		++c;
		
	}
}
