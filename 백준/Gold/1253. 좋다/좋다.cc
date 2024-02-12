#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<ll> A;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++){
    ll x; cin >> x;
    A.push_back(x);
  }
}

void solve() {
  sort(A.begin(), A.end());
  int good = 0;

  for(int i = 0; i < N; ++i) {
    int l = 0, r = N - 1;
    while(l < r) {
      if(l == i) {l++; continue;}
      if(r == i) {r--; continue;}
      ll sum = A[l] + A[r];
      if(sum == A[i]) {
        good++;
        break;
      }
      if(sum < A[i]) l++;
      else r--;
    }
  }

  cout << good << '\n';
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
