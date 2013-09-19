/* Name: Alex Velazquez
 * Start Date: August 20, 2011 @ 2:55PM
 * End Date: ???????
 * Purpose: To solve the problem #490 (Rotating Sentences) in UVa online judge.
 * Link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=94&page=show_problem&problem=431
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addSpaces (string &S, int X)
{
	for (int i=0;i<X;++i)
		S += " ";
}

int main ()
{
	string S;
	vector<string> sentences;
	int longestString=0;
	while (getline(cin,S))
	{
		if ((int)S.size() > longestString)
			longestString = (int)S.size();
		sentences.push_back(S);
	}
	int numSentences = (int) sentences.size();
	//cout << "Longest string is " << longestString << " chars long." << endl;
	//cout << (int)sentences.size() << " sentences. " << endl;
	for (vector<string>::iterator it=sentences.begin();it!=sentences.end();++it)
	{
		addSpaces(*it,longestString-(int)it->size());
		//cout << *it << " --- has " << (int)it->size() << " chars ." << endl;
	}
	
	/* display output */
	for (int n=0;n<longestString;++n)
	{
		string output="";
		bool foundSpace=false;
		for (int m=0;m<numSentences;++m)
		{
			if (!foundSpace && sentences[m][n] != ' ')
				foundSpace = true;
			if (foundSpace && sentences[m][n] != ' ')
				output = sentences[m][n] + output;
			else if (foundSpace && sentences[m][n] == ' ')
				output = " " + output; //change to asterisk if necessary
			//else
			//	output = " " + output;
		}
		cout << output << endl;
	}
}
