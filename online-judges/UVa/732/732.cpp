/* Alex Velazquez
 * Start: Fri Aug 16 20:59:48 EDT 2013
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
#include <stack>

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

bool isValid (string S) {
  int i = 0, o = 0;
  for(int k = 0; k < SZ(S); k++) {
    if (o > i)
      return false;
    if (S[k] == 'i') i++;
    else o++;
  }
  return true;
}

string process (string S1, string const& S) {
  string str;
  stack<char> st;
  REP(i, SZ(S)) {
    if (S[i] == 'i') {
      st.push(S1[0]);
      S1.erase(0, 1);
    }
    else {
      str += st.top();
      st.pop();
    }
  }
  return str;
}

int main ()
{
  string S1, S2;
  while (cin >> S1 >> S2) {
    int size1 = SZ(S1);
    if (SZ(S1) != SZ(S2)) {
      cout << "[" << endl << "]" << endl;
      continue;
    }
    string S;
    REP(i, size1)
      S += 'i';
    REP(i, size1)
      S += 'o';
    cout << "[" << endl;
    do {
      // check if current string is valid
      if (S[0] == 'o')
        break;
      if (!isValid(S))
        continue;
      string res = process(S1, S);
      if (!res.compare(S2)) {
        cout << S[0];
        for(int k = 1; k < SZ(S); k++) {
          cout << " " << S[k];
        }
        cout << endl;
      }
    } while(next_permutation(S.begin(), S.end()));
    cout << "]" << endl;
  }
}
