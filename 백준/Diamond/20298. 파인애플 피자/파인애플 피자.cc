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

const int MAX = 200005;

struct SegTree {
  int n;
  vector<int> tree;

  void init(int x) {
    n = x;
  }

  void clear() {
    for(int i = 1; i < n * 2; i++) {
      tree[i] = 0;
    }
  }

  void update(int idx, int v) {
    idx += n;
    tree[idx] += v;
    idx >>= 1;
    while (idx > 0) {
      tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
      idx >>= 1;
    }
  }

  int sum(int l, int r) {
    int res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += tree[l++];
      if (r & 1) res += tree[--r];
    }
    return res;
  }

};

int N, K, compP, compH;
vector<int> p, h;
vector<pii> cnt; // 자기와 비교하여 작고 큰 개수
int fail[MAX];
SegTree st;

bool cmp(pii cur, int v, int sz) {
  if(cur.X != st.sum(0, v - 1)) return false;
  if(cur.Y != st.sum(v + 1, sz)) return false;
  return true;
}

int KMP() {
  st.init(compP);
  st.clear();
  vector<int> result;
  int n = p.size();
  int m = h.size();
  for(int i = 0, j = 0; i < n; i++) {
    while(j > 0 && !cmp(cnt[j], p[i], compP - 1)) {
      for(int k = i - j; k < i - fail[j - 1]; k++)
        st.update(p[k], -1);
      j = fail[j - 1];
    }
    if(cmp(cnt[j], p[i], compP - 1)) {
      st.update(p[i], 1);
      j++;
    }
    if(j == m) {
      result.push_back(i - m + 1);
      for(int k = i - j + 1; k < i - fail[j - 1] + 1; k++)
        st.update(p[k], -1);
      j = fail[j - 1];
    }
  }

  return (int)result.size();
}

int compress(vector<int> *a) {
  auto mp = *a;
  sort(mp.begin(), mp.end());
  mp.erase(unique(mp.begin(), mp.end()), mp.end());
  for (int &i : *a)
    i = lower_bound(mp.begin(), mp.end(), i) - mp.begin();

  return (int)mp.size();
}

void input() {
  cin >> N >> K;
  p.resize(N), h.resize(K);
  for (int i = 0; i < N; i++)
    cin >> p[i];
  for (int i = 0; i < K; i++)
    cin >> h[i];
}

void solve() {
  compP = compress(&p);
  compH = compress(&h);

  for (int i = 0; i < K - 1; i++)
    p.push_back(p[i]);

  st.init(compH);
  st.tree.resize(MAX);
  int m = h.size();
  for(int i = 0; i < m; i++) {
    cnt.push_back({st.sum(0, h[i] - 1), st.sum(h[i] + 1, compH - 1)});
    st.update(h[i], 1);
  }

  st.clear();
  for(int i = 1, j = 0; i < m; i++) {
    while(j > 0 && !cmp(cnt[j], h[i], compH - 1)) {
      for(int k = i - j; k < i - fail[j - 1]; k++){
        st.update(h[k], -1);
      }
      j = fail[j - 1];
    }
    if(cmp(cnt[j], h[i], compH)) {
      st.update(h[i], 1);
      fail[i] = ++j;
    }
  }

  cout << KMP();
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