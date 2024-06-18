#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

#define MOD 786433
#define G 1000

using namespace std;

const int INF = 99999999;
int N;
vector<int> prefix[1005];
vector<pii> ans;

void input() {
  cin >> N;
  ans.resize(N + 1);
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    prefix[i].resize(x + 1, 0);
    
    for(int j = 1; j <= x; j++) {
      int v; cin >> v;
      prefix[i][j] = prefix[i][j - 1] + v;
    }
  }
}

void solve() {
  int total = 0;
  for(int tc = 0; tc < N; tc++) {
    int best = -INF;
    for(int i = 1; i < prefix[tc].size(); i++) {
      for(int j = i; j < prefix[tc].size(); j++) {
        int sum = prefix[tc][j] - prefix[tc][i - 1];
        if(sum > best) {
          best = sum;
          ans[tc] = {i, j};
        }
        else if(sum == best) {
          if(ans[tc].Y - ans[tc].X > j - i)
            ans[tc] = {i, j};
        }
      }
    }
    total += best;
  }

  cout << total << '\n';
  for(int i = 0; i < N; i++) {
    cout << ans[i].X << ' ' << ans[i].Y << '\n';
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
