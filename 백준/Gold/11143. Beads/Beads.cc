#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int MAXN = 100000;
int T, B, P, Q;
vector<int> beads(MAXN);
vector<int> segTree(4 * MAXN, 0);

void build(int node, int start, int end) {
  if (start == end) {
    segTree[node] = beads[start];
  } else {
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
  }
}

void update(int node, int start, int end, int idx, int val) {
  if (start == end) {
    beads[idx] += val;
    segTree[node] += val;
  } else {
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid) {
      update(node * 2, start, mid, idx, val);
    } else {
      update(node * 2 + 1, mid + 1, end, idx, val);
    }
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
  }
}

int query(int node, int start, int end, int l, int r) {
  if (r < start || l > end)
    return 0;
  if (l <= start && end <= r)
    return segTree[node];
  int mid = (start + end) / 2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return p1 + p2;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {
    cin >> B >> P >> Q;
    fill(beads.begin(), beads.begin() + B, 0);
    build(1, 0, B - 1);

    char op;
    int i, a, j;
    for (int k = 0; k < P + Q; ++k) {
      cin >> op;
      if (op == 'P') {
        cin >> i >> a;
        update(1, 0, B - 1, i - 1, a);
      } else if (op == 'Q') {
        cin >> i >> j;
        cout << query(1, 0, B - 1, i - 1, j - 1) << '\n';
      }
    }
  }

  return 0;
}