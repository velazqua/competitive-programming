/* Name: Alex Velazquez
 * Start Date: August 21, 2011 @ 1:24PM
 * End Date:   August 21, 2011 @ 1:43PM
 * Purpose: To solve the problem #694 (The Collatz Sequence) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=635
 * */

#include <iostream>

using namespace std;

typedef long long LL;

int numberTerms (LL A, LL LIMIT)
{
	if (A == 1)
		return 1;
	else if (A > LIMIT)
		return 0;
	else if (A%2 == 0) // if even
		return 1 + numberTerms(A/2,LIMIT);
	else // if odd
		return 1 + numberTerms(3*A+1,LIMIT);
}

int main ()
{
	LL A, LIMIT;
	int c=1;
	while (1)
	{
		cin >> A >> LIMIT;
		if (A<0 && LIMIT<0)
			break;
		cout << "Case " << c << ": ";
		cout << "A = " << A << ", limit = " << LIMIT;
		cout << ", number of terms = " << numberTerms(A,LIMIT) << endl;
		++c;
	}
}
