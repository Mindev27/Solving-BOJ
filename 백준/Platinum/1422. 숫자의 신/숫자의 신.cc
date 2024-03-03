#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int K, N;
vector<ll> v;

void input() {
  cin >> K >> N;
  for(int i = 0 ; i < K; i++) {
    ll a; cin >> a;
    v.push_back(a);
  }
}

void solve() {
  sort(v.begin(), v.end(), [&](ll a, ll b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    if(s1 == s2) return false;
    else return s1 > s2;
  });

  ll maxNum = 0;
  for(ll &i : v)
    maxNum = max(maxNum, i);

  int gap = N - K;
  for(ll &i : v) {
    if(gap > 0 && i == maxNum) {
      while(gap--) cout << i;
    }
    cout << i;
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