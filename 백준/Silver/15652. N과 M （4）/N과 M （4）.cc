#include <iostream>

using namespace std;

int n, m;
int num[10] = {};

void solve(int dep) {
  if(dep == m){
    for(int i = 0; i < m; i++){
      cout << num[i] << ' ';
    }
    cout << "\n";
    return;
  }

  for(int i = 1; i <= n; i++){
    if(dep == 0 || num[dep - 1] <= i){
      num[dep] = i;
      solve(dep + 1);
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;
  
  solve(0);

  return 0;
}