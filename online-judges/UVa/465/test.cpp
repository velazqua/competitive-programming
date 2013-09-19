/* Name: Alex Velazquez
 * Start Date: August 22, 11:35PM
 * End Date:   ??????
 * Purpose: To solve the problem #465 (Overflow) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=97&page=show_problem&problem=406
 * */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string removeLeadingZeroes(string A)
{
	int start=(int)A.size()-1;
	for (int i=0;i<(int)A.size();++i)
	{
		if (A[i] != '0')
		{
			start = i;
			break;
		}
	}
	return A.substr(start);
}

int main ()
{
	string a = "10";
	cout << removeLeadingZeroes(a) << endl;
}
