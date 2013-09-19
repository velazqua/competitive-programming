/* Name: Alex Velazquez
 * Start Date: October 26, 2011 @ 09:46PM
 * End Date:   October 26, 2011 @ 10:40PM
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int whosWinning( int score1, int score2 )
{
	return (score1==score2)?0:((score1>score2)?1:2);
}

void copyValues( int &oldA, int &newA, int &oldB, int &newB )
{
	oldA = newA;
	oldB = newB;
} 

int addSeconds(int newMinutes, int newSeconds, int &oldMinutes, int &oldSeconds )
{
	return (newMinutes*60+newSeconds)-(oldMinutes*60+oldSeconds);
}

int main ()
{
	int N;
	cin >> N;
	int team1=0, team2=0;
	int lastMinute = 0, lastSecond = 0;
	int totalSeconds1 = 0, totalSeconds2 = 0;
	int bstate = 0, astate = 0; // 0->tie, 1->team1 is winning, 2->team2 is winning
	for( int i=0; i<N; ++i )
	{
		int whoScored;
		cin >> whoScored;
		// check current score
		bstate = whosWinning( team1, team2 );
		if( whoScored == 1 ) ++team1; else ++team2;
		// check current score again. decide who to
		// add minutes|seconds to
		astate = whosWinning( team1, team2 );
		string time;
		cin >> time;
		string M, S;
		M = time.substr(0,2);
		S = time.substr(3,2);
		istringstream m(M), s(S);
		int minutes, seconds;
		m >> minutes; s >> seconds;
		/*
		cout << "astate: " << astate << ". bstate: " << bstate << endl;
		cout << "minutes: " << minutes << ". seconds: " << seconds << endl;
		cout << "lastMinute: " << lastMinute << ". lastSecond: " << lastSecond << endl;
		*/
		if( bstate == 0 && astate == 2 || bstate == 0 && astate == 1 )
			copyValues( lastMinute, minutes, lastSecond, seconds );
		else if( bstate == 1 && astate == 0 )
		{
			totalSeconds1 += addSeconds( minutes, seconds, lastMinute, lastSecond );
			copyValues( lastMinute, minutes, lastSecond, seconds );
		}
		else if( bstate == 2 && astate == 0 )
		{
			totalSeconds2 +=  addSeconds( minutes, seconds, lastMinute, lastSecond );
			copyValues( lastMinute, minutes, lastSecond, seconds );			
		}
		/*
		cout << ((totalSeconds1/60 < 10)?"0":"") << totalSeconds1/60 << ":" << ((totalSeconds1%60 < 10)?"0":"") << totalSeconds1%60 << endl;
		cout << ((totalSeconds2/60 < 10)?"0":"") << totalSeconds2/60 << ":" << ((totalSeconds2%60 < 10)?"0":"") << totalSeconds2%60 << endl;
		*/
	}

	if( astate == 1 )
		totalSeconds1 +=  addSeconds( 48, 0, lastMinute, lastSecond );
	else if( astate == 2 )
		totalSeconds2 +=  addSeconds( 48, 0, lastMinute, lastSecond );
	
	cout << ((totalSeconds1/60 < 10)?"0":"") << totalSeconds1/60 << ":" << ((totalSeconds1%60 < 10)?"0":"") << totalSeconds1%60 << endl;
	cout << ((totalSeconds2/60 < 10)?"0":"") << totalSeconds2/60 << ":" << ((totalSeconds2%60 < 10)?"0":"") << totalSeconds2%60 << endl;
	
}
