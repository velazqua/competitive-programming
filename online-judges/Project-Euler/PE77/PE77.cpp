/* Name: Alex Velazquez
 * Start Date: August 27, 10:32PM
 * End Date:   August 27, 11:39PM
 * Purpose: To solve the Project Euler problem #77
 * Link: http://projecteuler.net/index.php?section=problems&id=77
 * */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<int,int> answers;

void findSums (map<int,int> &M, vector<int> &P, int const &i, int const &size, int val, int currL, int const &L)
{
	if (currL > L)	return;
	for (int k=i;k<size;++k)
	{
		M[val+P[k]] += 1;
		if (M[val+P[k]] > 5000) 
		{
			//cout << val+P[k] << " => " << M[val+P[k]] << endl;
			answers[val+P[k]]= M[val+P[k]];
			return;
		}
		findSums(M,P,k,size,val+P[k],currL+1,L);
	}
}

int main ()
{
    int LIMIT = 100;
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
	map<int,int> M;
	int size = (int)primes.size();
	for (int i=0;i<size;++i)
	{
		M[primes[i]] += 1;
		findSums(M,primes,i,size,primes[i],2,100);
	}
	//int highest=0;
	//map<int,int>::iterator highIt;
	cout << answers.begin()->first << endl;
	/*
	for (map<int,int>::iterator it=M.begin();it!=M.end();++it)
	{
		if (it->second > 2)
		{
			cout << it->first << " => " << it->second << endl;
			break;
		}
	}
	*/
	//cout << highIt->first << " => " << highIt->second << endl;
}

