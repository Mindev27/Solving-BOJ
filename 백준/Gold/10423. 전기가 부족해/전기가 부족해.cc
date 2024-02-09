#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, M, K;
vector<pair<int, pii>> edges;
int parent[1005] = {};

int find(int x) {
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
  int x = find(a);
  int y = find(b);
  if(x > y) parent[x] = y;
  else parent[y] = x;
}
void input() {
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++)
    parent[i] = i;

  for(int i = 0; i < K; i++) { // 발전소를 표시
    int x; cin >> x;
    parent[x] = 0;
  }
  for(int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    edges.push_back({c, {a, b}});
  }
}

void solve() {
  int answer = 0;
  
  sort(edges.begin(), edges.end());
  for(int i = 0; i < edges.size(); i++) {
    auto cur = edges[i];
    if(find(cur.Y.X) == find(cur.Y.Y)) continue;
    if(find(cur.Y.X) == 0 && find(cur.Y.Y) == 0) continue;

    uni(cur.Y.X, cur.Y.Y);
    answer += cur.X;
  }

  cout << answer;
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