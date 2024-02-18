#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;

void input() { 
  cin >> N;
}

void solve() {
  int K = 1;
  while (K < N) K <<= 1;

  vector<vector<int>> ans;
  for(int i = (K >> 1); i > 0; i >>= 1){
    vector<int> temp;
    for(int j = 1; j <= N; j++){
      if(!temp.empty() && temp.size() % i == 0)
        j += i;
      if(j > N) break;
      temp.push_back(j);
    }
    ans.push_back(temp);
  }

  cout << ans.size() << '\n';
  for(auto& vec : ans){
    cout << vec.size() << ' ';
    for(int i : vec) cout << i << ' ';
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
