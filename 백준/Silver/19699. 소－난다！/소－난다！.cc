#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
vector<int> v;
bool visited[10];
bool isPrime[10000];
bool isFind = false;
bool ans[10000];

void getPrime() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;

  for (int p = 2; p * p <= 10000; p++) {
    if (isPrime[p]) {
      for (int i = p * p; i <= 10000; i += p) {
        isPrime[i] = false;
      }
    }
  }
}

void backTracking(int cnt, int sum, int start) {
  if (cnt == M) {
    if (isPrime[sum]) {
      ans[sum] = true;
      isFind = true;
    }
    return;
  }

  for (int i = start; i < N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    backTracking(cnt + 1, sum + v[i], i + 1);
    visited[i] = false;
    backTracking(cnt, sum, i + 1);
  }
}

void solve() {
  cin >> N >> M;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  getPrime();
  memset(visited, false, sizeof(visited));
  memset(ans, false, sizeof(ans));
  backTracking(0, 0, 0);

  if(!isFind) cout << -1;
  else {
    for(int i = 0; i < 10000; i++) {
      if(ans[i]) cout << i << ' ';
    }
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
