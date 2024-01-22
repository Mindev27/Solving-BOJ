#include <iostream>
#include <vector>
#include <cstring>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N, E;
int value[20005];
int p[20005];
vector<pii> edge[20005]; // 도착지점, 비용
int dp[20005] = {};

void init() {
  memset(p, 0, sizeof(p));
  memset(dp, -1, sizeof(dp));
  for(int i = 1; i <= N; i++)
    edge[i].clear();
}

void input() {
  cin >> N >> E;
  for(int i = 1; i <= N; i++) {
    cin >> value[i];
  }
  for(int i = 1; i <= E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[a].push_back({b, c});
  }
}


int solve(int cur) {
  if(dp[cur] != -1)
    return dp[cur];

  dp[cur] = value[cur];
  for(int i = 0; i < edge[cur].size(); i++) {
    pii next = edge[cur][i];

    // next로 진행할때 가치가 더 커지면
    int nextVal = solve(next.X) - next.Y + value[cur];
    if(dp[cur] <= nextVal){
      dp[cur] = nextVal;
      p[cur] = next.X; // 경로 저장
    }
  }
  return dp[cur];
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while(T--) {
    init();
    input();
    cout << solve(1) << ' ';

    // 경로를 탐색
    vector<int> path;
    for(int i = 1; i != 0; i = p[i])
      path.push_back(i);

    cout << path.size() << '\n';
    
    for(int i : path)
      cout << i << ' ';
    
    cout << '\n';
  }
  return 0;
}