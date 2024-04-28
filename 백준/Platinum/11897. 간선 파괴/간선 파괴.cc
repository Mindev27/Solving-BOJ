#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const short MAX_V = 705;
int V, E, Q;
vector<pii> edges, query, st, ed;

struct UnionFind {
short p[MAX_V];

  UnionFind() {
    for(int i = 0; i < MAX_V; ++i)
      p[i] = -1;
  }

  short find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return;
  }
};

UnionFind cur, Qunion[50005]; 

void input() {
  cin >> V >> E;
  edges.resize(E);
  for(int i = 0; i < E; i++) {
    cin >> edges[i].X >> edges[i].Y;
    edges[i].X--;
    edges[i].Y--;
  }
  cin >> Q;
  query.resize(Q);
  for(int i = 0; i < Q; i++) {
    cin >> query[i].X >> query[i].Y;
    query[i].X--;
    st.push_back({query[i].X, i});
    ed.push_back({query[i].Y, i});
  }
}

void solve() {
  sort(st.begin(), st.end());
  int start = 0;
  for(auto i : st) {
    int index = i.Y;
    for(int j = start; j < query[index].X; j++) {
      cur.Union(edges[j].X, edges[j].Y);
    }
    start = query[index].X;
    copy(cur.p, cur.p+V, Qunion[index].p);
  }

  sort(ed.begin(), ed.end());
  reverse(ed.begin(), ed.end());
  cur = UnionFind();
  start = E;
  for(auto i : ed) {
    int index = i.Y;
    for(int j = start; j > query[index].Y; j--) {
      cur.Union(edges[j - 1].X, edges[j - 1].Y);
    }
    start = query[index].Y;
    for(int j = 0; j < V; j++){
      Qunion[index].Union(cur.find(j), j);
    }
  }

  for(int i = 0; i < Q; ++i) {
    int answer = 0;
    for(int j = 0; j < V; j++)
      if(Qunion[i].p[j] < 0) answer++;
    cout << answer << '\n';
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
