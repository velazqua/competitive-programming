#include <iostream>
#include <cmath>

using namespace std;

int main ()
{	
	double G, B;
	int answer;
	while (cin >> G && cin >> B)
	{
		if (G == -1 && B == -1)
			break;	

		cout <<((G>B)?int(ceil(G/(B+1))):int(ceil(B/(G+1)))) << endl;
	}	
}
