/* Name: Alex Velazquez
 * Start Date: September 05, 2011 @ 12:07AM
 * End Date:   ???
 * Purpose: To solve the UVa problem 10194 - Football (aka Soccer)
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=98&page=show_problem&problem=1135
 * */

#include <iostream>
#include <set>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std;

struct Team {
	string team_name;
	int total_points;
	int games_played;
	int wins;
	int ties;
	int losses;
	int goal_difference;
	int goals_scored;
	int goals_against;
	Team (string name) : team_name(name), total_points(0), games_played(0), wins(0),\
		ties(0), losses(0), goal_difference(0), goals_scored(0), goals_against(0) {}
	void update (int GS, int GA)
	{
		goals_scored += GS;
		goals_against += GA;
		goal_difference = goals_scored - goals_against;
		if (GS > GA) 
		{
			++wins;
			total_points += 3;
		}
		else if (GA > GS)
			++losses;
		else
		{
			++ties;
			total_points += 1;
		}
		++games_played;
	}
};

int caseInsensitiveStringCompare( const std::string& str1, const std::string& str2 ) {
    std::string str1Cpy( str1 );
    std::string str2Cpy( str2 );
    std::transform( str1Cpy.begin(), str1Cpy.end(), str1Cpy.begin(), ::tolower );
    std::transform( str2Cpy.begin(), str2Cpy.end(), str2Cpy.begin(), ::tolower );
    return str1Cpy.compare(str2Cpy);
}

bool operator < (Team const& A, Team const& B)
{
	if (A.total_points > B.total_points)
		return true;
	else if (A.total_points < B.total_points)
		return false;
	else
	{
		if (A.wins > B.wins)
			return true;
		else if (A.wins < B.wins)
			return false;
		else
		{
			if (A.goal_difference > B.goal_difference)
				return true;
			else if (A.goal_difference < B.goal_difference)
				return false;
			else
			{
				if (A.goals_scored > B.goals_scored)
					return true;
				else if (A.goals_scored < B.goals_scored)
					return false;
				else
				{
					if (A.games_played < B.games_played)
						return true;
					else if (A.games_played > B.games_played)
						return false;
					else
					{
						if (caseInsensitiveStringCompare(A.team_name,B.team_name) <= 0)
							return true;
						else
							return false;
					}
				}
			}
		}
	}
}

int main ()
{
	int T;
	cin >> T;
	//cout << T << endl;
	for (int i=0;i<T;++i)
	{
		string tournament;
		if (i == 0) cin.ignore();
		getline(cin,tournament);
		int number_of_teams;
		cin >> number_of_teams;
		//cout << number_of_teams << "!" << endl;
		map<string,Team> allTeams;
		string team;
		for (int j=0;j<number_of_teams;++j)
		{
			if (j==0) cin.ignore();
			getline(cin,team);
			allTeams.insert(make_pair(team,Team(team)));
			//cout << team << "!" << endl;
		}
		int number_of_games;
		cin >> number_of_games;
		//cout << number_of_games << "!" << endl;
		/* main input (game stats)*/
		for (int k=0;k<number_of_games;++k)
		{
			string line;
			string T1, T2, G1, G2;
			int G1s, G2s;
			if (k==0) cin.ignore();
			getline(cin,line);
			int pound1, pound2, arroba;
			pound1 = line.find('#');
			pound2 = line.rfind('#');
			arroba = line.find('@');
			T1 = line.substr(0,pound1);
			T2 = line.substr(pound2+1);
			G1 = line.substr(pound1+1,arroba-pound1);
			G2 = line.substr(arroba+1,pound2-arroba);
			G1s = atoi(G1.c_str());
			G2s = atoi(G2.c_str());
			//cout << T1 << " " << G1s << " - " << G2s << " " << T2 << endl;
			allTeams.insert(make_pair(T1,Team(T1))).first->second.update(G1s,G2s);
			allTeams.insert(make_pair(T2,Team(T2))).first->second.update(G2s,G1s);
		}
		/* main output */
		int c = 1;
		cout << tournament << endl;
		set<Team> all_teams;
		for (map<string,Team>::iterator it = allTeams.begin();it!=allTeams.end();++it)
		{
			//cout << it->second.team_name << "!!!" << endl;
			all_teams.insert(it->second);
		}
		//cout << all_teams.size() << endl;
		for (set<Team>::iterator it = all_teams.begin();it!=all_teams.end();++it)
		{
			cout << c++ << ") " << it->team_name << " ";
			cout << it->total_points << "p, ";
			cout << it->games_played << "g ";
			cout << "(" << it->wins << "-" << it->ties << "-" << it->losses << "), ";
			cout << it->goal_difference << "gd ";
			cout << "(" << it->goals_scored << "-" << it->goals_against << ")" << endl; 
		}
		cout << ((i+1 == T)?"":"\n");
	}
}
