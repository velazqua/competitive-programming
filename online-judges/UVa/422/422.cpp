/* Alex Velazquez
 * Start: Sat Dec 10 22:54:01 EST 2011
 * End  :
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>
#include <string>

using namespace std;

int main ()
{
	int N;
	cin >> N;
	vector<string> matrixH(N);
	for( int i=0; i<N; ++i )
		cin >> matrixH[i];
	string word;
	vector<string> words;
	int numWords = 0;
	while( cin >> word )
	{
		if( word[0] == '0' )
			break;
		words.push_back( word );
		numWords += 1;
	}
	// generate vertical lines
	vector<string> matrixV(N);
	for( int i=0; i<N; ++i )
	{
		string w = "";
		for( int j=0; j<N; ++j )
			w += matrixH[j][i];
		matrixV[i] = w;
	}
	// generate diagonal lines
	vector<string> matrixD;
	for( int i=N-1; i>0; --i )
	{
		string w = "";
		int k = i;
		for( int j=0; k<=N-1; ++k, ++j )
			w += matrixH[k][j];
		matrixD.push_back( w );
	}
	for( int i=0; i<N; ++i )
	{
		string w = "";
		int k = i;
		for( int j=0; k<N; ++k, ++j )
			w += matrixH[j][k];
		matrixD.push_back( w );
	}
	for( int i=0; i<numWords; ++i )
	{
		bool foundIt = false;
		cout << "words[i]: " << words[i] << endl;
		// find word in horizontal|vertical lines
		for( int j=0; j<N; ++j )
		{
			size_t found  = matrixH[j].find( words[i] );
			size_t foundV = matrixV[j].find( words[i] );
			string revWords = words[i];
			reverse( revWords.begin(), revWords.end() );
			size_t revfound  = matrixH[j].find( revWords );
			size_t revfoundV = matrixV[j].find( revWords );
			if( found != string::npos ) // if we find a match
			{
				cout << j+1 << "," << found+1 << " ";
				cout << j+1 << "," << words[i].size()+found << endl;
				cout << "i: " << i << endl;
				foundIt = true;
				break; 
			}
			else if( foundV != string::npos ) // if we find a match
			{
				cout << foundV+1 << "," << j+1 << " ";
				cout << words[i].size()-1+j << "," << j+1 << endl;
				//cout << "i: " << i << endl;
				foundIt = true;
				break; 
			}
			else if( revfound != string::npos ) // if we find a match
			{
				cout << j+1 << "," << revWords.size()+revfound << " ";
				cout << j+1 << "," << revfound+1 << endl;
				//cout << "i: " << i << endl;
				foundIt = true;
				break; 
			}
			else if( revfoundV != string::npos ) // if we find a match
			{
				cout << revWords.size()+revfoundV << "," << j+1 << " ";
				cout << revfoundV+1 << "," << j+1 << endl;
				//cout << "i: " << i << endl;
				foundIt = true;
				break; 
			}
		}
		if( foundIt )
			continue;
		// find word in diagonal lines
		for( int j=0; j<2*N; ++j )
		{
			size_t found  = matrixD[j].find( words[i] );
			string revWords = words[i];
			reverse( revWords.begin(), revWords.end() );
			size_t revfound  = matrixD[j].find( revWords );
			if( found != string::npos ) // if we find a match
			{
				cout << j+1 << "," << found+1 << " ";
				cout << j+1 << "," << words[i].size()+found << endl;
				cout << "i: " << i << endl;
				foundIt = true;
				break; 
			}
			else if( revfound != string::npos ) // if we find a match
			{
				cout << j+1 << "," << revWords.size()+revfound << " ";
				cout << j+1 << "," << revfound+1 << endl;
				//cout << "i: " << i << endl;
				foundIt = true;
				break; 
			}
		}	
		cout << "Not found" << words[i] << endl;
	}
}
