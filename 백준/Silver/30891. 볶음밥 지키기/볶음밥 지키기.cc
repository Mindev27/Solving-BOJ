#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

int N ,R;
vector<pair<int, int>> rice;

void input() {
  cin >> N >> R;
  for(int i = 0; i < N; i++){
    int a, b; cin >> a >> b;
    rice.push_back({a, b});
  }
}

int saveRice(int x, int y){
  int cnt = 0;
  for(int i = 0; i < rice.size(); i++){
    int curX = rice[i].first;
    int curY = rice[i].second;

    int dist = (curX - x) *  (curX - x) + (curY - y) * (curY - y);
    if(dist <= R * R)
      cnt++;
  }
  return cnt;
}

void solve() {
  int result = 0;
  int resultX = 0, resultY = 0;
  for(int i = -100; i <= 100; i++){
    for(int j = -100; j <= 100; j++){
      if(result <= saveRice(i, j)){
        resultX = i;
        resultY = j;
        result = saveRice(i, j);
      }
    }
  }
  cout << resultX << ' ' << resultY;;
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
