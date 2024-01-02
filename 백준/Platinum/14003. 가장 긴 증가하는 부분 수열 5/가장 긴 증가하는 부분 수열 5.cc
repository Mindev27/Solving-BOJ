#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> L;  // LIS 저장
vector<int> P;  // 인덱스 정보를 저장

void input() {
  cin >> n;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    v.push_back(a);
  }
}

void solve() {
  for(int i = 0; i < v.size(); i++){
    int cur = v[i];
    
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
  cout << L.size() << '\n';

  vector<int> ans;
  int now = L.size() - 1;

  for(int i = P.size() - 1; i >= 0; i--){
    if(now == P[i]){
      now--;
      ans.push_back(v[i]);
    }
  }

  for(int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
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