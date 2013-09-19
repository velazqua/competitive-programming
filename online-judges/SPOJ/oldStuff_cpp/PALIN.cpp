#include <iostream>
#include <string>

using namespace std;

string pal (string newNum, string num, int i)
{
	if ((int)num.size()/2 == i)
	{
		if (num[i] == '9')
		{
			newNum = newNum.substr() + "0"+newNum.substr();
		}
	}
	if (num[i+1] != '9')
	{
		newNum = num[i] + 
	}

}

int main ()
{
	
}
