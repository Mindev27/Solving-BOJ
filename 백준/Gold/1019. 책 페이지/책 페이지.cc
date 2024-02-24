#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

// cnt[i][0] -> 1 ~ 9..9(i자리)까지의 0의 개수
// cnt[i][1] -> 1 ~ 9..9(i자리)까지의 0이외의 숫자 개수
ll cnt[10][2] = {
  {0, 0}, {0, 1}, {9, 20}, {189, 300}, {2889, 4000},
  {38889, 50000}, {488889, 600000}, {5888889, 7000000},
  {68888889, 80000000}, {788888889, 900000000}
};
int N;

ll ans[10] = {};

void count(int n, int len, bool isFront) {
  ll temp[10] = {};
  
  if(isFront) { // 1 ~ 9..9까지 세기
    temp[0] += cnt[len - 1][0];
    for(int i = 1; i <= 9; i++)
      temp[i] += cnt[len - 1][1];

    for(int i = 1; i < n; i++) { // 자릿수 올려가며 세기
      temp[i] += pow(10, len - 1);
      for(int j = 0; j <= 9; j++)
        temp[j] += cnt[len - 1][1];
    }
  }
  else {
    if(n == 0) return;

    for(int i = 0; i < n; i++) {
      temp[i] += pow(10, len - 1);
      for(int j = 0; j <= 9; j++)
        temp[j] += cnt[len - 1][1];
    }
  }

  for(int i = 0; i < 10; i++) {
    ans[i] += temp[i];
  }
}

void solve() {
  string s = to_string(N);
  int len = s.length();
  bool isFront = true;

  int curLen = len;
  
  for(int i = 0; i < len - 1; i++) {
    int cur = s[i] - '0';
    count(cur, curLen, isFront);
    
    
    int leftNum = N % (ll)pow(10, curLen - 1);

    ans[cur] += leftNum + 1;

    if(isFront) isFront = false;
    curLen--;
  }

  // 마지막 자리 더해주기
  int last = s[len - 1] - '0';
  for(int i = 0; i <= last; i++){
    ans[i]++;
  }

  // 한자리 수라면 0은 없음
  if(len == 1) {
    ans[0]--;
  }

  for(int i = 0; i < 10; i++) {
    cout << ans[i] << ' ';
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  solve();

  return 0;
}
