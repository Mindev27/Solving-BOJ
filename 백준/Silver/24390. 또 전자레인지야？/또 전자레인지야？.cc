#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int minute, seconds, times;
int jump[4] = {1, 3, 6, 60};
bool visited[400][2] = {}; // 시간, 시작 여부

void input() {
  string temp;
  cin >> temp;
  minute = stoi(temp.substr(0, 2));
  seconds = stoi(temp.substr(3, 2));

  times = (minute * 60 + seconds) / 10; // 10의 배수라 10 나누고 시작
  
}

void solve(){
  if(times == 0){
    cout << 0;
    return;
  }
  queue<pair<pair<int, int>, bool>> q; // 현재 시간, 누를 횟수, 시작여부
  q.push({{0, 0}, false});
  visited[0][0] = true;

  while(!q.empty()){
    int curTime = q.front().first.first;
    int clickNum = q.front().first.second;
    bool isStart = q.front().second;
    q.pop();
    
    if(curTime == times && isStart){ // 찾았다면 답 출력
      cout << clickNum;
      return;
    }

    for(int i = 0; i < 4; i++){
      int nextTime = curTime + jump[i];
      bool nextIsStart = isStart;
      
      if(i == 1 && !nextIsStart){ // 시작하는 경우
        nextIsStart = true;
        if(clickNum != 0){
          nextTime -= 3;
        }
      }

      if(!visited[nextTime][(int)nextIsStart] && nextTime <= times){
        visited[nextTime][(int)nextIsStart] = true;
        q.push({{nextTime, clickNum + 1}, nextIsStart});
      }
    }
  }
}

int main() {
  // freopen("input.txt" ,"r", stdin);

  input();

  solve();

  return 0;
}