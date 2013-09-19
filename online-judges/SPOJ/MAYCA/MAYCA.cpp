/* Name: Alex Velazquez
 * Start Date: September 17, 2011 @ 04:55PM
 * End Date:   September 16, 2011 @ 05:11PM
 * Purpose: To solve the SPOJ problem #9529 - Maya Calendar"
 * Link: https://www.spoj.pl/problems/MAYCA/
 * */
#include <iostream>
#include <map>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	string sDay, month;
	int day, year;
	map<string,int> monthToInt;
	map<int,string> intToMonth;
	monthToInt["pop"] = 0; monthToInt["xul"] = 5; monthToInt["zac"] = 10;
	monthToInt["no"] = 1; monthToInt["yoxkin"] = 6; monthToInt["ceh"] = 11;
	monthToInt["zip"] = 2; monthToInt["mol"] = 7; monthToInt["mac"] = 12;
	monthToInt["zotz"] = 3; monthToInt["chen"] = 8; monthToInt["kankin"] = 13;
	monthToInt["tzec"] = 4; monthToInt["yax"] = 9; monthToInt["muan"] = 14;
	monthToInt["koyab"] = 16; monthToInt["uayet"] = 18;
	monthToInt["pax"] = 15; monthToInt["cumhu"] = 17;

	intToMonth[0]="imix";intToMonth[5]="cimi";intToMonth[10]="chuen";intToMonth[15]="cib";
	intToMonth[1]="ik";intToMonth[6]="manik";intToMonth[11]="eb";intToMonth[16]="caban";
	intToMonth[2]="akbal";intToMonth[7]="lamat";intToMonth[12]="ben";intToMonth[17]="eznab";
	intToMonth[3]="kan";intToMonth[8]="muluk";intToMonth[13]="ix";intToMonth[18]="canac";
	intToMonth[4]="chicchan";intToMonth[9]="ok";intToMonth[14]="mem";intToMonth[19]="ahau";
	
	int numOfDays=0;
	cout << T << endl;
	for (int i=0;i<T;++i)
	{
		numOfDays=0;
		cin >> sDay >> month >> year;
		if ((int)sDay.size() == 3)
			day = 10*((int)sDay[0]-48) + (int)sDay[1]-48;
		else
			day = (int)sDay[0]-48;
		numOfDays = day + monthToInt[month]*20 + year*365;
		cout << numOfDays%13+1 << " " << intToMonth[numOfDays%20] << " " << numOfDays/260 << endl;
	}
}
