/* Name: Alex Velazquez
 * Start Date: September 04, 2011 @ 04:26PM
 * End Date:   Sept 05, 2011 @ 4:35PM
 * Purpose: To solve the Project Euler problem #348
 * Link: http://projecteuler.net/index.php?section=problems&id=348
 * */

#include <iostream>
#include <string>
#include <sstream>
#include <map>

typedef unsigned long long ULL;

using namespace std;

bool isPalindrome (string const& A)
{
	int i=0,j=(int)A.size()-1;
	while (i < j)
	{
		if (A[i] != A[j])
			return false;
		++i; --j;
	}
	return true;
}

bool isPalindrome (ULL &x)
{
	// convert int to string
	stringstream ss;
	ss << x;
	return isPalindrome(ss.str());
}

int main ()
{	
	map<ULL,int> pals;
	for (int i=2;i<30000;++i)
	{
		cout << i << endl;
		for (int j=2;j<10000;++j)
		{
			//stringstream A, B;
			//A << i;
			//B << j;
			//bigNum t = power(A.str(),2)+power(B.str(),3);
			ULL t = i*(ULL)i + (ULL)j*j*j;
			if (isPalindrome(t))
			{
				//cout << t << " = " << i << "^2 + " << j << "^3" << endl;  
				//if (t.number == "5229225") cout << "YEAH" << endl;
				++pals[t];
			}
		}
	}
	cout << "Done processing. Now find pals" << endl;
	ULL SUMM = 0ULL;
	int c = 0;
	for (map<ULL,int>::iterator it=pals.begin();it!=pals.end();++it)
	{
		if (c >= 5)
			break;
		if (it->second == 4){
			cout << it->first << " => " << it->second << endl;
			SUMM += it->first;
			++c;
		}
	}
	cout << SUMM << endl;
}

