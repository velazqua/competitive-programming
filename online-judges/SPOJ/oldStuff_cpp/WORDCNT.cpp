/* Name: Alex Velazquez
 * Start Date: September 10, 2011 @ 11:55PM
 * End Date:   ???
 * Purpose: To solve the SPOJ problem #3638 - Word Counting
 * Link: https://www.spoj.pl/problems/WORDCNT/
 * */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	string line, token;
	for (int i=0;i<T;++i)
	{
		if (i == 0) cin.ignore();
		getline(cin,line);
		stringstream ss (line);
		while (getline(ss,token,' ')) // getline(ss,token,'\t') || getline(ss,token,'\r') || 
		{
			cout << "token:->" << token << "<-" << endl;
		}
	}
}
