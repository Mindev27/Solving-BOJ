#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, apple_cnt, apple_x, apple_y, move_cnt, move_time;
  char move_direction;
  bool is_alive = true;
  queue<pair<int, int>> snake; // 뱀의 위치를 담는 큐
  queue<pair<int, int>> move; // 움직이는 정보를 담는 배열
  pair<int, int> next_head;
  
  cin >> n;
  cin >> apple_cnt;

  //맵 배열 동적 할당
  int **map = new int*[n + 1];
  for(int i = 0; i < n + 1; i++){
    map[i] = new int[n + 1]();
  }
  
  for(int i = 0; i < apple_cnt; i++){
    cin >> apple_x >> apple_y;
    map[apple_x][apple_y] = 1;
  }

  cin >> move_cnt;

  for(int i = 0; i < move_cnt; i++){
    cin >> move_time >> move_direction;

    if(move_direction == 'D'){ 
      move.push(make_pair(move_time, 1)); // 오른쪽 1
    }
    else{
      move.push(make_pair(move_time, -1)); // 왼쪽 -1
    }
  }

  // 오른쪽 (0,1), 아래 (1,0), 왼쪽 (0,-1), 위 (-1,0)
  vector<pair<int, int>> seeing_direction;
  seeing_direction.push_back(make_pair(0,1));
  seeing_direction.push_back(make_pair(1,0));
  seeing_direction.push_back(make_pair(0,-1));
  seeing_direction.push_back(make_pair(-1,0));
  int direction_index = 0; //초기값 오른쪽
  
  snake.push(make_pair(1, 1)); // 1,1부터 시작
  
  
  int time = 0;
  while(true){ // 벽에 충돌하거나 몸에 닿을때까지 반복

    // move벡터에서 first값과 비교
    if(time == move.front().first){ // 회전
        
      direction_index += move.front().second;
      move.pop();
        
      if(direction_index < 0) direction_index = 3;
      if(direction_index > 3) direction_index = 0;    
    }

    next_head = make_pair(snake.back().first + seeing_direction[direction_index].first,
                          snake.back().second + seeing_direction[direction_index].second);
    
    //벽이라면 게임종료
    if(next_head.first < 1 || next_head.first > n || next_head.second < 1 || next_head.second > n)
      is_alive = false;
    
    //몸에 닿는지 확인
    pair<int, int> temp;
    for(int i = 0; i < snake.size(); i++){
      temp = snake.front();
      snake.pop();
      if(next_head == temp) // 몸에 닿았다면
        is_alive = false;
      snake.push(temp);
    }

    if(!is_alive) break;

    time++;

    //만약 다음칸이 사과라면
    if(map[next_head.first][next_head.second] == 1){
      snake.push(next_head);
      map[next_head.first][next_head.second] = 0;
    }
    else{ // 아니라면 
      snake.push(next_head);
      snake.pop();
    }

    
  }

  cout << time + 1;

  delete [] map;
}