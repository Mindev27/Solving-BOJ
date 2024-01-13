#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll M, N;
vector<pair<int, int>> pie;
bool turnMore[300005] = {}; // 한번 더 돌아야하는 베리

void input() {
  cin >> M >> N;
  pie.resize(N);
  for(int i = 0; i < N; i++)
    cin >> pie[i].first;
  for(int i = 0; i < N; i++)
    cin >> pie[i].second;
}

// 스위핑을 통해서 한바퀴 더 돌아야하는 베리를 계산
void sweeping() {
  vector<pair<pair<int, int>, int>> temp; // (출발, 끝, 인덱스)

  for(int i = 0; i < N; i++) {
    if(pie[i].first < pie[i].second) // 0을 지나가는 경우
      temp.push_back({{pie[i].second, pie[i].first + M}, i});

    else{ // 0을 지나지 않는 경우
      temp.push_back({{pie[i].second, pie[i].first}, i});
      temp.push_back({{pie[i].second + M, pie[i].first + M}, i});
    }
  }

  // 시작지점은 오름차순 끝지점은 내림차순 정렬
  sort(temp.begin(), temp.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first.first == b.first.first) return a.first.second > b.first.second;
    return a.first.first < b.first.first;
  });

  // 한번더 돌아야하는 베리를 계산
  ll end = temp[0].first.second;
  ll sz = (ll)temp.size();

  for(int i = 1; i < sz; i++) {
    if(temp[i].first.second < end)
      turnMore[temp[i].second] = true;
    else end = temp[i].first.second;
  }
}

ll solve() {
  if(N == 1) { // 사람이 한명인 경우
    if(pie[0].first >= pie[0].second)
      return pie[0].first - pie[0].second;
    else
      return M + pie[0].first - pie[0].second;
  }
  
  // 파이기준 정렬
  sort(pie.begin(), pie.end(), [&](pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
  }); 

  // 동시에 같은 파이를 원하는지 검사
  for(int i = 0; i < N - 1; i++){
    if(pie[i].second == pie[i + 1].second) return -1;
  }

  if(M == N) { // 인원과 똑같은 경우 바꾸지않고 만족해야한다
    for(int i = 0; i < N; i++){
      if(pie[i].first != pie[i].second) return -1;
    }
    return 0;
  }

  sort(pie.begin(), pie.end()); // 사람기준 오름차순정렬

  // 파이가 오름차순인지 검사(한바퀴돌면 1번 감소해야함)
  bool isDown = pie[N - 1].second > pie[0].second;
  for(int i = 0; i < N - 1; i++){
    if(pie[i].second > pie[i + 1].second && isDown)
      return -1;
    if(pie[i].second > pie[i + 1].second)
      isDown = true;
  }

  sweeping(); // 스위핑

  ll result = 0;
  for(int i = 0; i < N; i++) {
    ll gap = pie[i].first - pie[i].second;
    result += gap >= 0 ? gap : M + gap;

    if(turnMore[i])
      result += M; // 한바퀴 더 돎
  }

  return result;
}

int main(void) {
  // (void)freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input();
  cout << solve();

  return 0;
}