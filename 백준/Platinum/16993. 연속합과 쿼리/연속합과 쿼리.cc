#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll INF = 1e18;

struct Node {
  ll rMax, lMax, max;
};

int N, M;
Node tree[400000];
ll a[100005], prefix[100005];
vector<pii> query;

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    prefix[i] = prefix[i - 1] + a[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    query.push_back({a, b});
  }
}

// 세그먼트 트리를 구축하는 함수
void makeSegTree(int cur, int l, int r) {
  if (l == r) {
    tree[cur] = {a[r], a[r], a[r]};
    return;
  }

  int mid = (l + r) / 2;
  makeSegTree(cur * 2, l, mid);
  makeSegTree(cur * 2 + 1, mid + 1, r);

  Node left = tree[cur * 2], right = tree[cur * 2 + 1];

  tree[cur].lMax = max(left.lMax, prefix[mid] - prefix[l - 1] + right.lMax);
  tree[cur].rMax = max(right.rMax, prefix[r] - prefix[mid] + left.rMax);
  tree[cur].max = max({left.max, right.max, left.rMax + right.lMax});
}

// 주어진 범위에 대해 쿼리를 처리하는 함수
Node get(int cur, int l, int r, int s, int e) {
  if (r < s || e < l)
    return {-INF, -INF, -INF}; // 범위 밖일 경우
  if (s <= l && r <= e)
    return tree[cur]; // 범위 안일 경우

  int mid = (l + r) / 2;
  Node left = get(cur * 2, l, mid, s, e);
  Node right = get(cur * 2 + 1, mid + 1, r, s, e);
  Node ret;

  ret.lMax = max(left.lMax, prefix[mid] - prefix[l - 1] + right.lMax);
  ret.rMax = max(right.rMax, prefix[r] - prefix[mid] + left.rMax);
  ret.max = max({left.max, right.max, left.rMax + right.lMax});

  return ret;
}

void solve() {
  makeSegTree(1, 1, N);

  for (auto q : query) {
    cout << get(1, 1, N, q.X, q.Y).max << '\n';
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
