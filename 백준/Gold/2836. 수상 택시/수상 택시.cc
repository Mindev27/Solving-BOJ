#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n, m;
vector<pair<ll, ll>> backward; // 뒤로 가는 직선

void input() {
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    ll a, b;
    cin >> a >> b;
    if(a > b) backward.push_back({a, b});
    // 어차피 m까지는 가기때문에 역방향인 정보만 더해주면 된다
  }
}

bool compare(pair<ll, ll> &a, pair<ll, ll> &b){
  return a.first > b.first;
}

ll solve() {
  ll result = m; // m만큼이동 + 뒤로 가는 값 * 2
  sort(backward.begin(), backward.end(), compare);

  if(backward.empty()) {
      return result;
  }

  ll start = backward[0].first;
  ll end   = backward[0].second;

  for(int i = 0; i < backward.size(); i++){
    ll nStart = backward[i].first;
    ll nEnd   = backward[i].second;

    if(nStart >= end){
      end = min(end, nEnd);
    }
    else{
      result += (start - end) * 2; // 갔다오기 때문에 
      start = nStart;
      end = nEnd;
    }
  }
  
  result += (start - end) * 2;
  return result;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();

  cout << solve();
}