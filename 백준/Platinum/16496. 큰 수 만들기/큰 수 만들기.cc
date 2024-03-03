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

int N;
bool isAllZero = true;
vector<ll> v;

void input() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    ll a; cin >> a;
    v.push_back(a);
    if(a != 0) isAllZero = false;
  }
}

void solve() {
  if(isAllZero) {cout << 0; return; }
  
  sort(v.begin(), v.end(), [&](ll a, ll b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    for(int i = 0 ; i < s1.size(); i++) {
      if(s1[i] > s2[i]) return true;
      else if(s1[i] < s2[i]) return false;
    }
    return true;
  });

  for(ll &i : v) cout << i;
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