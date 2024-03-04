#include <algorithm>
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

const int MOD = 1'000'000'007;
ll N, M;
ll a[2][2] = {{1, 1}, {1, 0}};
ll result[2][2] = {{1, 0}, {0, 1}};

void input() {
  cin >> N >> M;
}

ll GCD(ll a, ll b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}

// x행렬에 y행렬을 곱하는 함수
void multMatrix(ll x[2][2], ll y[2][2]){
  ll temp[2][2] = {};

  // 곱 행렬 계산
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      temp[i][j] = 0;

      for(int k = 0; k < 2; k++){
        temp[i][j] += x[i][k] * y[k][j];
        temp[i][j] %= MOD;
      }
    }
  }

  //x에 복사
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      x[i][j] = temp[i][j];
}

void solve() {
  // init
  a[0][0] = 1; a[0][1] = 1;
  a[1][0] = 1; a[1][1] = 0;
  result[0][0] = 1; result[0][1] = 0;
  result[1][0] = 0; result[1][1] = 1;
  
  int n = GCD(N, M);

  while(n > 0){
    if(n % 2 == 1){
      multMatrix(result, a);
    }
    n /= 2;
    multMatrix(a, a);
  }

  cout << result[1][0] << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int Tc; cin >> Tc;
  while(Tc--) {
    input();
    solve();
  }

  return 0;
}
