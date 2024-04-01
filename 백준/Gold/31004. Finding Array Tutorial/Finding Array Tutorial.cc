#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
int p[1005], s[1005];

void init() {
  memset(p, 0, sizeof(p));
  memset(p, 0, sizeof(s));
  cin >> N;
}

void solve() {
  for(int i = 1; i <= N; i++) {
    cout << "? 1 " << i << endl;
    cin >> p[i];
  }
  for(int i = 1; i <= N; i++) {
    cout << "? " << i << " " << N << endl;
    cin >> s[i];
  }

  vector<int> ans;
  for(int i = 1; i <= N; i++) {
    if(p[i] == p[i-1] + 1 && s[i] == s[i+1] + 1) {
      ans.push_back(i);
    }
  }

  sort(ans.begin(), ans.end());
  cout << "! " << ans.size() << ' ';
  for(int &i : ans) {
    cout << i << ' ';
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  init();
  solve();

  return 0;
}