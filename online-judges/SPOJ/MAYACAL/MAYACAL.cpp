/* Name: Alex Velazquez
 * Start Date: October 09, 2011 @ 05:52PM
 * End Date:   October 09, 2011 @ ??:??PM
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int LongCalendarToDays (int b, int k, int t, int w, int i)
{
	return b*144000+k*7200+t*360+w*20+i;
}

string DaysToLongCalendarDays (int d)
{
	string date="";
	vector<int> div;
	div.push_back(144000); div.push_back(7200);
	div.push_back(360);div.push_back(20);div.push_back(1);
	stringstream ss;
	ss << d/div[0];
	date += ss.str();
	d -= div[0]*(d/div[0]);
	for (int i=1;i<5;++i)
	{
		stringstream out;
		out << d/div[i];
		date += "."+out.str();
		d -= div[i]*(d/div[i]);
	} 
	return date;
}

int main ()
{
	vector<string> tzolkin;
	tzolkin.push_back("Imix");tzolkin.push_back("Ik");tzolkin.push_back("Akbal");tzolkin.push_back("Kan");
	tzolkin.push_back("Chikchan");tzolkin.push_back("Kimi");tzolkin.push_back("Manik");tzolkin.push_back("Lamat");
	tzolkin.push_back("Muluk");tzolkin.push_back("Ok");tzolkin.push_back("Chuen");tzolkin.push_back("Eb");
	tzolkin.push_back("Ben");tzolkin.push_back("Ix");tzolkin.push_back("Men");tzolkin.push_back("Kib");
	tzolkin.push_back("Kaban");tzolkin.push_back("Etznab");tzolkin.push_back("Kawak");tzolkin.push_back("Ajaw");
	vector<string> haab;
	haab.push_back("Pohp");haab.push_back("Wo");haab.push_back("Sip");haab.push_back("Zotz");haab.push_back("Sek");
	haab.push_back("Xul");haab.push_back("Yaxkin");haab.push_back("Mol");haab.push_back("Chen");haab.push_back("Yax");
	haab.push_back("Sak");haab.push_back("Keh");haab.push_back("Mak");haab.push_back("Kankin");haab.push_back("Muan");
	haab.push_back("Pax");haab.push_back("Kayab");haab.push_back("Kumku");haab.push_back("Wayeb");
	int N;
	while (cin >> N)
	{
		int b,k,t,w,i;
		char d;
		if (N == 0)
			break;
		vector<int> dates;
		for (int j=0;j<N;++j)
		{
			cin >> b >> d >> k >> d >> t >> d >> w >> d >> i;
			cout << b << d << k << d << t << d << w << d << i << endl;
			//dates.push_back(LongCalendarToDays(b,k,t,w,i));
			cout << LongCalendarToDays(b,k,t,w,i)<< " ";
			//cout << ". Calculated date: " << DaysToLongCalendarDays(LongCalendarToDays(b,k,t,w,i)) << endl;
		}
		/*
		for (int j=0;j<N-1;++j)
		{
			cout << dates[j+1]-dates[j] << endl;
		}
		*/
	}
}
