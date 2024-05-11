#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

const int MAX = 305;
int N;
int digCost[MAX];
int adj[MAX][MAX];
int p[MAX]; // 음수면 현재까지 비용 양수면 부모루트

int find(int x) {
  if(p[x] <= 0) return x;
  return p[x] = find(p[x]);
}

bool merge(int x, int y) {
  int a = find(x), b = find(y);
  if(a == b) return false;
  
  int digEach = digCost[a] + digCost[b];
  int connect = min(digCost[a], digCost[b]) + adj[x][y];

  // 각각 파는거보다 하나파고 연결하는게 좋다면
  if(digEach >= connect) {
    if(digCost[a] > digCost[b]) { // y가 루트
      p[b] += p[a] - adj[x][y];
      p[a] = b;
    }
    else { // x가 루트
      p[a] += p[b] - adj[x][y];
      p[b] = a;
    }
    return true; // 연결됨
  }
  return false;
}
void input() {
  cin >> N;
  for(int i = 1; i <= N; i++)
    cin >> digCost[i];
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> adj[i][j];
    }
  }
  for(int i = 1; i <= N; i++)
    p[i] = 0;
}

void solve() {
  vector<pair<int, pii>> edges; // 가중치, from, to

  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      edges.push_back({adj[i][j], {i, j}});
    }
  }

  // 크루스칼
  sort(edges.begin(), edges.end());
  int cnt = 0;
  for(auto &e : edges) {
    if(merge(e.Y.X, e.Y.Y))
      cnt++;
    
    if(cnt == N - 1) break;
  }

  int answer = 0;
  for(int i = 1; i <= N; i++) {
    if(p[i] <= 0) answer += digCost[i];
    if(p[i] < 0) answer += - p[i];
  }
  cout << answer;
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