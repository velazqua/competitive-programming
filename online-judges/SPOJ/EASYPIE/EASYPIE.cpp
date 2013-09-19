/* Name: Alex Velazquez
 * Start Date: October 23, 2011 @ 08:36PM
 * End Date:   October 23, 2011 @ ??:??PM
*/

#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <list>

using namespace std;

struct Problem {
	char problemId;
	bool accepted;
	int totalTime;
	int totalTries;
	Problem () {}
	Problem (char id, char ac, int ttime, int ttries) 
	{
		problemId = id;
		if( ac == 'A' ) 
		{
			accepted = true; 
			totalTime = ttime;
			++totalTries;
		}
		else 
		{
			accepted = false;
			++totalTries;
		}
	}
	 
};

struct Team {
	string teamName;
	map<char,Problem> problems;
	Team (string tn)
	{
		teamName = tn;
	}
};

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		int S;
		cin >> S;
		list<string> teams;
		for( int j=0; j<S; ++j )
		{
			int t;
			string teamName;
			char problemID, result;
			cin >> t >> teamName >> problemID >> result;
			// Create team
			if( teams.find( teamName ) == teams.end() ) // team does not exist
			{
				Team team( teamName );
				teams.push_back( teamName );
			}
			else // team already exists
			{
				
			}
			
		}
	}
}
