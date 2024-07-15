#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int SIZE = 200005;
int N, M;
vector<int> adj[SIZE];
bool visited[SIZE];
int p[SIZE];

int find(int x) {
  if(p[x] == x) return x;
  return p[x] = find(p[x]);
}

void Union(int x, int y) {
  x = find(x); y = find(y);
  if(x != y) p[y] = x;
}

void input() {
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }
}

void solve() {
  // init
  memset(visited, false, sizeof(visited));
  for(int i = 1; i <= N; i++) p[i] = i;
  
  // 단방향 지우면서 변호 체크
  for(int i = 1; i <= N; i++) {
    for(int j = 0, sz = adj[i].size(); j < sz;) {
      int x = adj[i][j];

      // 양방향인지 체크
      bool isOneWay = true;
      for(int k = 0; k < adj[x].size(); k++) {
        if(adj[x][k] == i) { isOneWay = false; break; }
      }

      if(isOneWay) {
        visited[x] = true;
        adj[i].erase(remove(adj[i].begin(), adj[i].end(), x), adj[i].end());
        sz--;
      } else j++;
    }
  }

  // 유파로 사이클 찾기
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < adj[i].size(); j++) {
      int x = adj[i][j];
      adj[x].erase(remove(adj[x].begin(), adj[x].end(), i), adj[x].end());
      if(find(x) == find(i)) {
        visited[find(x)] = true;
      }
      else {
        if(visited[find(x)]) Union(x, i);
        else Union(i, x);
      }
    }
  }

  bool flag = true;
  for(int i = 1; i <= N; i++) {
    if(!visited[i] && !visited[find(i)]) {
      flag = false;
      break;
    }
  }

  if(flag) cout << "YES";
  else cout << "NO";
    
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
