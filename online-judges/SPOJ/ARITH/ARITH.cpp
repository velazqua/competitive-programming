/* Alex Velazquez
 * Start: November 19, 2011 @ 09:47PM
 * End  : November 19, 2011 @ 11:27PM
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

#define DEBUG 0


string printDashes( int n )
{
	string d = "";
	for( int i=0; i<n; ++i )
		d += "-";
	return d;
}

string printSpaces( int n, int N )
{
	string s = "";
	for( int i=0; i<N-n; ++i )
		s += " ";
	return s;
}

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

string addTrailingZeroes (bigNum const& A, int i)
{
	string s = A.number;
	for( int k=0; k<i; ++k )
	{
		s += "0";
	}
	return s;
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
		A.number = addTrailingZeroes(A,diff);
		C.ds = B.ds;
	}
	else if (A.ds > B.ds)
	{
		diff = A.ds - B.ds;
		B.number = addTrailingZeroes(B,diff);
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
		//cout << removeLeadingZeroes( T.number ) << endl;
		printf( "%s\n", removeLeadingZeroes( T.number ).c_str() );
		T.number = addTrailingZeroes(T,addZeroes);
		T.updateS();
		C.updateS();
		C = C+T;
		++addZeroes;
	}
	C.ds = A.ds + B.ds;
	C.s  = (int)C.number.size()-C.ds;
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

bigNum power(string num, int N)
{
	--N;
	bigNum X(num), T(num), TEMP(num);
	for (int i=0;i<N;++i)
	{
		TEMP = X*T;
		X = TEMP;
	}
	return X;
}

string intToString( int x )
{
	stringstream S;
	S << x;
	return S.str();
}

string closestNum ( bigNum T )
{
	string temp;
	for( int i=1; i<10; ++i )
	{
		string X = intToString( i );
		bigNum approx = bigNum( X ) * bigNum( X );
		if( approx == T ) 
			return X;
		else if( approx < T ) 
			temp = X;
		else
			return temp;
	}
	return "-1";
}

/* subtracting two bigNums 
 * assumptions: A >= B */
bigNum operator - (bigNum A, bigNum B)
{
	bigNum C;
	if( A.number == B.number )
		return bigNum( "0" );
	
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
		A.number = addTrailingZeroes(A,diff);
		C.ds = B.ds;
	}
	else if (A.ds > B.ds)
	{
		diff = A.ds - B.ds;
		B.number = addTrailingZeroes(B,diff);
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
	int nextCarry=0;
	/* now add the strings bit by bit, starting from the rightmost bit */
	for (int i=highDig-1;i>=0;--i)
	{
		int tempA = (int)A.number[i]-48;
		int tempB = (int)B.number[i]-48+carry;
		if( tempA < tempB )
		{
			tempA += 10;
			nextCarry = 1;
		}
		else
		{
			nextCarry = 0;
		}
		int subt = tempA-tempB;
		stringstream out;
		out << subt; 
		#if DEBUG	
			cout << C.number << endl;
		#endif
		carry = nextCarry;
		C.number = out.str() + C.number;
	}
	C.number = removeLeadingZeroes( C.number );
	C.updateS();
	return C;
}

bigNum multiply(bigNum A, bigNum B, vector<string> &M, vector<int> &firstDigit, vector<int> &lastDigit)
{
	bigNum C("0");
	int currMult;
	int carry;
	/* multiply each digit in B (starting with the right most) and add it to C */
	int addZeroes=0;
	map<char,int> numbers;
	numbers['0'] = 0; numbers['3'] = 3; numbers['6'] = 6; numbers['8'] = 8; 
	numbers['1'] = 1; numbers['4'] = 4; numbers['7'] = 7; numbers['9'] = 9;
	numbers['2'] = 2; numbers['5'] = 5;
	map<char,bigNum> partialResults;
	for (int i=B.s+B.ds-1;i>=0;--i)
	{
		bigNum T;
		carry = 0;
		if( partialResults.find( B.number[i] ) == partialResults.end() )
		{
			/* iterate through string A and multiply with digit chosen above */
			for (int j=A.s+A.ds-1;j>=0;--j)
			{
				currMult = (B.number[i]-48)*(A.number[j]-48)+carry;
				//currMult = numbers[B.number[i]]*numbers[A.number[j]]+carry;
				//currMult = mults[B.number[i]][A.number[j]]+carry;
				stringstream out;
				//out<< currMult%10;
				out << lastDigit[currMult];
				T.number = out.str() + T.number;
				//carry = currMult/10;
				carry = firstDigit[currMult];
			}
			/* dont forget the carry! */
			if (carry)
			{	
				stringstream out;
				out << carry;
				T.number = out.str() + T.number;
			}
			partialResults[B.number[i]] = T;
		}
		else
		{
			T = partialResults[B.number[i]];
		}
		M.push_back( removeLeadingZeroes( T.number ) );
		T.number = addTrailingZeroes(T,addZeroes);
		T.updateS();
		C.updateS();
		C = C+T;
		++addZeroes;
	}
	C.ds = A.ds + B.ds;
	C.s  = (int)C.number.size()-C.ds;
	return C;
}


int main ()
{
	vector<int> lastDigit;
	vector<int> firstDigit;
	for( int i=0; i<90; ++i )
	{
		lastDigit.push_back( i%10 );
		firstDigit.push_back( i/10 );
	}
	int T;
	scanf( "%d\n", &T );
	set<int> allMults;
	for( int i=0; i<T; ++i )
	{
		char lineR[1002];
		string line;
		scanf( "%s\n", lineR );
		line = lineR; 
		size_t op;
		op = line.find( '+' );
		if( op == string::npos )
		{
			op = line.find( '-' );
			if( op == string::npos )
			{
				op = line.find( '*' );
			}
		}
		char optr = line[op];
		string num1 = line.substr( 0, op );
		string num2 = line.substr( op+1 );
		switch( optr )
		{
			case '+': 
			{
				bigNum result = bigNum( num1 )+bigNum( num2 );
				int numDashes = max( num2.size()+1 , result.number.size() );
				int numSpaces = max( max( num1.size(), num2.size()+1) , result.number.size() );
				printf( "%s%s\n", printSpaces( num1.size(), numSpaces ).c_str(), num1.c_str() ); 
				printf( "%s%c%s\n", printSpaces( num2.size()+1, numSpaces ).c_str(), optr, num2.c_str() );
				printf( "%s%s\n", printSpaces( numDashes, numSpaces ).c_str(), printDashes( numDashes ).c_str() );
				printf( "%s%s\n", printSpaces( result.s, numSpaces ).c_str(), result.number.c_str() );
				break;
			}
			case '-': 
			{
				bigNum result = bigNum( num1 )-bigNum( num2 );
				int numDashes = max( num2.size()+1, result.number.size() );
				int numSpaces = max( max( num1.size(), num2.size()+1) , result.number.size() );
				printf( "%s%s\n", printSpaces( num1.size(), numSpaces ).c_str(), num1.c_str() ); 
				printf( "%s%c%s\n", printSpaces( num2.size()+1, numSpaces ).c_str(), optr, num2.c_str() );
				printf( "%s%s\n", printSpaces( numDashes, numSpaces ).c_str(), printDashes( numDashes ).c_str() );
				printf( "%s%s\n", printSpaces( result.s, numSpaces ).c_str(), result.number.c_str() );
				break;
			}
			case '*': 
			{
				vector<string> Ms;
				bigNum result = multiply( bigNum( num1 ), bigNum( num2 ), Ms, firstDigit, lastDigit );
				int numSpaces = max( max( num1.size(), num2.size()+1 ), result.number.size() );
				int numDashes2 = result.number.size();
				printf( "%s%s\n", printSpaces( num1.size(), numSpaces ).c_str(), num1.c_str());
				printf( "%s%c%s\n", printSpaces( num2.size()+1, numSpaces ).c_str(), optr, num2.c_str() );
				if( num2.size() > 1 )
				{
					int numDashes1 = max( num2.size()+1, Ms[0].size() );
					printf( "%s%s\n",printSpaces( numDashes1, numSpaces ).c_str() , printDashes( numDashes1 ).c_str() );
					int size = Ms.size();
					for( int k=0; k<size; ++k )
					{
						printf( "%s%s\n", printSpaces( Ms[k].size()+k, numSpaces ).c_str() , Ms[k].c_str());
					}
					printf( "%s%s\n",printSpaces( numDashes2, numSpaces ).c_str(), printDashes( numDashes2 ).c_str() );
					result.updateS();
					printf( "%s%s\n",  printSpaces( removeLeadingZeroes(result.number).size(), numSpaces ).c_str(), removeLeadingZeroes(result.number).c_str());
					}
				else
				{
					printf( "%s\n", printDashes( numDashes2 ).c_str() );
					result.updateS();
					printf( "%s%s\n",  printSpaces( removeLeadingZeroes(result.number).size(), numDashes2 ).c_str(), removeLeadingZeroes(result.number).c_str() );
				}
				break;
			}
		}
		if( i != T-1 )
			cout << endl;
	}
	for( set<int>::iterator it=allMults.begin();it!=allMults.end();++it)
		cout << *it << endl;
}
