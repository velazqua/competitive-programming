#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <iterator>

using namespace std;

int main ()
{
	int sz,n;
	cin >> sz;
	set<pair<int,int> > S;
	set<pair<int,int> > sums;
	set<pair<int,int> > prods;
	typedef set<pair<int,int> >::iterator S_ITER;
	//read input
	for (int i=0;i<sz;++i)
	{
		cin >> n;
		S.insert(make_pair(n,0));
	}
	
	S_ITER it1=S.begin();
	S_ITER it2;
	S_ITER it1End=S.end();
	S_ITER it2End=S.end(); 
	//make sets of nums 
	int comb1;
	for (;it1!=it1End;++it1)
	{
		it2=it1;
		for (;it2!=it2End;++it2)
		{
			//cout << *it1+*it2 << " " << (*it1)*(*it2) << endl;
			if (it1->first != it2->first)
				comb1=1;
			else
				comb1=0;
			pair<S_ITER,bool> sR = sums.insert(make_pair(it1->first+it2->first,comb1));
			if (sR.second == false)
				(sR.first)->second += 1;
			pair<S_ITER,bool> pR = prods.insert(make_pair((it1->first)*(it2->first),comb1));
			if (pR.second == false)
				(pR.first)->second += 1;
		}
	}
	
	S_ITER x=sums.begin();
	S_ITER y=prods.begin();
	S_ITER d=S.begin();
	S_ITER xEnd=sums.end();
	S_ITER yEnd=prods.end();
	S_ITER dEnd=S.end();
	
	/*
	cout << "sum:{";
	for (;x!=xEnd;++x)
		cout << x->first << ", ";
	cout << "}" << endl;
	
	cout << "prod:{";
	for (;y!=yEnd;++y)
		cout << y->first << ", ";
	cout << "}" << endl;
	
	cout << "S:{";
	for (;d!=dEnd;++d)
		cout << d->first << ", ";
	cout << "}" << endl;
	
	
	x=sums.begin();
	y=prods.begin();
	d=S.begin();
	xEnd=sums.end();
	yEnd=prods.end();
	dEnd=S.end();
	*/
	
	int counter=0;
	//loop through numbers
	for (x=sums.begin() ;x!=xEnd ;++x )
	{
		for (y=prods.begin() ;y!=yEnd ;++y )
		{
			for (d=S.begin() ;d!=dEnd ; ++d)
			{
				
				int c = (x->first)*(d->first) - y->first;
				if (S.find(make_pair(c,0)) != S.end())
				{
					cout << c << "=" << x->first << "*" << d->first << "-" << y->first << endl;
					if (x->second && y->second)
						counter += 4;
					else if ((x->second && !(y->second)) || (!(x->second) && (y->second) ))
						counter += 2;
					else
						++counter;
				}
			}
		}
	}
	cout << counter << endl;
	
}
