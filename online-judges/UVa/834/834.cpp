/* Name: Alex Velazquez
 * Start Date: September 23, 2011 @ 09:39PM
 * End Date:   September 23, 2011 @ 10:44PM
 * Purpose: To solve the UVa problem 834 - Continued Fraction
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=775
 * */
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int A, B;
	while (cin >> A >> B)
	{
		vector<int> fraction;
		int d;
		int NUM=A, DEN=B, TEMP;
		while (1)
		{
			d = NUM/DEN;
			fraction.push_back(d);
			NUM = NUM - d*DEN;
			DEN = DEN;
			if (d == 0)
			{
				if (DEN%NUM==0)
				{
					DEN /= NUM;
					NUM = 1;
				}
			}
			if (NUM == 0)
			{
				break;
			}
			//cout << NUM << " " << DEN << " " << d << endl;
			if (NUM == 1)
			{
				fraction.push_back(DEN);
				break;
			}
			/* swap numerator and denominator */
			TEMP = NUM;
			NUM = DEN;
			DEN = TEMP;
		}
		cout << "[";
		vector<int>::iterator it = fraction.begin();
		cout << *it;
		if ((int)fraction.size() > 1)
		{
			cout << ";" << *(it+1);
			++it;++it;
			for (;it!=fraction.end();++it)
				cout <<  "," << *it;
		}
		cout << "]" << endl;
	}
}
