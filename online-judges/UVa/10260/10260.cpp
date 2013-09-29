/* Alex Velazquez
 * Start: Sun Sep 29 17:06:48 EDT 2013
 * End  : Sun Sep 29 17:24:10 EDT 2013
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

string soundex (string word, vector<int>& dict) {
  string S;
  REP(i, SZ(word)) {
    int num = dict[word[i]-'A'];
    if (num != 0) {
      S += char(48+num);
    }
  }
  return S;
}

string remove_duplicates (string word, vector<int>& dict) {
  int i = 0;
  while (i < SZ(word)-1) {
    if (dict[word[i]-'A'] == dict[word[i+1]-'A']) {
      word.erase(i+1, 1);
    }
    else
      i++;
  }
  return word;
}

int main ()
{
  vector<int> dict(26, 0);
  dict['B'-'A'] = 1;  dict['F'-'A'] = 1;  dict['P'-'A'] = 1;  dict['V'-'A'] = 1;
  dict['C'-'A'] = 2;  dict['G'-'A'] = 2;  dict['J'-'A'] = 2;  dict['K'-'A'] = 2;  dict['Q'-'A'] = 2;  dict['S'-'A'] = 2;  dict['X'-'A'] = 2;  dict['Z'-'A'] = 2;
  dict['D'-'A'] = 3;  dict['T'-'A'] = 3;
  dict['L'-'A'] = 4;
  dict['M'-'A'] = 5;  dict['N'-'A'] = 5;
  dict['R'-'A'] = 6;
  string word;
  while (cin >> word) {
    word = remove_duplicates(word, dict);
    cout << soundex(word, dict) << endl;
  }
}
