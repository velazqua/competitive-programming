/* Name: Alex Velazquez
 * Start Date: August 21, 2011 @ 1:52PM
 * End Date:   ???????????
 * Purpose: To solve the problem #457 (Linear Cellular Automata) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=398
 * */

#include <iostream>

using namespace std;

void displayDishes (int DISH[40])
{
	for (int i=0;i<40;++i)
	{
		switch(DISH[i])
		{
			case 0: cout << 'b';
					break;
			case 1: cout << '.';
					break;
			case 2: cout << 'x';
					break;
			case 3: cout << 'W';
					break;
		}
	}
	cout << endl;
}

int main ()
{
	int T;
	cin >> T;
	for (int i=0;i<T;++i)
	{
		/* DNA values */
		int DNA[10];
		for (int j=0;j<10;++j)
			cin >> DNA[j];
			
		int DISH[40];
		for (int j=0;j<40;++j)
			DISH[j] = 0;
		DISH[19] = 1;
		
		/* modify and output dishes */
		displayDishes(DISH);
		for (int j=0;j<50-1;++j)
		{
			int NEW_DISH[40];
			/* modify values */
			NEW_DISH[0] = DISH[0] + DISH[1];
			NEW_DISH[39]= DISH[39] + DISH[38];
			for	(int i=1;i<39;++i)
			{
				NEW_DISH[i] = DNA[(DISH[i-1] + DISH[i] + DISH[i+1])%10];
			}
			/* output */
			displayDishes(NEW_DISH);
			
			/* copy values from NEW_DISH to DISH */
			for (int k=0;k<40;++k)
				DISH[k] = NEW_DISH[k];
		}
		cout << endl;
	}
}
