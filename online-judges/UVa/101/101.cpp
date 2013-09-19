/* Alex Velazquez
 * Start: Sat Aug 24 13:14:46 EDT 2013
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

void remove_block(vector<vi> &stacks, int index, int x) {
  REP(i, SZ(stacks[index])) {
    if (stacks[index][i] == x) {
      stacks[index].erase(stacks[index].begin()+i);
      return;
    }
  }
}

void return_blocks(vector<vi> &stacks, int index, int x) {
  bool found = false;
  int foundIndex;
  REP(i, SZ(stacks[index])) {
    int number = stacks[index][i];
    if (found) {
      stacks[number].push_back(number);
    }
    if (number == x) {
      found = true;
      foundIndex = i;
    }
  }
  stacks[index].erase(stacks[index].begin()+foundIndex+1, stacks[index].end());
}

void pile_blocks(vector<vi> &stacks, int indexA, int x, int indexB) {
  int foundIndex;
  REP(i, SZ(stacks[indexA])) {
    int number = stacks[indexA][i];
    if (number == x) {
      foundIndex = i;
      break;
    }
  }
  stacks[indexB].insert(stacks[indexB].end(), stacks[indexA].begin()+foundIndex, stacks[indexA].end());
  stacks[indexA].erase(stacks[indexA].begin()+foundIndex, stacks[indexA].end());
}
    
int find(vector<vi> &stacks, int N, int x) {
  REP(i, N) {
    REP(j, SZ(stacks[i])) {
      if (stacks[i][j] == x)
        return i;
    }
  }
}

int main ()
{
  int N;
  cin >> N;
  string s1, s2;
  int a, b;
  vector< vector<int> > stacks(N);
  REP(i, N)
    stacks[i].push_back(i);
  while (cin >> s1) {
    if (!s1.compare("quit"))
      break;
    cin >> a >> s2 >> b;
    int indexA = find(stacks, N, a);
    int indexB = find(stacks, N, b);
    if (indexA == indexB)
      continue;
    if (!s1.compare("move")) {
      if (!s2.compare("onto")) {
        return_blocks(stacks, indexA, a);
        remove_block(stacks, indexA, a);
        return_blocks(stacks, indexB, b);
        stacks[indexB].push_back(a);
      }
      else { // over
        return_blocks(stacks, indexA, a);
        remove_block(stacks, indexA, a);
        stacks[indexB].push_back(a);
      }
    }
    else { // pile
      if (!s2.compare("onto")) {
        return_blocks(stacks, indexB, b);
        pile_blocks(stacks, indexA, a, indexB);
      }
      else { // over
        pile_blocks(stacks, indexA, a, indexB);
      }
    }
  }
  REP(i, N) {
    cout << i << ":";
    REP(j, SZ(stacks[i])) {
      cout << " " << stacks[i][j];
    }
    cout << endl;
  }
}
