#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int N, Q;
vector<pair<int, int>> query;
map<int, bool> m;

void input() {
  cin >> N >> Q;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    if(a == 1) m[i] = true;
  }
  for(int i = 0; i < Q; i++) {
    int a, b;
    cin >> a;
    if(a == 3)
      query.push_back({3, 0});
    else{
      cin >> b;
      query.push_back({a, b});
    }
  }
}

void solve() {
  int player = 0;
  for(int i = 0; i < query.size(); i++) {
    int command = query[i].first;
    if(command == 1) {
      int cur = query[i].second;
      if(m[cur - 1]) m.erase(cur - 1);
      else m[cur - 1] = true;
    }
    else if(command == 2) {
      int cur = query[i].second;
      player = (player + cur) % N;
    }
    else {
      if(m.size() == 0)
        cout << -1 << '\n';
      else{
        auto next = m.lower_bound(player);
        if(next == m.end())
          cout << (*m.begin()).first + N - player << '\n';
        else
          cout << (*next).first - player << '\n';
      }
    }
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}