#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <tuple>
#define ll long long
using namespace std;

ll N;
vector<ll> ph;

void input() {
  cin >> N;

  for (int i = 0; i < N; i++){
    ll a; cin >> a;
    ph.push_back(a);
  }
}

tuple<ll, ll, ll> solve() {
  sort(ph.begin(), ph.end());  // 오름차순 정렬

  ll result = LLONG_MAX;
  tuple<ll, ll, ll> answer;
  
  for(int i = 0; i < N - 2; i++){ // i를 선택한 후 투포인터 탐
    ll left = i + 1;
    ll right = N - 1;
    while(left < right){
      ll curPh = ph[i] + ph[left] + ph[right];
      if(abs(curPh) < result){
        result = abs(curPh);
        answer = {ph[i], ph[left], ph[right]};
      }
      if(curPh < 0) left++;
      else right--;
    }
  }
  return answer;
}

int main() {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  auto result = solve();
  cout << get<0>(result) << ' ';
  cout << get<1>(result) << ' ';
  cout << get<2>(result);

  return 0;
}

