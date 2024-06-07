#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N, iter;
int board[105][105];
vector<int> nums;
map<int, bool> m;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

vector<int> getPrime(int x) {
  vector<bool> prime(x + 1, true);
  vector<int> primes;

  // 0과 1은 소수가 아님
  prime[0] = prime[1] = false;

  for (int p = 2; p * p <= x; p++) {
    if (prime[p]) {
      // p가 소수인 경우, p의 배수들을 소수에서 제외
      for (int i = p * p; i <= x; i += p) {
        prime[i] = false;
      }
    }
  }

  // 소수 배열을 생성
  for (int p = 2; p <= x; p++) {
    if (prime[p]) {
      primes.push_back(p);
    }
  }

  return primes;
}

void input() {
  cin >> N;

  iter = N * N * N * N;

  for (int i = 0; i < N * N; i++) {
    for (int j = 0; j < N * N; j++) {
      cin >> board[i][j];
      if (board[i][j] != 0) {
        iter--;
        nums.push_back(board[i][j]);
      }
    }
  }
}

void solve() {
  vector<int> p = getPrime(500000);
  vector<int> ans;

  for (int num : nums) {
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        while (num % i == 0) {
          num /= i;
        }
        m[i] = true;
      }
    }
    if (num > 1) {
      m[num] = true;
    }
  }

  // 보드에 있는 숫자 제거
  for (int i = 0; i < p.size(); i++) {
    if (m.find(p[i]) == m.end())
      ans.push_back(p[i]);
  }

  // 보드 출력
  int idx = 0;
  for (int i = 0; i < N * N; i++) {
    for (int j = 0; j < N * N; j++) {
      if (board[i][j] != 0)
        cout << board[i][j] << ' ';
      else
        cout << ans[idx++] << ' ';
    }
    cout << '\n';
  }
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
