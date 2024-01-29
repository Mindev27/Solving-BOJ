#include <algorithm>
#include <iostream>
#include <cstring>

#define ll long long

using namespace std;

int N, K, len, answer = 0;
string p[10];
bool check[10] = {};
int fail[200];

void input() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> p[i];
    len += p[i].length();
  }
  cin >> K;
}

int kmp(string P) {
  int result = 0;
  memset(fail, 0, sizeof(fail));
  
  // 희소배열 만들기
  int m = P.size();
  for(int i = 1, j = 0; i < m; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }

  // KMP 알고리즘
  int n = P.size() * 2;
  string T = P + P;
  for(int i = 0, j = 0; i < n - 1; i++) {
    while(j > 0 && T[i] != P[j]) j = fail[j - 1];
    if(T[i] == P[j]) {
      if(j == m - 1) {
        result++;
        j = fail[j];
      }
      else j++;
    }
  }

  return result;
}

void solve(string cur) {
  if(cur.size() == len){
    if(kmp(cur) == K) {
      answer++;
    }
  }

  // 각 조합에 대해서 kmp실행
  for(int i = 0; i < N; i++) {
    if(check[i]) continue;
    check[i] = true;
    solve(cur + p[i]);
    check[i] = false;
  }
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve("");
  cout << answer;
  
  return 0;
}