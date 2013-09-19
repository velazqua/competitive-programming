/* Alex Velazquez
 * Start: Mon Dec  5 20:01:34 EST 2011
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
#include <string>

using namespace std;

int main ()
{
	map<string,char> M;
	M[".-"] = 'A';M[".---"] = 'J';M["..."] = 'S';M[".----"] = '1';M[".-.-.-"] = '.';M["---..."] = ':';
	M["-..."] = 'B';M["-.-"] = 'K';M["-"] = 'T';M["..---"] = '2';M["--..--"] = ',';M["-.-.-."] = ';';
	M["-.-."] = 'C';M[".-.."] = 'L';M["..-"] = 'U';M["...--"] = '3';M["..--.."] = '?';M["-...-"] = '=';
	M["-.."] = 'D';M["--"] = 'M';M["...-"] = 'V';M["....-"] = '4';M[".----."] = '\'';M[".-.-."] = '+';
	M["."] = 'E';M["-."] = 'N';M[".--"] = 'W';M["....."] = '5';M["-.-.--"] = '!';M["-....-"] = '-';
	M["..-."] = 'F';M["---"] = 'O';M["-..-"] = 'X';M["-...."] = '6';M["-..-."] = '/';M["..--.-"] = '_';
	M["--."] = 'G';M[".--."] = 'P';M["-.--"] = 'Y';M["--..."] = '7';M["-.--."] = '(';M[".-..-."] = '\"';
	M["...."] = 'H';M["--.-"] = 'Q';M["--.."] = 'Z';M["---.."] = '8';M["-.--.-"] = ')';M[".--.-."] = '@';
	M[".."] = 'I';M[".-."] = 'R';M["-----"] = '0';M["----."] = '9';M[".-..."] = '&';
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		string line;
		if( i == 0 )
			cin.ignore();
		getline( cin, line );
		cout << "Message #" << i+1 << endl;
		string token;
		int size = line.size();
		bool dSpace = false;
		for( int k=0; k<size; ++k )
		{
			if( line[k] == '.' || line[k] == '-' )
			{
				token += line[k];
				dSpace = false;
			}
			if( line [k] == ' ' )
			{
				if( !dSpace )
				{
					cout << M[token];
					token = "";
					dSpace = true;
				}
				else
				{
					cout << " ";
					dSpace = false;
				}	
			}
			if( k == size-1 )
			{
				cout << M[token] << endl;
				token = "";
				dSpace = false;
			}
		}
		if( i != T-1 )
			cout << endl;
	}
}
