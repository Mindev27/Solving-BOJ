#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int n;
vector<pair<int, int>> v; // 사용할 날짜, 남은 날짜

void input() {
  cin >> n;
  ll temp[100005] = {};

  for(int i = 0; i < n; i++){
    cin >>temp[i];
  }

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    v.push_back({a, temp[i]});
  }
}


ll solve(){
  sort(v.begin(), v.end());

  ll result = 0;
  int latestNum = v[0].first;  // 가장 오래된 날짜
  int curMax = -1;
  int cnt = 0;
  
  for(int i = 0; i < n; i++){
    int usingDate = v[i].first; // 사용할 날짜
    int expDate = v[i].second;  // 유효 날짜
    
    // cout << "usingDate : " << usingDate << " expDate : " << expDate << "\n";
    
    latestNum = max(latestNum, usingDate);
    
    // 유효기간이 지금까지의 날짜보다 작다면 더해주기
    if(latestNum > expDate){
      int changeNum = (latestNum - expDate) / 30;
      changeNum += (latestNum - expDate) % 30 ? 1 : 0; // 안나눠떨어지면 +1
      expDate += changeNum * 30;
      result += changeNum;
    }

    curMax = max(curMax, expDate);
    
    if(i + 1 < n && usingDate != v[i + 1].first)
      latestNum = curMax;

    // cout << "result : " << result << " latestNum : " << latestNum << "\n\n";
  }

  return result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  input();

  cout << solve();
  
  return 0;
}