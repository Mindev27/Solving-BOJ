#include <iostream>
#define ll long long

using namespace std;

const int DIV = 1'000'000'007;
int N;

void multiple(ll (*a1)[8], ll (*a2)[8]) {
  ll ans[8][8] = {};
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      for(int k = 0; k < 8; ++k){
        ans[i][j] += a1[i][k] * a2[k][j];
      }
      ans[i][j] %= DIV;
    }
  }
  for(int i = 0; i < 8; ++i)
    for(int j = 0; j < 8; ++j)
      a1[i][j] = ans[i][j];
}

void solve() {
  ll adj[8][8] = {
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,0,1},
    {0,0,0,1,1,0,1,0},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,1,0,1,0}
  };
  
  ll answer[8][8] = {
    {1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,1},
  };

  while(N > 0) {
    if(N & 1) {
      multiple(answer, adj);
      N -= 1;
    }
    multiple(adj, adj);
    N /= 2;
  }
  
  cout << answer[0][0];
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  solve();
  
  return 0;
}
