#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

int R, C;
vector<pii> v;

void solve() {
  cin >> R >> C;
  for(int i = 0; i < R; i++) {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int curDist = -1;
    int boat = -1;

    for(int j = 0; j < s.size(); j++) {
      char c = s[j];
      if(c != 'F' && c != '.' && c != 'S') {
        curDist = j;
        boat = c - '1' + 1;
        break;
      }
    }

    if(curDist != -1) {
      v.push_back({boat, curDist});
    }
  }

  sort(v.begin(), v.end(), [&] (pii a, pii b) {
    return a.Y < b.Y;
  });

  int order[10];
  int st = 1;
  order[v[0].X] = st;
  for(int i = 1; i < v.size(); i++) {
    if(v[i - 1].Y != v[i].Y) st++;
    order[v[i].X] = st;
  }

  for(int i = 1; i <= 9; i++) {
    cout << order[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
