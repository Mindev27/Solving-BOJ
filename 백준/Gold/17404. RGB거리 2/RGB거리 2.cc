#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999999;
int n;
int cost[1005][3] = {};

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++){
    int a, b, c;
    cin >> a >> b >> c;

    cost[i][0] = a;
    cost[i][1] = b;
    cost[i][2] = c;
  }
}

void check(int dp[][3]) {
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++){
      cout << dp[i][j] << ' ';
    }
    cout << "\n";
  }
  cout << "\n";
}

int solve() {
  int answer = INF;
  
  for(int i = 0; i < 3; i++){ // R, G, B로 각각 시작할때
    int dp[1005][3] = {};
    
    // 초기 상태 설정
    for(int j = 0; j < 3; j++){
      if(j == i) dp[2][j] = INF;
      else dp[2][j] = cost[1][i] + cost[2][j];
    }

    for(int j = 3; j <= n; j++){ // bottom-up으로 dp 계산
      dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
      dp[j][1] = min(dp[j - 1][2], dp[j - 1][0]) + cost[j][1];
      dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
    }

    //1번과 N번이 다른경우에 대해 정답 업데이트
    for(int j = 0; j < 3; j++)
      if(i != j) answer = min(answer, dp[n][j]);

    // check(dp);
  }

  return answer;
}

int main(void) {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();

  cout << solve();
  
  return 0;
}
