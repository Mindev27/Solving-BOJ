#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int N, root;
ll cnt[200005], dp[200005];
vector<int> tree[200005];

void input() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    int a; cin >> a;
    tree[a].push_back(i);
  }
  root = tree[0][0];
}

void DFS(int cur) {
  cnt[cur] = 1;

  for(int i = 0; i < tree[cur].size(); i++) {
    int child = tree[cur][i];
    DFS(child);
    cnt[cur] += cnt[child];
    dp[cur] -= cnt[child] * cnt[child];
  }
  dp[cur] += cnt[cur] * cnt[cur];
}

void solve() {
  DFS(root);

  ll result1 = 0, result2 = 0;
  ll curIdx = 0;
  for(int i = 1; i <= N; i++) {
    ll x = dp[i] / 2;
    ll y = dp[i] - x;
    x *= i; y *= i;
    
    if(curIdx % 2 == 0) {
      result1 += y;
      result2 += x;
    }
    else{
      result1 += x;
      result2 += y;
    }

    curIdx += dp[i];
  }

  cout << result2 << " " << result1;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}