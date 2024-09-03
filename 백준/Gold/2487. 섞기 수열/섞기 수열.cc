#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N;
vector<int> v;
bool visited[20005];

int DFS(int x) {
  if(visited[x]) return 0;
  
  visited[x] = true;
  int next = v[x];
  return 1 + DFS(next);
}

void solve() {
  cin >> N;
  v.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    v[x] = i;
  }

  // 각 사이클의 크기 계산
  vector<ll> sz;
  memset(visited, false, sizeof(visited));
  for(int i = 1; i <= N; i++) {
    if(!visited[i]) {
      sz.push_back(DFS(i));
    }
  }

  // 각 사이클의 LCM이 답
  while(sz.size() > 1) {
    ll a = sz.back();
    sz.pop_back();
    ll b = sz.back();
    sz.pop_back();

    sz.push_back(1LL * a * b / __gcd(a, b));
  }

  cout << sz[0];
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
