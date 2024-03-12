#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int N, idx;
vector<int> t, p;
string T, P;
int fail[400005];

void input() {
  cin >> N;
  t.resize(N), p.resize(N);
  for(int i = 0; i < N; i++)
    cin >> t[i];
  for(int i = 0; i < N; i++)
    cin >> p[i];
}

bool KMP() {
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
      if(j == m - 1)
        return true;
      else j++;
    }
  }

  return false;
}

void solve() {
  sort(t.begin(), t.end());
  sort(p.begin(), p.end());

  idx = 0;
  for(int i = 0; i < 360000; i++) {
    if(idx >= t.size()) T += '#';
    else if(t[idx] == i) { T += '.'; idx++; }
    else T += '#';
  }
  idx = 0;
  for(int i = 0; i < 360000; i++) {
    if(idx >= p.size()) P += '#';
    else if(p[idx] == i) { P += '.'; idx++; }
    else P += '#';
  }

  T += T;
  if(KMP()) cout << "possible";
  else cout << "impossible";
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