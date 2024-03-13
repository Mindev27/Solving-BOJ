#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

const int MOD = 100003;
int N;
string P;
vector<int> pos[MOD]; // pos[i] : 해시값이 i인 부분 문자열의 등장 위치

void input() {
  cin >> N >> P;
}

// 모듈러연산
inline int mod(ll x) {
  if(x >= 0) return x % MOD;
  return ((-x / MOD + 1) * MOD + x) % MOD;
}

bool RabinKarp(int k) {
  bool isFind = false;
  ll H = 0, power = 1;
  for(int i = 0; i < MOD; i++)
    pos[i].clear();

  for(int i = 0; i <= N - k; i++) { 
    if(i == 0) {
      for(int j = 0; j < k; j++) { // 첫 글자의 해시값 계산
        H = mod(H + 1LL * P[k - j - 1] * power);
        if(j < k - 1) power = mod(power * 2);
      }
    }
    else H = mod(2*(H - 1LL * P[i - 1] * power) + P[i + k - 1]);

    if(!pos[H].empty()) {
      for(int j = 0; j < pos[H].size(); j++) {
        bool isSame = true;
        for(int l = 0; l < k; l++) {
          if(P[i + l] != P[pos[H][j] + l]) {
            isSame = false;
            break;
          }
        }
        if(isSame) { isFind = true; break; }
      }
    }
    if(isFind) break;
    else pos[H].push_back(i);
  }
  return isFind;
}

// k길이의 문자열이 있는지 이분탐색으로 확인
void solve() {
  int l = 0, r = N;
  while(l + 1 < r) {
    int mid = (l + r) / 2;
    if(RabinKarp(mid)) l = mid;
    else r = mid;
  }

  cout << l;
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