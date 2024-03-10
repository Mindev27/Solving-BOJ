#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int MAX = 1'000'005;
int N, result = 0, fail[MAX];
string T, P;

void input() {
  cin >> N;
  T = "";
  for(int i = 0 ; i < N; i++) {
    char x; cin >> x;
    T += x;
  }

  P = "";
  for(int i = 0 ; i < N; i++) {
    char x; cin >> x;
    P += x;
  }
}

int GCD(int a, int b) {
  if(b == 0) return a;
  return GCD(b, a % b);
}

void solve() {
  // TT에서 P가 두번 등장하기 때문에 먼저 빼주고 시작
  if(T == P) result = -1; 
  T += T;
  
  // 실패 함수
  int m = P.size();
  for(int i = 1, j = 0; i < m; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }

  // KMP 알고리즘
  for(int i = 0, j = 0; i < T.size(); i++) {
    while(j > 0 && T[i] != P[j]) j = fail[j - 1];
    if(T[i] == P[j]) {
      if(j == m - 1) {
        result++;
        j = fail[j];
      }
      else j++;
    }
  }

  int gcd = GCD(N, result);

  cout << result / gcd << '/' << N / gcd;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}