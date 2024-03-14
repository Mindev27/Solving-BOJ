#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int N;
vector<int> prime;

void findPrime() {
  vector<bool> isPrime(N + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j += i)
        isPrime[j] = false;
    }
  }
  for (int i = 2; i <= N; ++i) {
    if (isPrime[i])
      prime.push_back(i);
  }
}

void input() {
  cin >> N;
}

void solve() {
  findPrime();

  int left = 0, right = prime.size() - 1, mid, response;
  while (left <= right) {
    mid = (left + right) / 2;
    cout << "? " << prime[mid] << endl;

    cin >> response;
    if (response == 1) left = mid + 1;
    else right = mid - 1;
  }
  cout << "! " << prime[left] << endl;
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