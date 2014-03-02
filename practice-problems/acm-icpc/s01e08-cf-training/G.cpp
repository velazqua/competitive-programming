#include <iostream>
#include <vector>

using namespace std;

void BFS(int node, vector< vector<int> >& G, vector<bool> &used, int &ans) {
  bool alreadyDone = true;
  for(int i = 0; i < int(G[node].size()); i++) {
    if (!used[G[node][i]]) {
      alreadyDone = false;
      used[G[node][i]] = true;
    }
  }
  if (!used[node])
    alreadyDone = false;
  if (!alreadyDone)
    ans++;
  used[node] = true;
}

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector< vector<int> > G(n);
    for(int i = 0 ; i < n; i++) {
      int d;
      cin >> d;
      for(int j = 0; j < d; j++) {
        int num;
        cin >> num;
        G[i].push_back(num-1);
      }
    }
    vector<bool> used(n, false);
    int ans = 0;
    while (true) {
      ans++;

      // find the node which has the most unvisited neighbors
      int node = -1;
      int unvisitedNeighbors = -1;
      for(int i = 0; i < n; i++) {
        int localUN = 0;
        if (!used[i])
          localUN++;
        for(int j = 0; j < int(G[i].size()); j++) {
          if (!used[G[i][j]]) {
            localUN++;
          }
        }
        if (localUN > unvisitedNeighbors) {
          unvisitedNeighbors = localUN;
          node = i;
        }
      }
      // mark as visited
      used[node] = true;
      for(int k = 0; k < int(G[node].size()); k++) {
        used[G[node][k]] = true;
      }
      bool done = true;
      for(int i = 0; i < n; i++) {
        if (!used[i])
          done = false;
      }
      if (done)
        break;
    }
    cout << ans << endl;
  }
}
