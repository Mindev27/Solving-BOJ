#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int MAX = 1000005;
string T, P;
int fail[MAX];

void solve(string P) {
  memset(fail, 0, sizeof(fail));
  
  // 실패 함수 만들기
  int m = P.size();
  for (int i = 1, j = 0; i < m; i++) {
    while (j > 0 && P[i] != P[j])
      j = fail[j - 1];
    if (P[i] == P[j])
      fail[i] = ++j;
  }

  cout << m - fail[m - 1] << '\n';
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a; cin >> a;
  string P; cin >> P;
  solve(P);

  return 0;
}