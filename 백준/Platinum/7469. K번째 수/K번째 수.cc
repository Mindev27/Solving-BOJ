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


int N, Q;
vector<int> arr;
vector<int> tree[400005];
vector<pair<pii, int>> query;

void input() {
  cin >> N >> Q;
  arr.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  query.resize(Q);
  for(int i = 0; i < Q; i++) {
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
    return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
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

  for(auto &q : query) {
    int l = -1e9, r = 1e9;
    int mid = ( l + r) / 2;
    while(l <= r){
      mid = (l + r) / 2;
      if(get(1, 1, N, q.X.X, q.X.Y, mid) < q.Y) l = mid + 1;
      else r = mid - 1;
    }
    cout << l << "\n";
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
