/* Alex Velazquez
 * Start: Sun Sep 15 20:49:50 EDT 2013
 * End  :
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef unsigned long long int ulld;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

string clean_up (string S) {
  bool beg = true;
  string newS;
  for(string::iterator it = S.begin();
      it != S.end();
      it++) {
    int num = *it;
    if (num >= 65 && num <= 90) {
      *it = 'a' + num - 'A';
      newS.push_back(*it);
      beg = false;
    }
    else if (num >= 97 && num <= 97+25) {
      newS.push_back(*it);
      beg = false;
    }
    else {
      if (*it == '-') {
        string::iterator nex = it;
        nex++;
        if (nex != S.end()) {
          newS.push_back('-');
        }
      }
    }
  }
  return newS;
}

int main ()
{
  string token;
  string word = "";
  set<string> words;
  while (cin >> token) {
    int size = token.size();
    if (token[size-1] == '-') {
      token = clean_up(token);
      word.insert(word.end(), token.begin(), token.end());
    }
    else {
      token = clean_up(token);
      word.insert(word.end(), token.begin(), token.end());
      words.insert(word);
      word.clear();
    }
  }
  for(set<string>::iterator it = words.begin();
      it != words.end();
      it++) {
    cout << *it << endl;
  }
}
