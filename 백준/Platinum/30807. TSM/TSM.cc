#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct Edge{
  int u, v;
  ll lo, hi;
};

ll n, m, k;
ll gap = 0;                            // 전체 그래프 간선의 범위
vector<Edge> edges;                    // 간선 정보 저장
int parent[100005] = {};

ll getParent(ll x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(ll a, ll b) {
  ll x = getParent(a);
  ll y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

bool findParent(ll a, ll b) {
  ll x = getParent(a);
  ll y = getParent(b);
  if (x == y) return true;
  else return false;
}

void input() {
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++){
    Edge x;
    cin >> x.u >> x.v >> x.lo >> x.hi;
    edges.push_back(x);
    gap += x.hi - x.lo;
  }
}

void initUnion() {
  for(int i = 1; i <= n; i++)
    parent[i] = i;
}

ll kruscal(ll len) {
  vector<pair<ll, pair<int, int>>> mst;  // (간선길이, 시작정점, 끝정점)

  // len에서 간선값을 빼가며 개수를 맞추기
  for(int i = 0; i < m; i++) {
    ll cost = min(len, edges[i].hi - edges[i].lo);
    mst.push_back({cost + edges[i].lo, {edges[i].u, edges[i].v}});
    len -= cost;
  }

  sort(mst.begin(), mst.end()); // 간선이 가장 짧은 순으로 정렬
  initUnion();

  ll sum = 0;         // 간선 가중치의 합
  int selectEdge = 0; // 선택된 간선의 수 (N-1이면 MST 완성)

  for(int i = 0; i < mst.size(); i++){
    if(selectEdge == n - 1) break;

    ll cost = mst[i].first;
    int s = mst[i].second.first;
    int e = mst[i].second.second;

    if(findParent(s, e)){          // s와 e가 하나로 묶여있다면
      continue;
    }
    else{                          // 아니라면 하나의 유니온으로 묶기
      unionParent(s, e);
      selectEdge++;
      sum += cost;
    }
  }

  return sum;
}

// 이분탐색을 진행하며, 가능한 간선의 값 생각하기
// 간선값을 하나씩 1증가시키면 MST비용은 단조증가한다
void solve() {
  ll left = -1, right = gap;
  while(left + 1 < right) {
    ll mid = (left + right) / 2;
    if(kruscal(mid) >= k)
      right = mid;
    else
      left = mid;
  }

  if(kruscal(right) == k) {
    cout << "YES\n";
    for(int i = 0; i < m; i++) {
      ll cost = min(right, edges[i].hi - edges[i].lo);
      cout << min(right, cost) + edges[i].lo << '\n';
      right -= cost;
    }
  }
  else {
    cout << "NO";
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}