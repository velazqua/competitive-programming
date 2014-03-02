#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    string line;
    vector<string> grid;
    for (int i = 0; i < n; i++) {
      cin >> line;
      grid.push_back(line);
    }
    // Algorithm:
    // Find up-leftmost and bottom-rightmost black squares
    // Assume that these form the corners of our square
    // Check if all cells inside of these two are black
    // If not, we have found a contradiction: return NO
    // Else, return YES
    int x1, y1, x2, y2;
    bool noBlackSquares = true;

    // Find up-leftmost black square
    bool done = false;
    for (int x = 0; x < n; x++) {
      if (done) break;
      for (int y = 0; y < n; y++) {
        if (grid[y][x] == '#') {
          x1 = y;
          y1 = x;
          done = true;
          noBlackSquares = false;
          break;
        }
      }
    }

    // Find bottom-rightmost black square
    done = false;
    for (int x = n-1; x >= 0; x--) {
      if (done) break;
      for (int y = n-1; y >= 0; y--) {
        if (grid[y][x] == '#') {
          x2 = y;
          y2 = x;
          done = true;
          break;
        }
      }
    }
    cout << "Case #" << t+1 << ": ";
    if (noBlackSquares || (abs(x1-x2) != abs(y1-y2))) {
      cout << "NO" << endl;
    }
    else {
      // Check all cells between the two corners
      bool validSquare = true;
      for (int x = x1; x <= x2; x++) {
        if (!validSquare) break;
        for (int y = y1; y <= y2; y++) {
          if (grid[x][y] != '#') {
            validSquare = false;
            break;
          }
        }
      }
      if (validSquare) {
        cout << "YES" << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
  }
}
