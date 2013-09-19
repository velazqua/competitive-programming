/* Alex Velazquez
 * Start: November 20, 2011 @ 04:02PM
 * End  : November 20, 2011 @ 04:42PM
*/

#include <iostream>
#include <map>

#define DEBUG 0

using namespace std;

string printSpaces( int n )
{
	string spaces = "";
	for( int i=0; i<7-n; ++i )
		spaces += " ";
	return spaces;
}

int power( int a, int N )
{
	if( N == 0 ) return 1;
	int X = 1;
	for( int i=0; i<N; ++i )
		X *= a;
	return X;
}

int convertToDecimal( string num, int baseFrom, map<char,int> &M )
{
	int size = num.size();
	int D = 0;
	for( int i=0; i<size; ++i )
		D += M[num[i]]*power( baseFrom, size-(i+1) );
	return D;
}

string convertToBaseN ( int D, int baseTo, map<int,char> &M )
{
	//if( baseTo == 10 ) return D;
	string answer = "";
	while( D != 0 )
	{
		answer = M[D%baseTo] + answer;
		D /= baseTo;
	}
	return answer;
}

int main ()
{
	map<char,int> M1;
	M1['0'] = 0;M1['1'] = 1;M1['2'] = 2;M1['3'] = 3;M1['4'] = 4;
	M1['5'] = 5;M1['6'] = 6;M1['7'] = 7;M1['8'] = 8;M1['9'] = 9;
	M1['A'] = 10;M1['B'] = 11;M1['C'] = 12;M1['D'] = 13;M1['E'] = 14;M1['F'] = 15;
	map<int,char> M2;
	M2[0] = '0';M2[1] = '1';M2[2] = '2';M2[3] = '3';M2[4] = '4';
	M2[5] = '5';M2[6] = '6';M2[7] = '7';M2[8] = '8';M2[9] = '9';
	M2[10] = 'A';M2[11] = 'B';M2[12] = 'C';M2[13] = 'D';M2[14] = 'E';M2[15] = 'F';
	string num;
	int baseFrom, baseTo;
	while( cin >> num >> baseFrom >> baseTo )
	{
		if( num == "0" ) 
		{
			cout << "      0" << endl;
			continue;
		}
		int decimal = convertToDecimal( num, baseFrom, M1 );
		string answer = convertToBaseN( decimal, baseTo, M2 );
		#if DEBUG
			cout << "num: " << num << endl;
			cout << "in decimal: " << decimal << endl;	
		#endif
		if( answer.size() > 7 ) cout << "  ERROR" << endl;
		else
		{
			cout << printSpaces( answer.size() ) << answer << endl;
		}
	}
}
