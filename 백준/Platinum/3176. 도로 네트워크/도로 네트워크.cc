#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 100005;
int N, M, H;
vector<pii> adj[SIZE];
vector<pii> query;
bool visited[SIZE];
int minDist[SIZE][20];
int maxDist[SIZE][20];
int dep[SIZE];
int p[SIZE][20];

void input() {
  cin >> N;
  for(int i = 0 ; i < N - 1; i++) {
    int x, y, z; cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }

  cin >> M;
  for(int i = 0 ; i < M; i++) {
    int x, y; cin >> x >> y;
    query.push_back({x, y});
  }
}

void labeling(int cur, int depth) {
  visited[cur] = true;
  dep[cur] = depth;

  for(auto k : adj[cur]) {
    int nNode = k.X;
    int nWeight = k.Y;

    if(!visited[nNode]) {
      p[nNode][0] = cur;
      minDist[nNode][0] = nWeight;
      maxDist[nNode][0] = nWeight;
      labeling(nNode, depth + 1);
    }
  }
}

void findAnswer(int a, int b) {
  pii res = {INF, 0};
  if(dep[a] != dep[b]) {
    if(dep[a] > dep[b]) swap(a, b);

    // 높이 맞추기
    for(int i = 19; i >= 0; i--) {
      int gap = 1 << i;
      if(dep[b] - dep[a] >= gap) {
        res.X = min(res.X, minDist[b][i]);
        res.Y = max(res.Y, maxDist[b][i]);
        b = p[b][i];
      }
    }
  }

  if(a != b) {
    for(int i = 19; i >= 0; i--) {
      if(p[a][i] != p[b][i]) {
        res.X = min(res.X, min(minDist[a][i], minDist[b][i]));
        res.Y = max(res.Y, max(maxDist[a][i], maxDist[b][i]));
        a = p[a][i];
        b = p[b][i];
      }
    }
    res.X = min(res.X, min(minDist[a][0], minDist[b][0]));
    res.Y = max(res.Y, max(maxDist[a][0], maxDist[b][0]));
  }

  cout << res.X << ' ' << res.Y << '\n';
}

void solve() {
  labeling(1, 0);

  // 트리의 최대높이 구하기
  int i = N; H = 0;
  while(i > 1) {
    i = i >> 1;
    H++;
  }

  // 거리를 계산
  for(int i = 1; i < 20; i++) {
    for(int j = 1; j <= N; j++) {
      int preP = p[j][i - 1];
      p[j][i] = p[preP][i - 1];

      if(p[preP][i - 1] == 0) continue;

      int preMin = minDist[preP][i - 1];
      int preMax = maxDist[preP][i - 1];
      int curMin = minDist[j][i - 1];
      int curMax = maxDist[j][i - 1];

      minDist[j][i] = min(preMin, curMin);
      maxDist[j][i] = max(preMax, curMax);
    }
  }

  for(auto i : query) {
    findAnswer(i.X, i.Y);
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