#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

const int MAX = 1000005;
struct SegTree {
  vector<ll> tree;

  SegTree() {
    tree.resize(4 * MAX, 0);
  }

  ll query(int node, int start, int end, ll candy) {
    if (candy > tree[node] || candy < 1)
      return 0;

    tree[node] -= 1;
    if (start == end) return start;
    int mid = (start + end) / 2;
    int d = tree[node * 2];
    return query(node * 2, start, mid, candy) +
           query(node * 2 + 1, mid + 1, end, candy - d);
  }

  void update(int node, int left, int right, int index, ll diff) {
    if (left <= index && index <= right) {
      tree[node] += diff;
      if (left != right) {
        int mid = (left + right) / 2;
        update(node * 2, left, mid, index, diff);
        update(node * 2 + 1, mid + 1, right, index, diff);
      }
    }
  }

  ll query(int candy) { return query(1, 1, MAX, candy); }

  void update(ll index, ll diff) { update(1, 1, MAX, index, diff); }
};

int N;

void input() { cin >> N; }

void solve() {
  SegTree st;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      ll b;
      cin >> b;
      cout << st.query(b) << '\n';
    } else if (a == 2) {
      ll b, c;
      cin >> b >> c;
      st.update(b, c);
    }
  }
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