#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, M, K;
bool infect[1005];
vector<pair<int, pii>> v;

void input() {
  cin >> N >> M >> K;
  memset(infect, false, sizeof(infect));
  for(int i = 0 ; i < K; i++) {
    int a; cin >> a;
    infect[a] = true;
  }

  for(int i = 0; i < M; i++) {
    int t, a, b; cin >> t >> a >> b;
    v.push_back({t, {a, b}});
  }
}

bool go(int x) {
  bool infection[1005];
  memset(infection, false, sizeof(infection));
  infection[x] = true;

  for(auto i : v) {
    if(infection[i.Y.X])
      infection[i.Y.Y] = true;
  }

  for(int i = 1; i <= N; i++) {
    if(infection[i] != infect[i])
      return false;
  }
  return true;
}

void solve() {
  sort(v.begin(), v.end());
  
  for(int i = 1; i <= N; i++) {
    if(infect[i]) {
      bool isTrue = go(i);
      if(isTrue) {
        cout << i;
        return;
      }
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
