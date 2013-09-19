/* Alex Velazquez
 * Start: Thu Oct 18 19:46:22 EDT 2012
 * End  : Thu Oct 18 19:55:14 EDT 2012
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

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int value ( string S ) {
   int size = SZ(S);
   if (size<=4)
      return 1;
   if (size==5)
      return 2;
   if (size==6)
      return 3;
   if (size==7)
      return 5;
   return 11;
}

int main ()
{
   int N;
   cin >> N;
   vector< vector<string> > words;
   map<string,int> val;
   REP( i, N ) {
      if( i == 0 )
         cin.ignore();
      string line;
      getline( cin, line );
      stringstream newLine( line );
      string token;
      vector<string> temp;
      while( newLine >> token ) {
         temp.push_back( token );
         pair<map<string,int>::iterator, bool> result = val.insert(make_pair(token,value(token)));
         if (!result.second) {
            val[token] = 0;
         }
      }
      words.push_back( temp );
   }
   int size = SZ(words);
   int maxx = 0;
   REP( i, size ) {
      int size2 = SZ(words[i]);
      int score = 0;
      REP( j, size2 ) {
         score += val[words[i][j]];
      }
      maxx = max(maxx, score);
   }
   cout << maxx << endl;
}
