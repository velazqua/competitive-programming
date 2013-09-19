#include <iostream>
#include <string>

using namespace std;

struct Posession
{
	int min;
	int sec;
	int total;
	int points;
	Posession() : min(0), sec(0), total(0), points(0) {}
};

ostream& operator << (ostream& os, const Posession &P)
{
	os << P.total/60 << ":" << P.total%60;
	return os;
}

int addTime (string a, string b)
{
	return int(60*(10*(int(a[0])-48)+(int(a[1])-48))+(int(a[3])-48)*10+(int(a[4])-48))-int(60*(10*(int(b[0])-48)+(int(b[1])-48))+(int(b[3])-48)*10+(int(b[4])-48));
}


int main ()
{
	int N,T;
	cin >> N;
	string timer;
	int c=0;
	Posession A;
	Posession B;
	bool isAWinning=false;
	bool isTie=true;
	string lastTimer;
	for (int i=0;i<N;++i)
	{
		cin >> T;
		cin >> timer;
		switch (T)
		{
			case 1 : ++A.points; break;
			case 2 : ++B.points; break;
		}		
		if (c != 0)
		{
			if (A.points > B.points)
			{
				if (!isAWinning) //were they losing? Add
				{
					A.total += addTime(timer,lastTimer);
					lastTimer=timer;
				}
				
				isAWinning=true;
				isTie=false;
			}
			else if (B.points > A.points )
			{
				if (isAWinning) //were they losing? Add
				{
					B.total += addTime(timer,lastTimer);
					lastTimer=timer;
				}
				isAWinning=false;
				isTie=false;
			}
			else
			{
				if (isAWinning) // was team A winning? Then add their time
				{
					A.total += addTime(timer,lastTimer);
					lastTimer=timer;
				}
				else // team B was winning. Add their time
				{
					B.total += addTime(timer,lastTimer);
					lastTimer=timer;
				}
				isAWinning=false;
				isTie=true;
			}
		}
		else
		{
			lastTimer=timer;
			if (A.points > B.points)
			{
				isTie=false;
				isAWinning=true;
			}
			else if (A.points < B.points)
			{
				isTie=false;
				isAWinning=false;
			}
			else
			{
				isTie=true;		
				isAWinning=false;
			}
		}
		++c;
	}
	
	if (isAWinning)
	{
		A.total += addTime("48:00",timer);
	}
	else if (!isTie)
	{
		B.total += addTime("48:00",timer);
	}
	
	cout << A << endl;
	cout << B << endl;
}

