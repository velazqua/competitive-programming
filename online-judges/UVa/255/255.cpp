/* Alex Velazquez
 * Start: Thu Jul 18 19:49:40 PDT 2013
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

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

bool isOk (int x, int y, int K, int Q) {
  int C = x*8+y;
  return x >= 0 && x < 8 && y >= 0 && y < 8 && C != K && C != Q;
}

void isAllowed(int C, int x, int y, int N, vector<vb>& board, int K, int Q) {
  if (N <= 0)
    return;
  int X = C/8+x;
  int Y = C%8+y;
  if (isOk(X, Y, K, Q)) {
    board[X][Y] = true;
    isAllowed(X*8+Y, x, y, N-1, board, K, Q);
  }
}

void kingMoves(int K, int Q, vector<vb>& king) {
  isAllowed(K, 0, 0, 1, king, K, Q);
  isAllowed(K, 0, 1, 1, king, K, Q);
  isAllowed(K, 0, -1, 1, king, K, Q);
  isAllowed(K, 1, 0, 1, king, K, Q);
  isAllowed(K, -1, 0, 1, king, K, Q);
}

void queenMoves(int Q, int K, vector<vb>& queen) {
  isAllowed(Q, 0, 0, 8, queen, K, Q);
  isAllowed(Q, 0, 1, 8, queen, K, Q);
  isAllowed(Q, 0, -1, 8, queen, K, Q);
  isAllowed(Q, 1, 0, 8, queen, K, Q);
  isAllowed(Q, -1, 0, 8, queen, K, Q);
}

int main ()
{
  int K, Q, N;
  while (cin >> K >> Q >> N) {
    if (K == Q)
      cout << "Illegal state" << endl;
    else {
      vector<vb> king(64, vb(64, false));
      vector<vb> queen(64, vb(64, false));

      // KING MOVEMENTS
      kingMoves(K, Q, king);

      // QUEEN MOVEMENTS
      queenMoves(Q, K, queen);

      int x = N/8;
      int y = N%8;

      if (!queen[x][y] || (N == K))
        cout << "Illegal move" << endl;
      else if (king[x][y])
        cout << "Move not allowed" << endl;
      else {
        bool move = false;
        vector<vb> newqueen(64, vb(64, false));
        queenMoves(N, K, newqueen);
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int kx = K/8;
        int ky = K%8;
        for (int i = 0; i < 4; i++) {
          int X = kx+dx[i];
          int Y = ky+dy[i];
          if (isOk(X, Y, K, N) && !newqueen[X][Y]) {
            move = true;
            break;
          }
        }
        if (move)
          cout << "Continue" << endl;
        else
          cout << "Stop" << endl;
      }
    }
  }
}
