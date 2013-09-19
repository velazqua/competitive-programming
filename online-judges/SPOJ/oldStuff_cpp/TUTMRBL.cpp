#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n==0)
			break;
		int numRectangles=0;
		cout << n << " = ";
		int otherN=n;
		int c=0;
		for (int i=1;i<(int)floor(sqrt(n))+1;++i)
		{
			if (i*i==n) // square
			{
				++numRectangles;
				while (otherN!=1 && otherN%i==0 && i!=1)
				{
					otherN /= i;
					if (c!=0)
						cout << " * " << i;
					else
					{
						cout << i;
						++c;
					}
				}
			}
			else if (n%i==0)
			{
				++numRectangles;
				while (otherN!=1 && otherN%i==0 && i!=1)
				{
					otherN /= i;
					if (c!=0)
						cout << " * " << i;
					else
					{
						cout << i;
						++c;
					}
				}
			}
		}
		if (c==0)
			cout << n;
		cout << endl << "With " << n << " marbles, " << numRectangles << " different";
		cout << " rectangles can be constructed." << endl;
	}
}
