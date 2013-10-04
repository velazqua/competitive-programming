/* Alex Velazquez
 * Start: Mon Sep 30 22:08:26 EDT 2013
 * End  : Mon Sep 30 23:03:01 EDT 2013
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
  int b, w;
  int dx[] = {0, -1, 0, 1};
  int dy[] = {1, 0, -1, 0};
  while (cin >> b >> w) {
    if (!b && !w)
      break;
    vector<string> board;
    vector< vector<int> > visited(b+2, vector<int>(w+2, 0));
    vector<int> occurrances(5, 0);
    board.push_back(string(w+2, '1'));
    REP(i, b) {
      string line;
      cin >> line;
      board.push_back('1'+line+'1');
    }
    board.push_back(string(w+2, '1'));
    int x = b, y = 1;
    int startIndex = 3;
    do {
      REP(i, 4) {
        int index = (startIndex + i) % 4;
        int X = x + dx[index];
        int Y = y + dy[index];
        if (board[X][Y] == '0') {
          x = X;
          y = Y;
          visited[x][y]++;
          if (index == 0) startIndex = 3;
          if (index == 1) startIndex = 0;
          if (index == 2) startIndex = 1;
          if (index == 3) startIndex = 2;
          break;
        }
      }
    } while (!(x == b && y == 1));
    for(int i = 0; i < b+2; i++) {
      for(int j = 0; j < w+2; j++) {
        if (board[i][j] == '0')
          occurrances[visited[i][j]]++;
      }
    }
    for(int i = 0; i < 5; i++) {
      printf("%3d", occurrances[i]);
    }
    printf("\n");
  }
}
