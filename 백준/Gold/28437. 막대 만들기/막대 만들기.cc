#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;
int n, q;
int stick[MAX] = {};
int query[MAX] = {};
int dp[MAX] = {};

void input(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> stick[i];
  }

  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> query[i];
  }
}

void solve(){
  memset(dp, 0, sizeof(dp));
  
  for(int i = 0; i < n; i++){
    int temp = stick[i];
    dp[temp] = 1;
  }

  for(int i = 1; i < MAX; i++){
    for(int j = 2 * i; j < MAX; j += i){
      dp[j] += dp[i];
    }
  }
}

void printAnswer(){
  for(int i = 0; i < q; i++){
    int temp = query[i];
    cout << dp[temp] << ' ';
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  input();

  solve();

  printAnswer();
}