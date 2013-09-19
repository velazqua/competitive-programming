/* Name: Alex Velazquez
 * Start Date: November 01, 2011 @ 09:59PM
 * End Date:   November 01, 2011 @ ??:??PM
*/
#include <iostream>
#include <vector>
#include <set>

// works for small nums
int xPyMODn (int &x, int y, int &n)
{
	if (y <= 2)
		return power(x,y)%n;
	else
	{
		if (y%2==0)
			return power(xPyMODn(x,y/2,n)%n,2)%n;
		else
			return power(xPyMODn(x,y/2,n)%n,2)%n*x%n;
	}	
}

