#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int N;
vector<int> v;

void input() {
  cin >> N;
  v.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i];
  }
}

// k범위가 된다면 그보다 큰 범위도 커버된다
void solve() {
  int pre = v[0];
  int result = 1, k = 1;
  
  for(int i = 1; i < N; i++) {
    if(pre > v[i]) k++; // 감소하면 더 뛰어넘어야함 
    else {              // 증가하면 한칸으로 초기화
      k = 1;
      pre = v[i];
    }

    result = max(result, k);
  }

  cout << result;
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