#include <iostream>
#include <vector>

using namespace std;

void printStar (vector< vector<char> >& V, int m) {
  for(int i = 0; i < m; i++) {
    int sIndex = -1;
    for(int j = m-1; j >= 0; j--) {
      if (V[i][j] != ' ') {
        sIndex = j+1;
        break;
      }
    }
    for(int j = 0; j < sIndex; j++) {
      cout << V[i][j];
    }
    cout << endl;
  }
}

int main ()
{
  int N;
  while (cin >> N) {
    if (!N) break;
    int m = 4*N + 1;
    vector< vector<char> > V(m, vector<char>(m, ' '));
    // horizontal lines and vertical lines
    for(int i = 0; i < m; i++) {
      V[N][i] = '*';
      V[m-N-1][i] = '*';
      V[i][N] = '*';
      V[i][m-N-1] = '*';
    }

    // diagonals
    for(int i = 0; i < m-N-1; i++) {
      V[i][i+N] = '*';
      V[i+N][i] = '*';
      V[i][m-N-1-i] = '*';
      V[i+N][m-1-i] = '*';
    }
    printStar(V, m);
  }
}
