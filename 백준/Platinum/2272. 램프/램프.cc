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

ll N, M;
int a[1000005];

void input() {
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
}

void solve() {
  int i = 0;
  while(true) {
    if(M < (1LL << i)) break;
    
    if(M & (1LL << i)) {
      int temp[1000005];
      
      for(int j = 0; j < N; j++)
        temp[j] = a[j]^a[((1LL << i) + j) % N];
      
      for(int j = 0; j < N; j++)
        a[j] = temp[j];
    }
    i++;
  }

  for(int i = 0; i < N; i++)
    cout << a[i] << '\n';
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