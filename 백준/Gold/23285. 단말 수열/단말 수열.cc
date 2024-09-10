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
int cnt[1005];

void solve() {
  cin >> N;
  v.resize(N + 1);
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < N; i++) {
     cin >> v[i];
    cnt[v[i]]++;
  }

  priority_queue<int, vector<int>, greater<int>> pq; // 리프노드들
  for(int i = 1; i <= N; i++) {
    if(cnt[i] == 0) pq.push(i);
  }


  vector<pii> edges;
  int idx = 0;
  while(idx < N - 2) {
    int cur = pq.top();
    pq.pop();

    edges.push_back({min(cur, v[idx]), max(cur, v[idx])});
    cnt[v[idx]]--;
    if(cnt[v[idx]] == 0) pq.push(v[idx]);
    idx++;
  }

  int a = pq.top(); pq.pop();
  int b = pq.top(); pq.pop();

  edges.push_back({min(a, b), max(a, b)});

  sort(edges.begin(), edges.end());

  for(pii i : edges) {
    cout << i.X << " " << i.Y << "\n";
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc = 1;
  // cin >> Tc;
  while(Tc--) {
    solve();
  }

  return 0;
}

