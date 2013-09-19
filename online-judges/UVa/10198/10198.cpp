/* Alex Velazquez
 * Start: Sun Aug  5 20:56:20 EDT 2012
 * End  : Sun Aug  5 22:18:43 EDT 2012
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

typedef unsigned long long int LL;

using namespace std;

typedef pair<LL,LL> ii;
typedef vector<ii> vii;
typedef vector<LL> vi;

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
	////cout << "A: " << A << ". B: " << B << endl;
	////cout << "A.s: " << A.s << ". B.s: " << B.s << endl;
	////cout << "A.ds: " << A.ds << ". B.ds: " << B.ds << endl;
	
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
		int summ = A.number[i] + B.number[i] - 2*48 + carry;
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

bool overflow (string X)
{
	/* maximum int in C is 2,147,483,647 */
	if ((int)X.size() > 10)
		return true;
	else if ((int)X.size() < 10)
		return false;
	else // 10 digits. check each digit!
	{
		if (X <= "2147483647")
			return false;
		else
			return true;
	}
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
	C.updateS();
	return C;
}

bigNum zero( "0" );
bigNum one( "1" );
bigNum two( "2" );

bigNum solve( int N, vector<bigNum> &answer )
{
	//cout << "solve.. N:" << N << endl;
	////cout << "solve... N: " << N << ". answer[N]: " << answer[N] << endl;
	if( N >= 0 )
	{
		if( answer[N].number.compare( "0" ) )
		{
			//cout << "Not zero!: N: " << N << ". asnwr: "  << answer[N] << endl;
			return answer[N];
		}
		if( N == 0 )
		{
			//cout << "N == 0 !! return bigNum(1) " << endl;
			return one;
		}
		else
		{
			//cout << "lots of calls!" << endl;
			bigNum a = solve( N-1, answer );
			bigNum b = solve( N-2, answer );
			bigNum c = solve( N-3, answer );
			bigNum R = a;
			a.updateS();
			b.updateS();
			c.updateS();
			R.updateS();
			//cout << "R: " << R << endl;
			//cout << a.number << " " << a.s << " " << a.ds << endl;
			//cout << R.number << " " << R.s << " " << R.ds << endl;
			R = R + a;
			//cout << "R: " << R << endl;
			R = R + b;
			//cout << "R: " << R << endl;
			R = R + c;
			//cout << "R: " << R << endl;
			//cout << "N: " << N << ". R: " << R << endl;
			//cout << "a: " << a << ". b: " << b << ". c: " << c << endl;
			answer[N] = R; 
			return R;
		}
	}
	else
		return zero;
}

bigNum calc( int N, vector<bigNum> &answer )
{
	bigNum A = solve( N, answer );
	answer[N] = A;
	return A;
}

int main ()
{
	int N;
	vector<bigNum> answer( 1001, bigNum("0") );
	while( cin >> N )
	{
		if( !answer[N].number.compare( "0" ) )
			answer[N] = calc( N, answer );
		cout << answer[N].number << endl;	
	}
}
