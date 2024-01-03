#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 30005;
int N, M, K;
int dp[3005] = {};
int candy[SIZE] = {};
int parent[SIZE] = {};
pair<int, int> group[SIZE];

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  int x = getParent(a);
  int y = getParent(b);
  if (x > y) parent[x] = y;
  else parent[y] = x;
}

void init() {
  for(int i = 1; i <= SIZE; ++i){
    parent[i] = i;
  }
}

void input() {
  cin >> N >> M >> K;
  for(int i = 1; i <= N; ++i)
    cin >> candy[i];

  for(int i = 1; i <= M; ++i) {
    int a, b;
    cin >> a >> b;
    unionParent(a, b);
  }
}



void solve() {
  for(int i = 1; i<= N; ++i) { // 하나의 그룹으로 묶기
    int curP = getParent(i);
    group[curP].first += 1;
    group[curP].second += candy[i];
  }

  int result = 0;
  dp[0] = 0;
  for(int i = 1; i <= N; ++i) {
    if(group[i].first == 0) continue;

    for(int j = K - 1; j >= 0; --j) {
      if(group[i].first <= j){
        dp[j] = max(dp[j], dp[j - group[i].first] + group[i].second);
        result = max(result, dp[j]);
      }
    }
  }
  cout << result;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  init();
  input();
  solve();
  
  return 0;
}