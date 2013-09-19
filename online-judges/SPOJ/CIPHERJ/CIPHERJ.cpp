/* Name: Alex Velazquez
 * Start Date: September 17, 2011 @ 05:47PM
 * End Date:   September 17, 2011 @ 06:26PM (TLE)
 * Purpose: To solve the SPOJ problem #9525 - "Cipher"
 * Link: https://www.spoj.pl/problems/CIPHERJ/
 * */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main ()
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		//cin >> n;
		if (n == 0)
			break;
		int a[n];
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
			//cin >> a[i];
		
		int k;
		while (1)
		{
			scanf("%d",&k);
			vector<string> allStrings;
			//cin >> k;
			if (k == 0)
				break;
			string line;
			getline(cin,line);
			line.erase(0,1);
			int sizeLine = (int)line.size();
			if (sizeLine < n)
				for (int j=0;j<n-sizeLine;++j)
					line += " ";

			string newLine=line;
			string originalLine=line;
			int P=-1;
			// find period
			allStrings.push_back(line);
			for (int l=0;l<k;++l)
			{
				//cout << "l: " << l << ".-" << line << "-" << endl;
				for (int h=0;h<n;++h)
				{
					newLine[a[h]-1] = line[h];
				}
				line = newLine;
				allStrings.push_back(line);
				if (originalLine.compare(newLine) == 0) // if equal to original, we have found a period
				{	
					P = l;
					break;
				}
			}
			//cout << "PERIOD: " << P+1 << endl;
			if (P > 0)
				cout << allStrings[k%(P+1)] << endl;
			else
				cout << line << endl;
		}	
		cout << endl;
	}
}
