#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long

using namespace std;

int n, findNum;
int want[100005] = {};   // 서로 원하는 정보 저장
bool visited[100005] = {}; // 방문 여부 저장
bool matched[100005] = {};    // 매치가 된 학생 정보저장

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> want[i]; 
    visited[i] = false;
    matched[i] = false;
  }
}

void dfs(int x) {
  visited[x] = true;
  int nStudent = want[x];

  if(!visited[nStudent]){
    dfs(nStudent);
  }

  else if(!matched[nStudent]) {
    for(int i = nStudent; i != x; i = want[i]) {
      findNum++;
    }
    findNum++;
  }
  matched[x] = true;
}

void solve() {
  findNum = 0;
  for(int i = 1; i <= n; i++){
    if(visited[i]) continue;
    dfs(i);
  }

  cout << n - findNum << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while(T--){
    input();
    solve();
  }
  
  return 0;
}
