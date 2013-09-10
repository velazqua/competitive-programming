#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long ULL;

void hamming (ULL val, ULL i, const ULL &L, ULL P[],set<ULL> &nums)
{
	if (val < L)
	{
		nums.insert(val);
		for (ULL k=i;k<25;++k)
		{
			//cout << val << "*"<< P[k] << "=" << val*P[k] << endl;
			hamming(val*P[k],k,L,P,nums);
		}
	}
}

void hamming2 (ULL val, ULL i, const ULL &L, ULL P[],bool H[])
{
	//cout << val << endl;
	if (val < L)
	{
		H[val]=true;
		for (ULL k=i;k<25;++k)
		{
			//cout << val << "*"<< P[k] << "=" << val*P[k] << endl;
			hamming2(val*P[k],i,L,P,H);
		}
	}
}



int main ()
{
	set<ULL> hamNums;
	hamNums.insert(1); hamNums.insert(2); hamNums.insert(3); hamNums.insert(5);
	const ULL LIMIT=1000000000;
	ULL P[25]; P[0]=2; P[1]=3; P[2]=5; P[3]=7; P[4]=11; P[5]=13; P[6]=17; P[7]=19;
	P[8]=23; P[9]=29; P[10]=31; P[11]=37; P[12]=41; P[13]=43; P[14]=47; P[15]=53; P[16]=59; 
	P[17]=61; P[18]=67; P[19]=71;P[20]=73;P[21]=79;P[22]=83;P[23]=89;P[24]=97; 
	/*
	bool H[LIMIT];
	for (ULL i=0;i<LIMIT;++i)
		H[i]=false;
	H[1]=true; H[2]=true; H[3]=true; H[5]=true;
	*/
	
	for (ULL i=0;i<25;++i)
		hamming(P[i],i,LIMIT,P,hamNums);
	//for (ULL i=0;i<3;++i)
	//	hamming2(P[i],i,LIMIT,P,H);
	cout << "There are " << hamNums.size() << " hamming numbers under " << LIMIT << endl;
	/*
	for (set<ULL>::iterator it=hamNums.begin();it!=hamNums.end();++it)
	{
		cout << *it << endl;
	}
	*/
	
	/*
	ULL c=0;
	for (ULL i=0;i<LIMIT;++i)
		if (H[i])
			++c;
	cout << "There are " << c << " hamming numbers under " << LIMIT << endl;
	*/
}
