#include <iostream>
#include <cstring>

#define ll long long

using namespace std;

ll N, R, G, B, result = 0;
ll f[60] = {};
ll dp[15][60][60][60] = {}; // 레벨, r, g, b 개수일때 경우의 수

// 팩토리얼을 계산하는 함수
ll factorial(ll n) {
  if(n == 0 || n == 1) return 1;
  if(f[n] != 0) return f[n];
  return f[n] = n * factorial(n - 1);
}

// 조합의 개수를 반환하는 함수
ll makeCom(ll level, ll r, ll g, ll b) {
  ll result = factorial(level);
  result /= factorial(r);
  result /= factorial(g);
  result /= factorial(b);
  return result;
}


ll solve(int level, int r, int g, int b){
  if(level == N + 1)
    return 1;

  if(dp[level][r][g][b] != -1)
    return dp[level][r][g][b];
  
  ll temp = 0;

  // 한 층에 1개의 색만 사용할 때
  if(level <= R - r) temp += solve(level + 1, r + level, g, b);
  if(level <= G - g) temp += solve(level + 1, r, g + level, b);
  if(level <= B - b) temp += solve(level + 1, r, g, b + level);
  
  // 한 층에 두개의 색을 사용할 때(level이 짝수인 경우만 가능)
  if(level % 2 == 0){
    if(level / 2 <= R - r && level / 2 <= G - g){
      temp += makeCom(level, level / 2, level / 2, 0)
        * solve(level + 1, r + level / 2, g + level / 2, b);
    }
      
    if(level / 2 <= G - g && level / 2 <= B - b){
        temp += makeCom(level, 0, level / 2, level / 2)
          * solve(level + 1, r, g + level / 2, b + level / 2);
    }
    if(level / 2 <= B - b && level / 2 <= R - r){
        temp += makeCom(level, level / 2, 0, level / 2)
          * solve(level + 1, r + level / 2, g, b + level / 2);
    }
  }

  // 한 층에 세개의 색을 사용할떄(level이 3의 배수인경우 가능)
  if(level % 3 == 0){
    if(level / 3 <= R - r && level / 3 <= G - g && level / 3 <= B - b)
      temp += makeCom(level, level / 3, level / 3, level / 3)
        * solve(level + 1, r + level / 3, g + level / 3, b + level / 3);
  }

  return dp[level][r][g][b] = temp;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> R >> G >> B;
  memset(dp, -1, sizeof(dp));
  cout << solve(1, 0, 0, 0);
  
  return 0;
}
