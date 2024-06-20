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

using namespace std;

int N, M;
vector<int> arr;
vector<int> tree[400005];
vector<pair<pii, int>> query;

void input() {
  cin >> N;
  arr.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  cin >> M;
  query.resize(M);
  for(int i = 0; i < M; i++) {
    cin >> query[i].X.X >> query[i].X.Y >> query[i].Y;
  }
}

void update(int bucket, int node, int start, int end, int val) {
  if(node < start || node > end) return;
  tree[bucket].push_back(val);
  if(start == end) return;
  int mid = (start + end) / 2;
  update(bucket * 2, node, start, mid, val);
  update(bucket* 2 + 1, node, mid + 1, end, val);
}

int get(int node, int start, int end, int left, int right, int val) {
  if(start > right || end < left) return 0;
  if(start >= left && end <= right)
    return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
  int mid = (start + end) / 2;
  return get(node * 2, start, mid, left, right, val)
        + get(node * 2 + 1, mid + 1, end, left, right, val);
}

void solve() {
  for(int i = 0; i <= N; i++) {
    update(1, i, 1, N, arr[i]);
  }

  for(int i = 0; i < 400005; i++) {
    sort(tree[i].begin(), tree[i].end());
  }

  int ans = 0;
  for(auto &q : query) {
    int i = ans^q.X.X, j = ans^q.X.Y, k = ans^q.Y;
    ans = get(1, 1, N, i, j, k);
    cout << ans << '\n';
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
