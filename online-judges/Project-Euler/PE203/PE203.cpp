#include <iostream>
#include <set>
#include <list>
#include <cmath>

using namespace std;

typedef unsigned long long ULL;

void printPascal2 (ULL P[], int rows)
{
	int k=0;
	for (int i=0;i<rows;++i)
	{
		++k;
		for (int j=0;j<k;++j)
		{
			cout << P[i*(i+1)/2 + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main ()
{
	set<ULL> NUMS;
	NUMS.insert(1);
	int rows=8;
	ULL P[rows*(rows+1)/2];
	for (int i=0;i<rows*(rows+1)/2;++i)
		P[i]=1;
	int target=1;
	int counter=0;
	int start=4;
	int num=1;
	while (target != rows-1)
	{
		P[start] = P[num] + P[num+1];
		NUMS.insert(P[num] + P[num+1]);
		++counter;
		if (counter == target)
		{
			counter = 0;
			++target;
			start += 3;
			num+=2;
		}
		else
		{
			++num;
			++start;
		}
	}
	/*
	cout << "Numbers in pascals triangle" << endl;
	for (set<ULL>::iterator it=NUMS.begin();it!=NUMS.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	*/
	
	//generating primes
	int LIMIT = 10;
    list<ULL>primes;
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
           primes.push_back(i*i);
    }
    
	set<ULL> NUMS_COPY=NUMS;
    list<ULL>::iterator itPrimes=primes.begin(),itPrimesEnd=primes.end();
    for ( ; itPrimes != itPrimesEnd ; ++itPrimes)
    {
		for (set<ULL>::iterator it=NUMS.begin();it!=NUMS.end();++it)
		{
			//if (*it > *itPrimes)
			//	break;
			if (*it % *itPrimes == 0) // divisible!
			{
				
				//cout << *it << " will be deleted " << endl;
				set<ULL>::iterator itAlt=NUMS_COPY.find(*it);
				NUMS_COPY.erase(itAlt);
			}
		}
	}
	
	/*
	cout << "Numbers in pascals triangle" << endl;
	for (set<ULL>::iterator it=NUMS_COPY.begin();it!=NUMS_COPY.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	*/
	
    //--itPrimes;
    //cout << *itPrimes << endl;
	cout << "There are " << NUMS_COPY.size() << " distinct numbers in " << rows << " of pascals triangle" << endl;
	//set<ULL>::iterator it=NUMS.end();
	//--it;
	//cout << *it << endl;
	//printPascal2(P,rows);
}
