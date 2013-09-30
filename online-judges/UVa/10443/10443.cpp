/* Alex Velazquez
 * Start: Mon Sep 30 13:23:26 EDT 2013
 * End  : Mon Sep 30 13:58:36 EDT 2013
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

void printBoard (vector<string>& b, int r, int c) {
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      cout << b[i][j];
    }
    cout << endl;
  }
}

int main ()
{
  int T;
  cin >> T;
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  vector<char> B(26, ' ');
  B['R'-'A'] = 'P';
  B['P'-'A'] = 'S';
  B['S'-'A'] = 'R';
  REP(t, T) {
    if (t != 0)
      cout << endl;
    int r, c, n;
    cin >> r >> c >> n;
    vector<string> board(1, string(c+2, ' '));
    REP(i, r) {
      string line;
      cin >> line;
      line = ' ' + line + ' ';
      board.push_back(line);
    }
    board.push_back(string(c+2, ' '));
    REP(k, n) {
      vector<string> temp(r+2, string(c+2, ' '));
      for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
          bool beat = false;
          REP(d, 4) {
            int x = i + dx[d];
            int y = j + dy[d];
            if (B[board[i][j]-'A'] == board[x][y]) {
              beat = true;
              break;
            }
          }
          if (beat) {
            temp[i][j] = B[board[i][j]-'A'];
          }
          else {
            temp[i][j] = board[i][j];
          }
        }
      }
      board = temp;
    }
    printBoard(board, r, c);
  }
}
