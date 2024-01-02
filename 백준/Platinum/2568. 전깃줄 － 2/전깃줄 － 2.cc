#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> L;    // LIS 저장
vector<int> P;    // 데이터값이 L에서 몇번째 인덱스인지

void input() {
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
}

void solve() {
  sort(v.begin(), v.end()); // 인덱스 순으로 정렬
  for(int i = 0; i < v.size(); i++){
    int cur = v[i].second;
    
    if(L.empty() || cur > L.back()){
      L.push_back(cur);
      P.push_back(L.size() - 1);
    }
    else{
      int findIndex = lower_bound(L.begin(), L.end(), cur) - L.begin();
      L[findIndex] = cur;
      P.push_back(findIndex);
    }

  }
}

void printAnswer() {
  vector<int> ans;  // 삭제할 데이터 저장
  cout << v.size() - L.size() << '\n';

  int now = L.size() - 1;
  
  for(int i = P.size() - 1; i >= 0; i--){
    if(now == P[i]) now--;
    else ans.push_back(v[i].first);
  }

  sort(ans.begin(), ans.end());
  for(int i: ans)
    cout << i << '\n';
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  input();
  solve();
  printAnswer();
  
  return 0;
}