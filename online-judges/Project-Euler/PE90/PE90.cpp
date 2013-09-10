#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printVector (const set<int>& V) {
  cout << "{";
  for(set<int>::iterator it = V.begin();
      it != V.end();
      it++) 
    cout << *it << ", ";
  cout << "}";
}

int main ()
{
  vector<int> nums;
  for(int i = 0; i < 10; i++)
    nums.push_back(i);
  set< set<int> > allSets;
  do
  {
    set<int> temp;
    for(int i = 0; i < 6; i++) {
      temp.insert(nums[i]);
    }
    allSets.insert(temp);
  } while (next_permutation(nums.begin(), nums.end()));
  int ans = 0;
  for(set< set<int> >::iterator it1 = allSets.begin();
      it1 != allSets.end();
      it1++) {
    set< set<int> >::iterator it2 = it1;
    it2++;
    for ( ; it2 != allSets.end(); it2++) {
      vector<bool> visited(9, false);
      for( set<int>::iterator num1 = it1->begin();
          num1 != it1->end();
          num1++) {
        for( set<int>::iterator num2 = it2->begin();
            num2 != it2->end();
            num2++) {
          int p1 = *num1 * 10 + *num2;
          int p2 = *num2 * 10 + *num1;
          if (p1 == 1 || p1 == 10 || p2 == 1 || p2 == 10)
            visited[0] = true;
          if (p1 == 4 || p1 == 40 || p2 == 4 || p2 == 40)
            visited[1] = true;
          if (p1 == 6 || p1 == 60 || p1 == 9 || p1 == 90 || p2 == 6 || p2 == 60 || p2 == 9 || p2 == 90)
            visited[2] = true;
          if (p1 == 19 || p1 == 91 || p1 == 16 || p1 == 61 || p2 == 19 || p2 == 91 || p2 == 16 || p2 == 61)
            visited[3] = true;
          if (p1 == 25 || p1 == 52 || p2 == 25 || p2 == 52)
            visited[4] = true;
          if (p1 == 39 || p1 == 93 || p1 == 36 || p1 == 63 || p2 == 39 || p2 == 93 || p2 == 36 || p2 == 63)
            visited[5] = true;
          if (p1 == 46 || p1 == 64 || p1 == 49 || p1 == 94 || p2 == 46 || p2 == 64 || p2 == 49 || p2 == 94) {
            visited[6] = true;
            visited[7] = true;
          }
          if (p1 == 81 || p1 == 18 || p2 == 81 || p2 == 18)
            visited[8] = true;
        }
      }
      bool good = true;
      for(int i = 0; i < 9; i++) {
        if (!visited[i]) {
          good = false;
          break;
        }
      }
      if ( good ) {
        ans++;
        printVector(*it1);
        cout << ", ";
        printVector(*it2);
        cout << endl;
      }
    }
  }
  cout << ans << endl;
}
