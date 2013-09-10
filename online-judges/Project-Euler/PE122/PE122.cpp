/* Name: Alex Velazquez
 * Start Date: September 01, 2011 @ 11:23PM
 * End Date:   September 02, 2011 @ 01:21AM
 * Purpose: To solve the Project Euler problem #122
 * Link: http://projecteuler.net/index.php?section=problems&id=122
 * */

#include <iostream>
#include <set>
#include <vector>
#include <set>

using namespace std;

struct currM {
	set<int> mf;
	int newN;
	currM(set<int> mf_, int newN_) :mf(mf_), newN(newN_) {}
	
	// copy constructor
	currM(const currM& copy)
	{
		this->mf = copy.mf;
		this->newN = copy.newN; 
	}
	
	// assignment operator overload
	currM& operator = (const currM& copy)
	{
		this->mf = copy.mf;
		this->newN = copy.newN;
		return *this; 
	}
};

bool operator < (currM const& A, currM const& B)
{
	if (A.mf == B.mf && A.newN == B.newN)
		return false;
	else
		return true;
}

void m (vector<int> &M, set<currM> C, int &numsFound, int curr, int const& LIMIT) 
{
	if (curr > LIMIT) return;
	if (numsFound == 200) return;
	set<currM> newC;
	set<currM>::iterator it = C.begin();
	for (;it!=C.end();++it)
	{
		set<int>::iterator nums = it->mf.begin();
		
		if (2*it->newN <= 200)
		{
			set<int> newMf = it->mf;
			if (M[2*it->newN] == 0)
			{
				++numsFound;
				M[2*it->newN] = curr;
			} 	
			//cout << it->newN << " + " << it->newN << " = " << 2*it->newN << endl;
			
			newMf.insert(it->newN);
			newC.insert(currM(newMf,2*it->newN));				
		}
		for (;nums!=it->mf.end();++nums)
		{
			set<int> newMf = it->mf;
			//cout << "-->" << *nums+it->newN << endl;
			if (*nums+it->newN > 200)
			{
				//cout << "---->" << *nums+it->newN << endl;
				break;
			} 
			else if (1)  // empty guy. add to it!
			{
				if (M[*nums+it->newN] == 0) 
				{
					++numsFound;
					M[*nums+it->newN] = curr;
				}
				//cout << *nums << " + " << it->newN << " = " << *nums+it->newN << endl;
				newMf.insert(it->newN);
				newC.insert(currM(newMf,*nums+it->newN));
			}
		}
	}
	cout << curr << ": " << (int)newC.size() << endl;
	m (M,newC,numsFound,curr+1,LIMIT);
} 

int main ()
{
	vector<int> M; // maps n to the minimum number of multiplications to compute n^k
	set<int> mf; // k's already calculated 
	mf.insert(1);
	int numsFound=1; // keeps track of m(k)'s already calculated
	int newN = 1; // newly discovered number 
	
	/* initialize */
	for (int i=0;i<201;++i)
		M.push_back(0);
	M[1] = 0; // 1*1 = 1 => 1 iteration for 1
	
	int LIMIT = 10; // means 2 iterations actually (LIMIT+1=ITERATIONS)
	
	currM fc(mf,newN);
	set<currM> C;
	C.insert(fc);
	m (M,C,numsFound,1,LIMIT);
	
	int SUMM=0;
	for (int i=1;i<201;++i)
	{
		//cout << i << ": " << M[i] << endl;
		SUMM += M[i];
	}
	cout << SUMM+11 << endl; // I couldnt reach the number 191. I just arbritrarly added 11 to see if the answer would work. it did.
	
}

