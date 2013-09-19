/* Alex Velazquez
 * Start: Thu Nov  1 10:07:07 EDT 2012
 * End  : Thu Nov  1 11:55:48 EDT 2012
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

struct Cell {
   int knight;
   int bishop;
   int reflection;
   bool unreachable;
   Cell () : knight(2000000), bishop(2000000), reflection(2000000), unreachable(false) {}
};

struct Move {
   int x;
   int y;
   int prev;
   Move (int X, int Y, int P) : x(X), y(Y), prev(P) {}
};

bool isOk (int x, int y, int N) {
   return x >= 0 && x < N && y >= 0 && y < N;
}

void moveRegular(vector< vector<Cell> > &G, Move &pos, int size, vector<Move> &newPositions, int steps, bool &found, int &endx, int &endy) {
   if (pos.prev == 0)
      return;
   int arrx[8] = {-1,-1,1,1,-2,-2,2,2};
   int arry[8] = {-2,2,-2,2,-1,1,-1,1};
   REP( i, 8 ) {
      int X = pos.x+arrx[i];
      int Y = pos.y+arry[i];
      if (isOk(X,Y,size) ) {
         if( X == endx && Y == endy) {
            found = true;
            return;
         }
         if (!G[X][Y].unreachable && steps < G[X][Y].knight) {
            G[X][Y].knight = steps;
            #if DEBUG
               cout << pos.x << " " << pos.y << endl;
               cout << "Going to (" << X << "," << Y << ") as a regular knight" << endl;
            #endif
            newPositions.PB(Move(X, Y, 0));
         }
      }
   }
}

void moveBishop(vector< vector<Cell> > &G, Move &pos, int size, vector<Move> &newPositions, int steps, bool &found, int &endx, int &endy) {
   if (pos.prev == 1)
      return;
   int arrx[8] = {-2,-2,2,2};
   int arry[8] = {-2,2,-2,2};
   REP( i, 4 ) {
      int X = pos.x+arrx[i];
      int Y = pos.y+arry[i];
      if (isOk(X,Y,size)) {
         if( X == endx && Y == endy) {
            found = true;
            return;
         }
         if (!G[X][Y].unreachable && steps < G[X][Y].bishop) {
            G[X][Y].bishop = steps;
            #if DEBUG
               cout << "Going to (" << X << "," << Y << ") as a bishop" << endl;
            #endif
            newPositions.PB(Move(X, Y, 1));
         }
      }
   }   
}

void moveReflection(vector< vector<Cell> > &G, Move &pos, int size, vector<Move> &newPositions, int steps, bool &found, int &endx, int &endy) {
   if (pos.prev == 2)
      return;
   int arrx[2] = {pos.x,size-pos.x-1};
   int arry[2] = {size-pos.y-1,pos.y};
   REP( i, 2 ) {
      int X = arrx[i];
      int Y = arry[i];
      if (isOk(X,Y,size)) {
         if( X == endx && Y == endy) {
            found = true;
            return;
         }
         if (!G[X][Y].unreachable && steps < G[X][Y].reflection) {
            G[X][Y].reflection = steps;
            #if DEBUG
               cout << "Going to (" << X << "," << Y << ") as a reflection" << endl;
            #endif
            newPositions.PB(Move(X, Y, 2));
         }
      }
   }
}

int main ()
{
   int N;
   while (cin >> N) {
      if (!N)
         break;
      int startx, starty, endx, endy;
      cin >> startx >> starty >> endx >> endy;
      startx--; starty--;
      endx--; endy--;
      int x, y;
      vector< vector<Cell> > G(2*N, vector<Cell>(2*N, Cell()));
      while (cin >> x >> y) {
         if (!x && !y)
            break;
         G[x-1][y-1].unreachable = true;
      }
      if (startx == endx && starty == endy) {
         cout << "Result : 0" << endl;
         continue;
      }
      vector<Move> positions;
      positions.PB(Move(startx, starty, -1));
      int steps = 0;
      bool found = false;
      while (!positions.empty()) {
         vector<Move> newPositions;
         ++steps;
         while (!positions.empty()) {
            Move pos = positions.back();
            positions.pop_back();
            if (pos.x == endx && pos.y == endy) {
               found = true;
               cout << steps << endl;
               break;
            }
            #if DEBUG
               cout << "====== STEP " << steps << " =======" << endl; 
            #endif
            moveRegular(G, pos, 2*N, newPositions, steps, found, endx, endy);
            moveBishop(G, pos, 2*N, newPositions, steps, found, endx, endy);
            moveReflection(G, pos, 2*N, newPositions, steps, found, endx, endy);
            if( found ) {
               cout << "Result : " << steps << endl;
               break;
            }
         }
         if (found)
            break;
         positions = newPositions;
      }
      if (!found) {
         cout << "Solution doesn't exist" << endl;
      }
   }
}
