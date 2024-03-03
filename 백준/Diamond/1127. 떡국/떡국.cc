#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 55;

int N, K, S = 53, T = 54;
bool assist[MAX][MAX];           // 협력여부
int c[MAX][MAX], f[MAX][MAX];    // 용량 플로우
bool gd[MAX][MAX], of[MAX][MAX]; // 경비와 경비업체 여부
vector<int> adj[MAX];            // 플로우 그래프의 연결

void initNetwork() {
  memset(c, false, sizeof(c));
  memset(f, false, sizeof(f));
  for(int i = 0; i < N; i++)
    adj[i].clear();
}

// type -> 0: 유량X, 1: 단방향, 2: 양방향
void makeEdge(int from, int to, int type) {
  adj[from].push_back(to);
  adj[to].push_back(from);
  if(type >= 1) c[from][to] += 1;
  if(type >= 2) c[to][from] += 1;
}

// 소스 -> 가드가 있는 국가, 경비업체가있는 국가 -> 싱크
// 각 경비업체마다 네트워크 연결 후 최소 컷 구하기
void makeNetwork(int cur) {
  int from, to;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(assist[i][j]) { // 연결되어있는 경우 확인
        if(gd[i][cur]) from = S; else if(!of[i][cur]) from = T; else from = i;
        if(gd[j][cur]) to = S; else if(!of[j][cur]) to = T;  else to = j;

        if(from != S && from != T && to != S && to != T) makeEdge(from, to, 2);
        else if(from == S && to != S) makeEdge(from, to, 1);
        else if(from == T && to != T) makeEdge(to, from, 1);
        else if(to == S && from != S) makeEdge(to, from, 1);
        else if(to == T && from != T) makeEdge(from, to, 1);
      }
    }
  }
}

// Edmond-Karp 알고리즘
int EdmondKarp(){
  int totalFlow = 0;
  while(true){
    vector<int> parent(MAX, -1);
    queue<int> q;
    
    parent[S] = S;
    q.push(S);
    
    while(!q.empty() && parent[T] == -1){
      int cur = q.front(); q.pop();
      for(int next : adj[cur]) {
        if(c[cur][next] - f[cur][next] > 0 && parent[next] == -1){
          q.push(next);
          parent[next] = cur;
        }
      }
    }
    
    if(parent[T] == -1) break;
    
    int flow = INF;
    for(int p = T; p != S; p = parent[p])
      flow = min(flow, c[parent[p]][p] - f[parent[p]][p]);
    for(int p = T; p != S; p = parent[p]){
      f[parent[p]][p] += flow;
      f[p][parent[p]] -= flow;
    }
    totalFlow += flow;
  }
  return totalFlow;
}

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    string temp; cin >> temp;
    for(int j = 0; j < N; j++) {
      if(temp[j] == '1') {
        assist[i][j] = true;
      }
    }
  }
  cin >> K;
  for(int i = 0; i < N; i++) {
    int num; cin >> num;
    for(int j = 0; j < num; j++) {
      int x; cin >> x;
      gd[i][x] = true;
    }
  }
  for(int i = 0; i < N; i++) {
    int num; cin >> num;
    for(int j = 0; j < num; j++) {
      int x; cin >> x;
      of[i][x] = true;
    }
  }
}

void solve() {
  int result = 0;
  for(int i = 0; i < K; i++) {
    initNetwork();
    makeNetwork(i);
    result += EdmondKarp();
  }
  
  cout << result;
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