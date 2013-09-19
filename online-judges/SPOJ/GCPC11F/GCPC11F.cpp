/* Alex Velazquez
 * Start: November 22, 2011 @ 09:30PM
 * End  : November 22, 2011 @ 10:24PM
*/

#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#define DEBUG 0

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		string line;
		if( i == 0 )
			cin.ignore();
		getline( cin, line );
		int size = line.size();
		map<char,int> M;
		// map all chars to its number of occurrances in string
		for( int k=0; k<size; ++k )
		{
			if( line[k] == ' ' )
				continue;
			if( M.find( line[k] ) != M.end() )
				++M[line[k]]; 
			else
				M[line[k]] = 1;
		}
		map<int,vector<char>, greater<int> > rM;
		// map number of occurances of any char to its chars
		for( map<char,int>::iterator it=M.begin(); it!=M.end(); ++it )
			rM[it->second].push_back( it->first );	
		#if DEBUG 
			cout << line << endl;
			for( map<int,vector<char> >::iterator it=rM.begin(); it!=rM.end(); ++it )
			{
				cout << it->first << " => {";
				for( vector<char>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2 )
				{
					cout << *it2 << ", ";
				}
				cout << "}" << endl;
			}
		#endif
		// if number of occurrances maps to more than 1 char, then 
		// it is impossible to decode the string!
		map<int,vector<char> >::iterator it = rM.begin();
		if( it->second.size() > 1 )
			cout << "NOT POSSIBLE" << endl;
		else
		{
			// calculate distance
			int E = 5;
			int S = it->second[0]-64;
			int D = ( S >= E ) ? S-E : 26-(E-S);
			cout << D << " ";
			// now decode string
			for( int k=0; k<size; ++k )
			{
				if( line[k] == ' ' )
					cout << ' ';
				else
				{
					int X = 64+((int(line[k])-64)+(26-D))%26;
					cout << char( ( X == 64 ) ? 90 : X );
				}
			}
			cout << endl;
		}
	}
}
