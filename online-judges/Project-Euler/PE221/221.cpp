#include <iostream>
#include <set>
#include <cmath>

using namespace std;

unsigned long long A (unsigned long long p, unsigned long long q)
{
	unsigned long long r = (1+p*q)/(q-p);
	if (-p*q+r*-p+r*q == 1)
		return p*q*r;
	
	r = (1-p*q)/(q+p);
	if (p*q+r*p+r*q == 1)
		return p*q*r;
	return -1;
}
int main ()
{
	set<unsigned long long> alex;
	unsigned long long a;
	unsigned long long LIMIT = 50000;
	for (unsigned long long p=1;p<LIMIT;p++){
		for (unsigned long long q=p+1;q<LIMIT;q++){
			a = A(p,q);
			if (a > 0)
				alex.insert(a);
		}
	}
	unsigned long long c=1;
	set<unsigned long long>::iterator it = alex.begin();
	if (alex.size() > 150000){
	for (; c++ < 150000; ++it);
	cout << *it << endl;
	}
	cout << "done" << endl;
}
