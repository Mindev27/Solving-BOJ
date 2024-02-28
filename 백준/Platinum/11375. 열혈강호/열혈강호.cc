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

const int MAX = 1005;
int N, M;
vector<int> adj[MAX];
int nxt[MAX]; // 이미 점유하고있는 정점
bool done[MAX];

bool dfs(int x) {
  for (int i : adj[x]) {
    if (done[i]) continue; // 처리됐으면 무시
    
    done[i] = true;
    
    if (nxt[i] == 0 || dfs(nxt[i])) {
      nxt[i] = x;
      return true;
    }
  }
  return false;
}

void input() {
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    int num; cin >> num;
    for(int j = 0; j < num; j++) {
      int x; cin >> x;
      adj[i].push_back(x);
    }
  }
}

void solve() {
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    memset(done, false, sizeof(done));
    if (dfs(i)) ans++;
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
