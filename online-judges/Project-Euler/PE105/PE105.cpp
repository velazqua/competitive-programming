/* Name: Alex Velazquez
 * Start Date: September 03, 2011 @ 09;42AM
 * End Date:   ???
 * Purpose: To solve the Project Euler problem #105
 * Link: http://projecteuler.net/index.php?section=problems&id=105
 * */

#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int S (vector<int> &A)
{
	int SUMM=0;
	for (vector<int>::iterator it = A.begin();it!=A.end();++it)
	{
		SUMM += *it;
	}
	return SUMM;
}

void printvector (vector<int> &A)
{
	cout << "{";
	for (vector<int>::iterator it = A.begin();it!=A.end();++it)
	{
		cout << *it << ",";
	}
	cout << "}. S(A) = " << S(A) << endl;
}

void printvectors (vector<vector<int> > &S)
{
	cout << "{";
	for (vector<vector<int> >::iterator it = S.begin();it!=S.end();++it)
	{
		cout << '\t';
		vector<int> A = *it;
		printvector(A);
	}
	cout << "}" << endl;
}

void findSubsets (vector<vector<int> > &ALL,\
				  vector<int> CURR,\
				  vector<int> &A,\
				  int &i, int &iEnd)
{
	CURR.push_back(A[i]);
	ALL.push_back(CURR);
	for (int k=i+1;k<iEnd;++k)
		findSubsets(ALL,CURR,A,k,iEnd);
}

int main ()
{
	ifstream fin;
	fin.open("PE105.txt");
	string line;
	int ANSWER = 0;
	int c = 0;
	while (getline(fin,line))
	{
		stringstream ss(line);
		string token;
		set<int> A;
		while (getline(ss,token,','))
		{
			int value = atoi(token.c_str());
			A.insert(value);

			vector<int> vA;
			for (set<int>::iterator it=A.begin();it!=A.end();++it)
				vA.push_back(*it);
			//printvector(vA);
			
			vector<vector<int> > ALL;
			int iEnd=(int)A.size();
			for (int i=0;i<iEnd;++i)
				findSubsets(ALL,vector<int>(),vA,i,iEnd);
			
			set<int> sums;
			for (vector<vector<int> >::iterator x = ALL.begin();x!=ALL.end();++x)
			{
				sums.insert(S(*x));
			}
			
			vector<vector<int> >::iterator xEnd = ALL.end();
			--xEnd;
			bool cond2=true;
			for (vector<vector<int> >::iterator x = ALL.begin();x!=xEnd&&cond2;++x)
			{
				cond2=true;
				vector<vector<int> >::iterator y = x;
				++y;
				for (;y!=ALL.end();++y) 
				{
					//cout << "x.size(): " << (int)(*x).size() << ". S(x): ";
					//cout << S(*x) << ". y.size(): " << (int)(*y).size();
					//cout << ". S(y): " << S(*y) << endl;
					if ((int)(*x).size() > (int)(*y).size())
					{
						if (!(S(*x) > S(*y))){
							//printvector(*x);
							//printvector(*y);
							cond2=false;
							break;
						}
					}
					
					if ((int)(*x).size() < (int)(*y).size())
					{
						if (!(S(*x) < S(*y))){
							//printvector(*x);
							//printvector(*y);
							cond2=false;
							break;
						}
					}	
				}
				if (cond2==false)
					break;
			}
		
			if (cond2 && (int)sums.size() == (int)pow(2,(int)A.size())-1) // i. condition satisfied!
			{
				//cout << "The set A has the 2 properties" << endl;
				ANSWER += S(vA);
				++c;
				//cout << ++c << endl;
			}
		}
	}
	cout << c << endl;
	cout << ANSWER << endl;
	fin.close();
}
