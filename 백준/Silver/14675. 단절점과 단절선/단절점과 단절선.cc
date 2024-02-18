#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, Q;
vector<int> adj[100005];
vector<pii> query;

void input() {
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> Q;
  for(int i = 0 ; i < Q; i++) {
    int x, y; cin >> x >> y;
    query.push_back({x, y});
  }
}

// 연결된 노드가 2개이상이면 단절점
bool isCutNode(int node) {
  if(adj[node].size() < 2)
    return false;
  else
    return true;
}

void solve() {
  for(pii &q : query) { // 각 쿼리에 대해 처리
    if(q.X == 1) { // 단절점
      if(isCutNode(q.Y)) cout << "yes\n";
      else cout << "no\n";
    }
    else { // 트리는 항상 단절선이다
      cout << "yes\n";
    }
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
