#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  string keyword, text;
  while (cin >> keyword) {
    if (!keyword.compare("THEEND"))
      break;
    cin >> text;
    vector<string> words;
    vector< pair<char, int> > P;
    int size = keyword.size();
    for(int i = 0; i < int(keyword.size()); i++) {
      P.push_back(make_pair(keyword[i], i));
    }
    sort(P.begin(), P.end());
    string temp;
    int c = 0;
    int textSize = text.size();
    for(int i = 0; i < int(text.size()); i++) {
      temp += text[i];
      c++;
      if (c == textSize/size) {
        words.push_back(temp);
        temp.clear();
        c = 0;
      }
    }
    vector<string> ordered(size);
    for(int i = 0; i < size; i++) {
      ordered[P[i].second] = words[i];
    }
    for(int k = 0; k < int(text.size())/size; k++) {
      for(int i = 0; i < size; i++) {
        cout << ordered[i][k];
      }
    }
    cout << endl;
  }
}
