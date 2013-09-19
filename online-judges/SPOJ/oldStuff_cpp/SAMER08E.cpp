#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct E {
	int D;
	int M;
	int Y;
	int C;
	int L;
	E (int d, int m, int y, int c, bool l) : D(d), M(m), Y(y), C(c), L(l){}
};

ostream& operator << (ostream& os, const E& e)
{
	os << e.D << " " << e.M << " " << e.Y << " " << e.C;
	return os;
}

int main ()
{
	int T;
	map<int,int> months;
	months[1]=31;months[2]=28;months[3]=31;months[4]=30;months[5]=31;months[6]=30;
	months[7]=31;months[8]=31;months[9]=30;months[10]=31;months[11]=30;months[12]=31;
	while (1)
	{
		cin >> T;
		if (T==0)
			break;
		months[2]=28;
		int D, M, Y, C;
		bool l;
		vector<E> dates;
		int numDays=0, elec=0;
		for (int i=0;i<T;++i)
		{
			cin >> D >> M >> Y >> C;
			if (Y%400==0)
				l=1;
			else if (Y%100==0)
				l=0;
			else if (Y%4==0)
				l=1;
			else
				l=0;
			E temp (D,M,Y,C,l);
			dates.push_back(temp);
		}

		for (int i=0;i<(int)dates.size()-1;++i)
		{
			//cout << dates[i] << "----" << dates[i+1] << endl;
			if (dates[i].Y == dates[i+1].Y)
			{
				//cout << "SAME YEAR!!" << endl;
				if ((dates[i].M == dates[i+1].M) && (dates[i].D+1==dates[i+1].D))
				{
					//cout << "SAME MONTH" << endl;
					++numDays;
					elec += dates[i+1].C-dates[i].C;
				}
				else if (dates[i].M+1==dates[i+1].M)
				{
					if (dates[i].M==2 && (dates[i].D==months[2]+dates[i].L) && dates[i+1].D==1)
					{
						++numDays;
						elec += dates[i+1].C-dates[i].C;
					}
					else if (dates[i].M != 2 && (dates[i].D==months[dates[i].M]) && dates[i+1].D==1)
					{
						++numDays;
						elec += dates[i+1].C-dates[i].C;
					}
				}
			}
			else if (dates[i].Y +1 == dates[i+1].Y)
			{
				if (dates[i].D==31 && dates[i].M==12 && dates[i+1].M==1 && dates[i+1].D==1)
				{
					++numDays;
					elec += dates[i+1].C-dates[i].C;
				}
			}
		}
		cout << numDays << " " << elec << endl;
	}
}
