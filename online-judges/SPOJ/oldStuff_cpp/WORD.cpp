#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

int main ()
{
	int N, K;
	scanf("%d %d", &N, &K);
	list<string> words;
	string w;
	string theWord;
	map<string,pair<string,string> > wordSubs;
	for (int i=0;i<N-K+1;++i)
	{
		cin >> w;
		words.push_back(w);
		wordSubs.insert(make_pair(w,make_pair(w.substr(0,K-1),w.substr(1,K-1))));
	}
	theWord = words.back();
	words.pop_back();
	//for (list<string>::iterator it=words.begin();it!=words.end();++it)
	//	cout << *it << endl;
	//cout << (int)words.size() << endl;
	list<string>::iterator it=words.begin();
	list<string>::iterator itEnd=words.end();
	list<string>::iterator itTemp;
	int ws=K;
	string theWordStart=theWord.substr(0,K-1);
	string theWordFinish=theWord.substr(ws-K+1,K-1);
	
	while (ws != N)
	{
		if (it == itEnd)
			it = words.begin();
		/*
		cout << "theWord: " << theWord << ". ws: " << ws << endl; 
		cout << "it: " << *it << endl;
		cout << theWord.substr(0,K-1) << " " <<  it->substr(1,K-1) << endl; 
		cout << theWord.substr(ws-K+1,K-1) << " " <<  it->substr(0,K-1) << endl;
		*/
		if (theWordStart == wordSubs[*it].second)
		{
			theWord = (*it)[0] + theWord;
			theWordStart = theWord.substr(0,K-1); 
			itTemp = it;
			++it;
			words.erase(itTemp);
			++ws;
		}
		else if (theWord.substr(ws-K+1,K-1) == wordSubs[*it].first)
		{
			theWord += (*it)[K-1];
			theWordFinish = theWord.substr(ws-K+1,K-1);
			itTemp = it;
			++it;
			words.erase(itTemp);
			++ws;
		}
		else
		{
			++it;
		}
	}
	cout << theWord << endl;
}
