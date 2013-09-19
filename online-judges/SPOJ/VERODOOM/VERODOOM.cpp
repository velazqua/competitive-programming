/* Alex Velazquez
 * Start: Thu Mar  8 23:26:51 EST 2012
 * End  :
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

string removeLeadingZeroes(string A)
{
	int start=(int)A.size()-1;
	for (int i=0;i<(int)A.size();++i)
	{
		if (A[i] != '0')
		{
			start = i;
			break;
		}
	}
	return A.substr(start);
}

struct bigNum {
	string number; // number representation in string
	int s; // number of digits in INTEGER PART of number
	int ds;// number of digits in DECIMAL PART of number
	bigNum (string n) 
	{
		number = n;
		size_t decPoint = number.find(".");
		if (decPoint != string::npos) // if we find a decimal point!
		{
			s = (int)decPoint;
			ds = (int)number.size()-s-1;
			number.erase(decPoint,1); // remove '.' from number
		}
		else
		{
			s = (int)number.size();
			ds = 0;
		}
	}
	bigNum () 	      : number(""),s(0),ds(0) {}
	bigNum (const bigNum& rhs)
	{
		this->number = rhs.number;
		this->s = rhs.s;
		this->ds= rhs.ds;
	}
	bigNum& operator = (const bigNum& rhs)
	{
		this->number = rhs.number;
		this->s = rhs.s;
		this->ds= rhs.ds;
		return *this;
	}
	void updateS () 
	{
		this->s = (int)number.size();
	}
};

// only works for integer bigNums
bool operator < ( bigNum const& A, bigNum const& B )
{
	if( A.s < B.s )
		return true;
	else if( A.s > B.s )
		return false;
	else
		return ( A.number.compare( B.number ) < 0 ) ? true : false;
}

bool operator > ( bigNum const& A, bigNum const& B )
{
	return ( B < A ) ? true : false;
}

bool operator == ( bigNum const& A, bigNum const& B )
{
	return ( A < B || B < A ) ? false : true; 
}

ostream& operator << (ostream& os, const bigNum& N)
{
	if (N.ds == 0) // if no decimal digits
		os << N.number;
	else
	{
		os << N.number.substr(0,N.s) << "." << N.number.substr(N.s);
	}
	return os;
}

void addLeadingZeroes (bigNum& A, int i)
{
	if (i > 0)
	{
		A.number = "0" + A.number;
		addLeadingZeroes(A,i-1);
	}
}

void addTrailingZeroes (bigNum& A, int i)
{
	if (i > 0)
	{
		A.number += "0";
		addTrailingZeroes(A,i-1);
	}
}

/* adding two bigNums */
bigNum operator + (bigNum A, bigNum B)
{
	bigNum C;
	/* strings must be the same size in order to add them */
	//cout << "A: " << A << ". B: " << B << endl;
	//cout << "A.s: " << A.s << ". B.s: " << B.s << endl;
	//cout << "A.ds: " << A.ds << ". B.ds: " << B.ds << endl;
	
	int diff;
	if (A.s < B.s) // add zeroes to A
	{
		diff = B.s - A.s; // add $diff zeroes to A
		addLeadingZeroes(A,diff);
		C.s = B.s;
	}
	else if (A.s > B.s)
	{
		diff = A.s - B.s;
		addLeadingZeroes(B,diff);
		C.s = A.s;
	}
	else
	{
		C.s = A.s;
	}
	
	if (A.ds < B.ds) // add zeroes to A
	{
		diff = B.ds - A.ds; // add $diff zeroes to A
		addTrailingZeroes(A,diff);
		C.ds = B.ds;
	}
	else if (A.ds > B.ds)
	{
		diff = A.ds - B.ds;
		addTrailingZeroes(B,diff);
		C.ds = A.ds;
	}
	else
	{
		C.ds = A.ds;
	}
	
	int highDig = (A.s > B.s)? A.s : B.s;
	int highDDig  = (A.ds > B.ds) ? A.ds : B.ds;
	highDig += highDDig;
	int carry=0;
	
	/* now add the strings bit by bit, starting from the rightmost bit */
	for (int i=highDig-1;i>=0;--i)
	{
		int summ = (int)A.number[i] + (int)B.number[i] - 2*48 + carry;
		carry = summ/10;
		stringstream out;
		out << summ%10; // last digit of summ
		C.number = out.str() + C.number;
	}
	/* add the leftover carry (if any!) */
	if (carry)
	{
		stringstream out;
		out << carry;
		C.number = out.str() + C.number;
	}
	return C;
}

bigNum operator * (bigNum A, bigNum B)
{
	bigNum C("0");
	int currMult;
	int carry;
	/* multiply each digit in B (starting with the right most) and add it to C */
	int addZeroes=0;
	for (int i=B.s+B.ds-1;i>=0;--i)
	{
		bigNum T;
		carry = 0;
		/* iterate through string A and multiply with digit chosen above */
		for (int j=A.s+A.ds-1;j>=0;--j)
		{
			currMult = ((int)B.number[i]-48)*((int)A.number[j]-48)+carry;
			stringstream out;
			out << currMult%10;
			T.number = out.str() + T.number;
			carry = currMult/10;
		}
		/* dont forget the carry! */
		if (carry)
		{	
			stringstream out;
			out << carry;
			T.number = out.str() + T.number;
		}
		addTrailingZeroes(T,addZeroes);
		T.updateS();
		C.updateS();
		C = C+T;
		++addZeroes;
	}
	C.ds = A.ds + B.ds;
	C.s  = (int)C.number.size()-C.ds;
	return C;
}
string intToString( int x )
{
	stringstream S;
	S << x;
	return S.str();
}


#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int N;
		cin >> N;
		if( N%2 ) // if odd
		{
			bigNum n1( intToString( N ) );
			bigNum n2( intToString( (N+1)/2 ) );
			bigNum n3( intToString( N+2 ) );
			cout << n1*n2*n3 << endl;
		}
		else
		{
			bigNum n1( intToString( N/2 ) );
			bigNum n2( intToString( N+1) );
			bigNum n3( intToString( N+2 ) );
			cout << n1*n2*n3 << endl;
		}
	}
}
