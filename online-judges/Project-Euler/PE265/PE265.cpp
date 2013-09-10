#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <set>

using namespace std;

struct BinaryString {
  string s;
  string prefix;
  string suffix;
  BinaryString(string S) : s(S), prefix(S.substr(0,4)), suffix(S.substr(1)) {}
};

set<string> answers;

typedef unsigned long long int ulld;

void dfs(string s, map<string, vector<string> >&M, map<string, bool>& visited, deque<string> &currSeq, int &explored) {
  if (!visited[s]) {
    explored++;
    visited[s] = true;
    currSeq.push_back(s);
    if (explored == 32 && !s.substr(1).compare("0000")) {
      // output the sequence
      string ans;
      ans += currSeq[0];
      for (int k = 1; k <= 27; k++) {
        ans += currSeq[k][4];
      }
      answers.insert(ans);
    }
    for (vector<string>::iterator it = M[s].begin();
        it != M[s].end();
        it++) {
      dfs(*it, M, visited, currSeq, explored);
    }
    explored--;
    visited[s] = false;
    currSeq.pop_back();
  }
}

int binaryToInt (string S) {
  ulld result = 0;
  for (int k = 31; k >= 0; k--) {
    if (S[k] == '1') {
      result += (1LL << (31-k));
    }
  }
  return result;
}

int main ()
{
  vector<BinaryString> vs;
  for (int i = 0; i < 32; i++) {
    string s;
    for (int k = 4; k >= 0; k--) {
      if ( (1 << k) & i ) {
        s += '1';
      }
      else {
        s += '0';
      }
    }
    vs.push_back(BinaryString(s));
  }
  // create graph
  map<string, vector<string> > M;
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      if (i != j) {
        if (!vs[i].suffix.compare(vs[j].prefix)) {
          M[vs[i].s].push_back(vs[j].s);
        }
      }
    }
  }
  map<string, bool> visited;
  int explored = 0;
  deque<string> currSeq;
  dfs(string("00000"), M, visited, currSeq, explored);
  cout << binaryToInt("00000111110111001101011000101001") << endl;
  ulld num = 0;
  for (set<string>::iterator it = answers.begin();
      it != answers.end();
      it++) {
    cout << *it << " " << binaryToInt(*it) << endl;
    num += binaryToInt(*it);
  }
  cout << num << endl;
}
