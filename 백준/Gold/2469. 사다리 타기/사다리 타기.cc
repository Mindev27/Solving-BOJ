#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int K, N, mid;
string st, ed;
vector<string> ladder;

void input() {
  cin >> K >> N;
  for(int i = 0; i < K; i++) {
    st += (char)(i + 'A');
  }
  cin >> ed;

  ladder.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> ladder[i];
    if(ladder[i][0] == '?')
      mid = i;
  }
}

void solve() {
  // 앞부분 만들기
  for(int i = 0; i < mid; i++) {
    for(int j = 0; j < ladder[i].size(); j++) {
      char c = ladder[i][j];
      if(c == '-') swap(st[j], st[j + 1]);
    }
  }

  for(int i = N - 1; i > mid; i--) {
    for(int j = 0 ; j < ladder[i].size(); j++) {
      char c = ladder[i][j];
      if(c == '-') swap(ed[j], ed[j + 1]);
    }
  }

  bool flag = true;
  string ans = "";
  for(int i = 0 ; i < K - 1; i++) {
    if(st[i] == ed[i + 1])
      ans += '-';
    else if(st[i] == ed[i - 1] || st[i] == ed[i])
      ans += '*';
    else { flag = false; break; }
  }

  if(flag == false) {
    ans = "";
    for(int i = 0; i < K - 1; i++)
      ans += 'x';
  }
  
  cout << ans;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  solve();

  return 0;
}
