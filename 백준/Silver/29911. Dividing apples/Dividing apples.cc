#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>

using namespace std;

int N;
ll a[1000005];
ll sum = 0;

void input() {
  cin >> N;
  
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    sum += x;
    a[i] = sum;
  }
}

void solve() {
  ll minVal = 1e18;
  int result = 0;
  for(int i = 0; i < N; i++) {
    if(minVal > abs(2 * a[i] - sum)) {
      minVal = abs(2 * a[i] - sum);
      result  = i;
    }
  }

  cout << result + 1;
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
