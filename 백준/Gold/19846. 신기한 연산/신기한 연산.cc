#include <iostream>
#include <vector>

using namespace std;

int N, M, Q;
vector<pair<int, int>> query;


void input() {
  cin >> N >> M >> Q;
  for(int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    query.push_back({a - 1, b - 1});
  }
}

void solve() {
  string result = "";
  while(true){
    for(int i = 0; i < N; i++) {
      result += 'a' + i;
      if(result.length() == M){
        cout << result;
        return;
      }
      result += 'a' + i;
      if(result.length() == M){
        cout << result;
        return;
      }
    }
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