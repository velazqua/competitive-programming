#include <iostream>
#include <list>

using namespace std;

int d=30;
int counter=0;

void PS (bool L, int A, int c)
{
	if (c < d)
	{
		// ON TIME
		PS(L,0,c+1);
		
		// ABSENT
		if (A < 2)
			PS(L,A+1,c+1);
		
		// LATE
		if (L==false) // if not late yet
			PS(true,0,c+1);
	}
	else
		++counter;
}

int main ()
{
	PS(false,0,1);
	PS(false,1,1);
	PS(true,0,1);
	cout << counter << endl;
}
