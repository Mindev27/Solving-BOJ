#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

ll N, M, idx;
vector<pii> v;
vector<int> strong;

void solve() {
  cin >> N >> M;
  v.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i].X;
    v[i].Y = i + 1;
  }
  sort(v.begin(), v.end());

  for(int i = N - 1; i >= 0; i--) {
    strong.push_back(v[i].Y);
    if(i - 1 >= 0 && v[i].X - v[i - 1].X > M) {
      idx = i;
      break;
    }
  }

  if(N == strong.size()) {
    cout << "YES\n";
    for(int i = N - 1; i >= 0; i--) {
      cout << strong[i] << " ";
    }
    return;
  }

  if(strong.size() < 4) {
    cout << "NO\n"; return;
  }

  // 큰거 2마리 넣고 -> 작은애들 전부 넣고 -> 큰애들 전부 넣기
  cout << "YES\n";
  cout << strong[0] << ' ' << strong[1] << ' ';
  for(int i = 0; i <= idx - 1; i++) {
    cout << v[i].Y << ' ';
  }
  for(int i = 2; i < strong.size(); i++) {
    cout << strong[i] << ' ';
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
