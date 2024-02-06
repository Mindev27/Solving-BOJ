#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MOD = 1'000'000'007;
int N, M;
int parent[1005];
vector<pair<pii, int>> query;

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    query.push_back({{a, b}, c});
  }
}

void solve() {
  for(int i = 1; i <= N; i++)
    parent[i] = i;

  // 쿼리에 대해서 하나의 유니온으로 묶기
  for(int i = 0 ; i < M; i++) {
    int L = query[i].X.X;
    int R = query[i].X.Y;
    int K = query[i].Y;

    for(int j = L; j <= R - K; j++) {
      unionParent(j, j + K);
    }
  }

  ll ans = 1;
  for(int i = 1; i <= N; i++) {
    if(getParent(i) == i)
      ans = (ans * 2) % MOD;
  }

  cout << ans;
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
