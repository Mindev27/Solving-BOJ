#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> num;
bool palin[2005][2005] = {};
vector<pair<int, int>> query;

void input() {
  cin >> n;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    num.push_back(x);
  }
  cin >> m;
  for(int i = 0; i < m; ++i){
    int x, y;
    cin >> x >> y;
    query.push_back({x - 1, y - 1});
  }
}

void init() {
  for(int i = 0; i < n; ++i){
    palin[i][i] = true;
    if(i < n - 1 && num[i] == num[i + 1])
      palin[i][i + 1] = true;
  }
}

void solve() {
  for(int i = n - 1; i >= 0; --i){
    for(int j = 0; j < n; j++){
      if(num[i] == num[j] && palin[i + 1][j - 1])
        palin[i][j] = true;
    }
  }

  for(int i = 0; i < m; ++i){
    int x = query[i].first;
    int y = query[i].second;
    if(palin[x][y])
      cout << "1\n";
    else
      cout << "0\n";
  }
}

int main() {
  // (void)freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  init();
  solve();


  return 0;
}
