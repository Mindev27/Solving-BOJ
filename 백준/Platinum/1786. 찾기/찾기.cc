#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int MAX = 1000005;
string T, P;
int fail[MAX];

void input() {
  getline(cin, T);
  getline(cin, P);
}

void solve() {
  // 실패 함수 만들기
  int m = P.size();
  for(int i = 1, j = 0; i < m; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }
  
  // KMP 알고리즘
  int n = T.size();
  vector<int> result;
  for(int i = 0, j = 0; i < n; i++) {
    while(j > 0 && T[i] != P[j]) j = fail[j - 1];
    if(T[i] == P[j]) {
      if(j == m - 1) {
        result.push_back(i - m + 2);
        j = fail[j];
      }
      else j++;
    }
  }

  cout << result.size() << '\n';
  for(int &i : result)
    cout << i << ' ';
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