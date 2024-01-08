#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

int N, M;
vector<pair<int, int>> player;
vector<int> team;

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    player.push_back({a, b});
  }

  for(int i = 0; i < M; i++) {
    int a; cin >> a;
    team.push_back(a);
  }
}

void solve() {
  sort(player.begin(), player.end());
  sort(team.begin(), team.end());
  reverse(player.begin(), player.end());
  reverse(team.begin(), team.end());

  priority_queue<pair<int, int>> pq;
  ll result = 0;
  int index = 1;
  
  pq.push({player[0].second, player[0].first});
  for(int i = 0; i < M; i++){
    result += pq.top().first;
    pq.pop();
    for(int j = 0; j < team[i]; j++){
      pq.push({player[index + j].second, player[index + j].first});
    }
    index += team[i];
  }

  cout << result;
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
