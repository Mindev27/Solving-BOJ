#include <iostream>

using namespace std;

const int INF = 999'999'999;
int N;
int w[20][20];
int dp[20][(1 << 10)];

void input(){
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> w[i][j];
    }
  }
}

int TSP(int cur, int visited){
  if(visited == (1 << N) - 1){ // 모두 방문한 경우
    if(w[cur][0] > 0){
      return w[cur][0]; // 집으로 돌아가는 길이 있는 경우
    }
    return INF; // 불가능한 경우
  }

  // 메모이제이션 있으면 반환
  if(dp[cur][visited] != 0) return dp[cur][visited];

  dp[cur][visited] = INF; // 최댓값으로 초기화 후 탐색

  for(int i = 0; i < N; i++){
    if(w[cur][i] == 0)    // 길이 없으면 탐색 종료
      continue;

    if(visited & (1 << i)) // 이미 방문했으면 탐색 종료
      continue;

    int next = TSP(i, visited | (1 << i)); // 다음 노드로 가는 비용계산
    dp[cur][visited] = min(dp[cur][visited], next + w[cur][i]); // 업데이트
  }

  return dp[cur][visited];
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  cout << TSP(0, 1); // 0번째 도시 방문으로 시작

  return 0;
}