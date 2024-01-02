#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

int calcDate(int month, int day);
bool compare(const pair<int, int> &a, const pair<int, int> &b);

int main() {
  int n;
  cin >> n;

  int startDate, endDate, minDate = 365, maxDate = 0;
  vector<pair<int, int>> v;

  //입력
  for(int i = 0; i < n; i++){
    int startM, startD, endM, endD;
    cin >> startM >> startD >> endM >> endD;

    startDate = calcDate(startM, startD);
    endDate = calcDate(endM, endD);
    
    // 가장 빨리 피는 꽃의 날짜 계산
    if(startDate < minDate)
      minDate = startDate;

    // 가장 늦게 피는 꽃의 날짜 계산
    if(maxDate < endDate)
      maxDate = endDate;
    
    v.push_back({startDate, endDate});
  }

  // 범위 내에 있는 꽃이 없다면 0 출력
  if(calcDate(3,1) < minDate || maxDate < calcDate(11,31)){
    cout << 0;
    return 0;
  }

  sort(v.begin(), v.end(), compare);

  // 답을 저장할 스택
  stack<pair<int, int>> ans;
  ans.push({v[0].first, v[0].second});
  int startIdx = 0, start, end;
    
  //3월 1일을 넘지 않는 첫 값 계산
  for(int i = 1; i < n; i++){
    start = v[i].first;
    end = v[i].second;

    // 다음값이 더 좋다면 변경
    if(start <= calcDate(3,1) && ans.top().second < end){
      ans.pop();
      ans.push({start, end});
      startIdx = i;
    }
  }

  int breakDate = calcDate(11, 31);

  while(true){
    int bestIdx = -1, bestStartDate = 0, BestEndDate = 0;
    start = ans.top().first;
    end = ans.top().second;
    
    // 11월 30일까지 모두 선택했으면 끝
    if(breakDate <= end)
      break;
    
    // 남은 값들을 탐색하며 그리디하게 가져가기
    for(int i = startIdx + 1; i < n; i++){
      
      // 범위안에 들때, 이전값 보다 더 좋다면
      if(v[i].first <= end){
        if(BestEndDate < v[i].second){
          bestStartDate = v[i].first;
          BestEndDate = v[i].second;
          bestIdx = i;
        }
      }
    }

    startIdx = bestIdx;
    
    // 끊어져 있다면
    if(bestStartDate == 0 && BestEndDate == 0){
      cout << 0;
      return 0;
    }
    else{
      ans.push({bestStartDate, BestEndDate});
    }
  } 

  cout << ans.size();

}

// 월 일을 숫자로 계산
int calcDate(int month, int day){
  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return accumulate(days, days + month, 0) + day;
}

// 시작 날짜가 작은 순으로, 끝 날짜가 큰 순으로 정렬
bool compare(const pair<int, int> &a, const pair<int, int> &b){
  if(a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}