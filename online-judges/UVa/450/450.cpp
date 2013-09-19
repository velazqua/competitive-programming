/* Alex Velazquez
 * Start: Fri Feb 24 19:15:46 EST 2012
 * End  : Wed Feb 29 19:51:46 EST 2012
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct Person {
	string title, firstName, lastName;
	string address, homePhone, workPhone;
	string box, department;
	Person( string t, string f, string l, string a, string h, string w, string b, string d ) : title(t), firstName(f), lastName(l), address(a), homePhone(h), workPhone(w), box(b), department(d) {}
};

bool operator < ( Person const& A, Person const& B )
{
	if( A.lastName.compare( B.lastName ) < 0 )
		return true;
	else
		return false;
}

int main ()
{
	int T;
	cin >> T;
	set<Person> ppl;
	REP( i, T )
	{
		if( i == 0 ) cin.ignore();
		string departmentName;
		getline( cin, departmentName );
		string line;
		//cout << "departmentName: " << departmentName << endl;
		while( getline( cin, line ) )
		{
			if( line.size() == 0 ) break;
			stringstream newLine( line );
			string token;
			vector<string> tokens;
			while( getline( newLine, token, ',' ) )
			{
				tokens.push_back( token );
			}
			ppl.insert( Person( tokens[0],tokens[1],tokens[2],tokens[3],tokens[4],tokens[5],tokens[6], departmentName ) );
		}
	}
	for( set<Person>::iterator it=ppl.begin(); it!=ppl.end(); ++it )
	{
		cout << "----------------------------------------" << endl;
		cout << it->title << " " << it->firstName << " " << it->lastName << endl;
		cout << it->address << endl;
		cout << "Department: " << it->department << endl;
		cout << "Home Phone: " << it->homePhone << endl;
		cout << "Work Phone: " << it->workPhone << endl;
		cout << "Campus Box: " << it->box << endl; 
	}
}
