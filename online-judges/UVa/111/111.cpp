/* Alex Velazquez
 * Start: Mon Nov 18 12:15:28 EST 2013
 * End  : Mon Nov 18 16:26:04 EST 2013 Mon Nov 18 16:25:45 EST 2013
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

int main ()
{
  int n;
  cin >> n;
  vector<int> correctOrder(n+1);
  correctOrder[0] = -2;
  REP(i, n) {
    int num;
    cin >> num;
    correctOrder[num] = i+1;
  }
  string line;
  getline(cin, line);
  while (getline(cin, line)) {
    vector<int> numbers(n+1);
    numbers[0] = -1;
    istringstream ss(line);
    int val;
    int c = 1;
    while (ss >> val) {
      numbers[val] = c;
      c++;
    }
    // find longest common subsequence
    vector< vector<int> > LCS(n+1, vector<int>(n+1, 0));

    for(int i = 1; i < n+1; i++) {
      for(int j = 1; j < n+1; j++) {
        if (correctOrder[i] == numbers[j]) {
          LCS[i][j] = LCS[i-1][j-1] + 1;
        }
        else {
          LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
        }
      }
    }
    cout << LCS[n][n] << endl;
  }
}
