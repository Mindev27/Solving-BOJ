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

void input() {
   cin >> N;
  v.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i];
  }
}

void solve() {
  for(int k = 1; k <= N; k++) {
    set<int> avail;
    bool flag = true;
    for(int i = 1; i <= k; i++) {
      avail.insert(i);
    }

    for(int i = 0; i < N - k + 1; i++) {
      if(!avail.count(v[i])) {
        flag = false;
        break;
      }
      avail.erase(v[i]);
      avail.insert(i + k + 1);
    }

    if(flag) { cout << k; return; }
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
