#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//정렬 기준 함수
bool cmp(vector<int> &v1, vector<int> &v2){
  if(v1[1] == v2[1])
    return v1[0]<v2[0];
  else return v1[1]<v2[1];
}

int main() {
  int TestCase, i, index, end_time, cnt;

  cin >> TestCase;

  vector<vector<int>> data(TestCase, vector<int>(2));
  
  for(i = 0; i < TestCase; i++){
    cin >> data[i][0] >> data[i][1];
  }
  
  //끝나는 시간 기준으로 정렬
  sort(data.begin(), data.end(), cmp);

  index = 0;
  cnt = 0; // 첫번째 회의 횟수추가
  end_time = 0;
  
  while(1){
    if(end_time <= data[index][0]){
      end_time = data[index][1];
      cnt++;
    }

    if(index >= TestCase - 1){
      break;
    }

    index++;
  }
  
  cout << cnt;
}