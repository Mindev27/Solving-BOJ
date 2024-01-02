#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

int main() {
  int n;
  vector<pair<int, int>> data;
  stack<pair<int, int>> s;
  pair<int, int> max = {0, 0};

  //입력
  cin >> n;
  for(int i = 0; i < n; i++){
    int location, height;
    cin >> location >> height;
    data.push_back({location, height});

    if(height >= max.second){
      max.first = location;
      max.second = height;
    }
  }

  sort(data.begin(), data.end(), compare);
  
  int Area = 0;

  // 왼쪽 값 누적
  if(data[0].first != max.first){

    s.push({data[0].first, data[0].second}); // 첫 값 push

    //순회하며 높을때만 스택에 넣기
    for(int i = 1; i < data.size(); i++){
      if(data[i].first == max.first)
        break;

      if(s.top().second <= data[i].second)
        s.push({data[i].first, data[i].second});
    }

    //누적 넓이 계산
    int tempLocation = max.first;
    while(!s.empty()){
      Area += (tempLocation - s.top().first) * s.top().second;
      tempLocation = s.top().first;
      s.pop();
    }
  }

  // 오른쪽 값 누적
  int endIdx = data.size() - 1;
  if(data[endIdx].first != max.first){

    s.push({data[endIdx].first, data[endIdx].second}); // 끝 값 push

    //순회하며 높을때만 스택에 넣기
    for(int i = endIdx; i >= 0; i--){
      if(data[i].first == max.first)
        break;

      if(s.top().second <= data[i].second)
        s.push({data[i].first, data[i].second});
    }

    //누적 넓이 계산
    int tempLocation = max.first + 1;
    while(!s.empty()){
      Area += (s.top().first + 1 - tempLocation) * s.top().second;
      tempLocation = s.top().first + 1;
      s.pop();
    }
  }

  // 가장 큰 넓이 누적
  Area += max.second;

  cout << Area;
}