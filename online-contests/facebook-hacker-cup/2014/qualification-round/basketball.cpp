#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct People {
  string name;
  int shot_perc;
  int height;
  People (string n, int s, int h) : name(n), shot_perc(s), height(h) {}
};

struct Player {
  string name;
  int draft_num;
  int minutes_played;
  Player (string n, int d, int m) : name(n), draft_num(d), minutes_played(m) {}
};

bool operator < (People const& A, People const& B) {
  if (A.shot_perc != B.shot_perc) {
    return A.shot_perc > B.shot_perc;
  }
  else {
    return A.height > B.height;
  }
}

bool highestTimeComp (Player const& A, Player const& B) {
  if (A.minutes_played != B.minutes_played) {
    return A.minutes_played > B.minutes_played;
  }
  else {
    return A.draft_num > B.draft_num;
  }
}

bool lowestDraftComp (Player const& A, Player const& B) {
  if (A.minutes_played != B.minutes_played) {
    return A.minutes_played < B.minutes_played;
  }
  else {
    return A.draft_num < B.draft_num;
  }
}

int main ()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    int N, M, P;
    cin >> N >> M >> P;
    set<People> ppl;
    for(int i = 0; i < N; i++) {
      string name;
      int shot_perc, height;
      cin >> name >> shot_perc >> height;
      ppl.insert(People(name, shot_perc, height));
    }
    vector<Player> team1, bench1;
    vector<Player> team2, bench2;
    int draft = 1;
    for (auto& p : ppl) {
      if (draft % 2) {
        team1.push_back(Player(p.name, draft, 0));
      }
      else {
        team2.push_back(Player(p.name, draft, 0));
      }
      draft++;
    }

    // select the P players per team
    sort(team1.begin(), team1.end(), lowestDraftComp);
    sort(team2.begin(), team2.end(), lowestDraftComp);

    // insert players to bench
    while (team1.size() > P) {
      int size = team1.size();
      bench1.push_back(team1[size-1]);
      team1.pop_back();
    }

    while (team2.size() > P) {
      int size = team2.size();
      bench2.push_back(team2[size-1]);
      team2.pop_back();
    }

    if (bench1.size() > 0) {
      for (int i = 0; i < M; i++) {
        for(auto& p : team1) {
          p.minutes_played++;
        }
        for(auto& p : team2) {
          p.minutes_played++;
        }
        sort(team1.begin(), team1.end(), highestTimeComp);
        sort(team2.begin(), team2.end(), highestTimeComp);
        sort(bench1.begin(), bench1.end(), lowestDraftComp);
        sort(bench2.begin(), bench2.end(), lowestDraftComp);
        team1.push_back(bench1[0]);
        team2.push_back(bench2[0]);
        bench1.push_back(team1[0]);
        bench2.push_back(team2[0]);
        team1.erase(team1.begin());
        team2.erase(team2.begin());
        bench1.erase(bench1.begin());
        bench2.erase(bench2.begin());
      }
    }

    set<string> names;
    for(auto& p : team1) {
      names.insert(p.name);
    }
    for(auto& p : team2) {
      names.insert(p.name);
    }
    cout << "Case #" << t+1 << ":";
    for(auto& n : names) {
      cout << " " << n;
    }
    cout << endl;
  }
}
