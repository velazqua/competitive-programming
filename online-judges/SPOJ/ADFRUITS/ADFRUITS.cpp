/* Name: Alex Velazquez
 * Start Date: October 09, 2011 @ 03:20PM
 * End Date:   October 09, 2011 @ ??:??PM
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main ()
{
	string F1, F2;
	while (cin >> F1 >> F2)
	{
		// search substring of F2 in F1
		size_t found = -1; 
		int size2 = F2.size();
		string newF1, newF2;
		set<string> newF1s;
		//cout << "words: " << F1 << " " << F2 << endl;
		for (int k=0;k<size2;++k){
			found = k-1;
			for (int i=k;i<size2;++i)
			{
				found = F1.find(F2[i],found+1);
				if (found == string::npos) // found match
				{
					newF1s.insert(F1+F2.substr(i));
					cout << "newF1: " << F1+F2.substr(i) << ". i: " << i << endl;
					break;
				}
			}		
		}
		int size1 = F1.size();
		// search substring of F1 in F2
		set<string> newF2s;
		for (int k=0;k<size1;++k){
			found = k-1;
			for (int i=k;i<size1;++i)
			{
				found = F2.find(F1[i],found+1);
				if (found == string::npos) // found match
				{
					newF2s.insert(F2+F1.substr(i));
					cout << "newF2: " << F2+F1.substr(i) <<". i: "<<i<< endl;
					break;
				}
			}
		}
		// compare each new names, output shortest one
		newF1 = *(newF1s.begin());
		newF2 = *(newF2s.begin());
		if (F1.compare(F2) == 0)
			cout << F1 << endl;
		else if (newF1.size() == 0)
			cout << newF2 << endl;
		else if (newF2.size() == 0)
			cout << newF1 << endl;
		else
			cout << ((newF1.size()<newF2.size())?newF1:newF2) << endl;
	}
}
