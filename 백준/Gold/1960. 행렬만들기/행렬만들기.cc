#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool board[505][505] = {};
vector<pair<int, int>> row;
vector<int> col;

void input() {
  cin >> N;
  for(int i = 0; i < N; i++){
    int a; cin >> a;
    row.push_back({a, i});
  }
  for(int i = 0; i < N; i++){
    int a; cin >> a;
    col.push_back(a);
  }
}

bool compare(pair<int, int> &a, pair<int, int> &b){
  return a.first > b.first;
}

void solve() {
  for(int i = 0; i < N; i++) {
    int cur = col[i];
    sort(row.begin(), row.end(), compare);
    for(int j = 0; j < N; j++) {
      if(row[j].first > 0){
        cur--;
        row[j].first--;
        board[row[j].second][i] = 1;
      }
      if(cur == 0) break;
    }
    if(cur > 0) {
      cout << -1;
      return;
    }
  }
  
  cout << "1\n";
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
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