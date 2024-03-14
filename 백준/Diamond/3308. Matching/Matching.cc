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
  int n;
  int tree[MAX * 2];

  void clear() {
    for(int i = 0; i < MAX * 2; i++) {
      tree[i] = 0;
    }
  }

  void update(int idx, int v) {
    for (tree[idx += n] += v; idx > 1; idx >>= 1) {
      tree[idx >> 1] = tree[idx] + tree[idx ^ 1];
    }
  }

  int sum(int l, int r) {
    int result = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) result += tree[l++];
      if (r & 1) result += tree[--r];
    }
    return result;
  }
};

int N, M;
vector<int> p, h;
vector<pii> cnt; // 자기와 비교하여 작고 큰 개수
int fail[MAX];
SegTree st;

bool cmp(pii cur, int v) {
  if(cur.X != st.sum(0, v)) return false;
  if(cur.Y != st.sum(v + 1, MAX)) return false;
  return true;
}

vector<int> KMP() {
  st.clear();
  vector<int> result;
  int n = p.size();
  int m = h.size();
  for(int i = 0, j = 0; i < n; i++) {
    while(j > 0 && !cmp(cnt[j], p[i])) {
      for(int k = i - j; k < i - fail[j - 1]; k++)
        st.update(p[k], -1);
      j = fail[j - 1];
    }
    if(cmp(cnt[j], p[i])) {
      if(j == m - 1) {
        result.push_back(i - m + 2);
        for(int k = i - j; k < i - fail[j] + 1; k++)
          st.update(p[k], -1);
        st.update(p[i], 1);
        j = fail[j];
      }
      else {
        st.update(p[i], 1);
        j++;
      }
    }
  }

  return result;
}

void compress(vector<int> *a) {
  auto mp = *a;
  sort(mp.begin(), mp.end());
  for (int &i : *a)
    i = lower_bound(mp.begin(), mp.end(), i) - mp.begin() + 1;
}

void input() {
  cin >> N >> M;
  p.resize(M), h.resize(N);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    h[x - 1] = i + 1;
  }
  for (int i = 0; i < M; i++)
    cin >> p[i];
}

void solve() {
  compress(&h);
  compress(&p);

  st.n = MAX;
  st.clear();
  for(int i = 0; i < N; i++) {
    cnt.push_back({st.sum(0, h[i]), st.sum(h[i] + 1, MAX)});
    st.update(h[i], 1);
  }

  memset(fail, 0, sizeof(fail));
  st.clear();
  for(int i = 1, j = 0; i < N; i++) {
    while(j > 0 && !cmp(cnt[j], h[i])) {
      for(int k = i - j; k < i - fail[j - 1]; k++){
        st.update(h[k], -1);
      }
      j = fail[j - 1];
    }
    if(cmp(cnt[j], h[i])) {
      st.update(h[i], 1);
      fail[i] = ++j;
    }
  }

  vector<int> ans = KMP();
  if(ans.empty()) { cout << 0; return; }
  cout << ans.size() << '\n';
  for(int &i : ans)
    cout << i << ' ';
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