#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

int main ()
{
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    if (i == 0) cin.ignore();
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    map<char, int> M;
    while (ss >> token) {
      for(int k = 0; k < int(token.size()); k++) {
        M[token[k]]++;
      }
    }
    vector<pair<int, char> > P;
    for(map<char,int>::iterator it = M.begin();
        it != M.end();
        it++) {
      P.push_back(make_pair(it->second, it->first));
    }
    sort(P.begin(), P.end(), greater< pair<int,char> >());
    int mostCommon = P[0].first;
    bool done = false;
    for(int i = 1; i < int(P.size()); i++) {
      if (P[i].first == mostCommon) {
        cout << "NOT POSSIBLE" << endl;
        done = true;
        break;
      }
    }
    if (done)
      continue;
    int mapping = ('E' - P[0].second + 26) % 26;
    cout << (P[0].second - 'E' + 26) % 26 << " ";
    for(int k = 0; k < int(line.size()); k++) {
      if (line[k] == ' ')
        cout << ' ';
      else {
        char c;
        if (line[k] + mapping >= 'Z') {
          c = line[k] - 26 + mapping;
        }
        else
          c = line[k] + mapping;
        cout << char(c);
      }
    }
    cout << endl;
  }
}
