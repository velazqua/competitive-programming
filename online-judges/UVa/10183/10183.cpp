/* Alex Velazquez
 * Start: Mon Sep  3 20:22:56 EDT 2012
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

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
	cout << "COMPARING < " << endl;
	cout << "A: " << A.number << ". A.s: " << A.s << endl;
	cout << "B: " << B.number << ". B.s: " << B.s << endl;
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
	cout << "COMP: " << ( A < B ) << endl;
	cout << "COMP: " << ( B < A ) << endl;
	return ( A < B || B < A ) ? false : true; 
}

bool operator <= ( bigNum const& A, bigNum const& B )
{
	return ( B > A ) ? false : true;
}

bool operator >= ( bigNum const& A, bigNum const& B )
{
	return ( A < B ) ? false : true;
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
	C.updateS();
	return C;
}

inline std::string TrimStr(const std::string& Src, const std::string& c = " \r\n")
{
	size_t p2 = Src.find_last_not_of(c);
	if (p2 == std::string::npos) return std::string();
	size_t p1 = Src.find_first_not_of(c);
	if (p1 == std::string::npos) p1 = 0;
	return Src.substr(p1, (p2-p1)+1);
}

string intToString( int x )
{
	stringstream S;
	S << x;
	return S.str();
}

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main ()
{
	vector<bigNum> nums;
	bigNum A( "1" );
	bigNum B( "2" );
	nums.PB( A );
	nums.PB( B );
	for( int i=0; i<477; ++i )
	{
		A.updateS();
		B.updateS();
		bigNum C = A+B;
		C.updateS();
		nums.PB( C );
		A = B;
		B = C;
	}
	int size = SZ(nums);
	string a, b;
	bigNum X1 ("9216845717656874712980450562726202415567360565980794777111390850331644813674856981646960226192287360");
	bigNum X2 ("10");
	bigNum X3 ("1");
	if( X1 == X2 || X2 == X1 )
	{
		cout << X1 << endl;
	}
	while( cin >> a >> b )
	{
		if( !a.compare( "0" ) && !b.compare( "0" ) )
			break;
		int counter = 0;
		bigNum AA( a );
		bigNum BB( b );
		for( int i=0; i<size; ++i )
			if( ( (nums[i] > AA) || (nums[i] == AA) ) && ( (nums[i] < BB) || (nums[i] == B) ) )
			{
				cout << "AA: " << AA << " " << AA.s << endl;
				cout << "BB: " << BB << " " << BB.s << endl;
				cout << "nums[i]: " << nums[i] << " " << nums[i].s << endl;
				cout << (nums[i] > AA) << " " << (nums[i] == AA) << " " << (nums[i] < BB) << " " << (nums[i] == B) << endl;
				++counter;
			}
		cout << counter << endl;
	}
}
