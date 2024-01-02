#include <iostream>

using namespace std;

typedef long long ll;

const int DIV = 1000000007;
ll n;
ll a[2][2] = {{1, 1}, {1, 0}};
ll result[2][2] = {{1, 0}, {0, 1}};

void input() {
  cin >> n;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      cin >> a[i][j];
    }
  }
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
        temp[i][j] %= DIV;
      }
    }
  }

  //x에 복사
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      x[i][j] = temp[i][j];
}

// 이분탐색으로 제곱
void solve() {
  while(n > 0){
    if(n % 2 == 1){
      multMatrix(result, a);
    }
    n /= 2;
    multMatrix(a, a);
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  solve();

  cout << result[1][0];
}