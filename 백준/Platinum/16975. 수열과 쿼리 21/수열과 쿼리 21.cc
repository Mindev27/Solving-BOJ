#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int n, m, k;
vector<ll> arr, tree, lazy;

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

void updateRange(int node, int start, int end, int l, int r, ll val) {
  if (lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end || start > r || end < l)
    return;
  if (start >= l && end <= r) {
    tree[node] += (end - start + 1) * val;
    if (start != end) {
      lazy[2 * node] += val;
      lazy[2 * node + 1] += val;
    }
    return;
  }
  int mid = (start + end) / 2;
  updateRange(2 * node, start, mid, l, r, val);
  updateRange(2 * node + 1, mid + 1, end, l, r, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll queryRange(int node, int start, int end, int idx) {
  if (lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start == end) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  if (idx <= mid) {
    return queryRange(2 * node, start, mid, idx);
  } else {
    return queryRange(2 * node + 1, mid + 1, end, idx);
  }
}

void solve() {
  cin >> n;
  arr.resize(n + 1);
  tree.resize(4 * n);
  lazy.resize(4 * n);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  build(1, 1, n);

  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    ll d;
    cin >> a >> b;
    if (a == 1) {
      cin >> c >> d;
      updateRange(1, 1, n, b, c, d);
    } else if (a == 2) {
      cout << queryRange(1, 1, n, b) << "\n";
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
