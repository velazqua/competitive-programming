/* Name: Alex Velazquez
 * Start Date: September 18, 2011 @ 11:18PM
 * End Date:   ???
 * Purpose: To solve the Project Euler problem #293
 * Link: http://projecteuler.net/index.php?section=problems&id=293
 * */
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <set>

using namespace std;

// finds all admissible numbers recursively!
void findAdmissible (set<int> &admissible,int num, int i,vector<int> &primes,int const& sizePrimes, int const& LIMIT)
{
	if (i < sizePrimes && num*primes[i] < LIMIT && num*primes[i] > 0)
	{
		admissible.insert(num*primes[i]);
		findAdmissible(admissible,num*primes[i],i,primes,sizePrimes,LIMIT);
	}
	if (i < sizePrimes && num*primes[i+1] < LIMIT && num*primes[i+1] > 0)
	{
		admissible.insert(num*primes[i+1]);
		findAdmissible(admissible,num*primes[i+1],i+1,primes,sizePrimes,LIMIT);
	}
}

// checks whether a number is prime or not (could be improved)
bool isPrime (vector<int> &primes, int N)
{
	int i=0;
	while (primes[i] <= (int)floor(sqrt(N)))
	{
		if (N%primes[i] == 0)
			return false;
		++i;
	}
	return true;
}

int main ()
{
	/* BEGIN CALCULATE PRIMES */
    int LIMIT = 40000;
    vector<int>primes;
    bool numbers[LIMIT];
    numbers[0] = true;
    numbers[1] = true;
    int i=2;
    for (int i=2;i<LIMIT;++i)
        numbers[i] = false;
    while (i <= int(sqrt(LIMIT)))
    {
          for (int j=i+i;j<=LIMIT;j+=i)
              numbers[j] = true;    
          i++;
          while (numbers[i] == true)
                i++;
    }
    for (int i=0;i<LIMIT;++i)
    {
        if (numbers[i] == false)
           primes.push_back(i);
    }
    /* END CALCULATE PRIMES */
    
    set<int> admissible;
    admissible.insert(2);
    int N = 1000000000;
    findAdmissible (admissible,2,0,primes,(int)primes.size(),N);
    
    /* find the pseudo-Fortunate numbers */
    int M;
    set<int> pseudoFortunate;
    for (set<int>::iterator it=admissible.begin();it!=admissible.end();++it)
    {
		M = 2;
		while (1)
		{
			if (isPrime(primes,*it+M))
			{
				cout << "N: " << *it << ". M: " << M << ". N+M: " << *it+M << endl;
				pseudoFortunate.insert(M);	
				break;
			}
			++M;
		}
	}
	
	int SUMM = 0;
	/* find the sum of pseudo-Fortunate numbers */
	for (set<int>::iterator it = pseudoFortunate.begin();it!=pseudoFortunate.end();++it)
	{
		SUMM += *it;
	}
	cout << "Sum of all pseudo-Fortunate numbers is: " << SUMM << endl;
}
