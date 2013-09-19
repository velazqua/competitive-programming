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

struct State {
  int currIndex1;
  int currIndex2;
  deque<char> st;
  string ops;
  State(int c1, int c2, deque<char> t, string s) : 
    currIndex1(c1), currIndex2(c2), st(t), ops(s) {}
};

int main ()
{
  string S1, S2;
  while (cin >> S1 >> S2) {
    vector<State> Q;
    Q.push_back(State(0, 0, deque<char>(), string("")));
    int c = 0;
    while (!Q.empty()) {
      int size = Q.size(); 
      for(int i = 0; i < size; i++) {
        // try popping
        if (Q[i].st.size() > 0 && Q[i].st[0] == S2[Q[i].currIndex2]) {
          deque<char> t(Q[i].st);
          t.pop_front();
          Q.push_back(State(Q[i].currIndex1, Q[i].currIndex2 + 1, t, Q[i].ops + " o"));
        }
        if (true) {
          deque<char> t(Q[i].st);
          t.push_front(S1[Q[i].currIndex1]);
          Q.push_back(State(Q[i].currIndex1 + 1, Q[i].currIndex2, t, Q[i].ops + " i"));
        }
      }
      Q.erase(Q.begin(), Q.begin() + size);
      c++;
      if (c == int(S1.size()) * 2)
        break;
    }
    cout << "[" << endl;
    for(vector<State>::iterator it = Q.begin();
        it != Q.end();
        it++) {
      cout << it->ops << endl;
    }
    cout << "]" << endl;
  }
}
