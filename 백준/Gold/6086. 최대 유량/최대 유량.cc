#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_V = 52;
const int INF = 1000000000;
int n;
vector<int> edge[MAX_V];  // 인접 리스트
int c[MAX_V][MAX_V] = {}; // 간선의 용량
int f[MAX_V][MAX_V] = {}; // 현재 흐르는 유량

// 문자를 숫자로 치환해줌
int CtoI(char c){
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++){
    char a, b; int w;
    cin >> a >> b >> w;
    a = CtoI(a); b = CtoI(b);
    c[a][b] += w; c[b][a] += w;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
}

int solve() {
  int total = 0, start = CtoI('A'), end = CtoI('Z');

  // 증가 경로를 BFS로 탐색
  while(true){
    int prev[MAX_V]; // 왔던 이전의 정점 저장
    fill(prev, prev + MAX_V, -1); // 초기화
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty() && prev[end] == -1){
      int now = q.front();
      q.pop();
      
      for(int i = 0; i < edge[now].size(); i++){
        int next = edge[now][i];
        // 유량이 남아있고, 방문하지 않았으면
        if(c[now][next] - f[now][next] > 0 && prev[next] == -1){
          q.push(next);
          prev[next] = now; // 이전에 방문했다는 정보를 저장
          if(next == end)   // 끝까지 탐색했다면 끝
            break;
        }
      }
    }
    
    // 끝까지 가는 경로가 없으면 종료
    if(prev[end] == -1)
      break;

    int flow = INF;
    // 경로를 보면서 가장 허용치가 낮은거 찾기
    for(int i = end; i != start; i = prev[i]){
      // i번째로 흘려보낼때 남은 용량과 비교하여 더 작은값 저장
      flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
    }

    // 역방향 간선으로 흘려주기
    for(int i = end; i != start; i = prev[i]){
      f[prev[i]][i] += flow;
      f[i][prev[i]] += flow;
    }

    // 값에 더하기  
    total += flow;
  }

  return total;
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  cout << solve();
}

