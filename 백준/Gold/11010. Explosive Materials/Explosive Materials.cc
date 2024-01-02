#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int color[1001] = {};
vector<int> map[1001]; // 인접 리스트
vector<pair<int, int>> v;

void BFS(int x);

int main() {
  int testCase;
  cin >> testCase;

  while(testCase--){
    int vNum, eNum;
    cin >> vNum >> eNum;

    // 정보 초기화
    v.clear();
    for(int i = 1; i <= vNum; i++){
      color[i] = 0;
      map[i].clear();
    }
    
    // 인접 리스트에 저장
    for(int i = 0; i < eNum; i++){
      int a, b;
      cin >> a >> b;
      map[a].push_back(b);
      map[b].push_back(a); 
    }

    //색칠하기
    for(int i = 1; i <= vNum; i++){
      if(color[i] == 0){
        BFS(i);
      }
    }

    //합 계산하기
    int dp[1001][1001] = {};
    memset(dp, -1, sizeof(dp));

    //초기값 설정
    dp[0][v[0].first] = v[0].second;
    dp[0][v[0].second] = v[0].first;

    for(int i = 1; i < v.size(); i++){
      int val1 = v[i].first;
      int val2 = v[i].second;
      
      //그대로 넣는경우
      for(int j = 1000; j >= 0; j--){
        
        if(dp[i - 1][j] != -1){  // 값이 있다면
          
          if(dp[i][j + val1] == -1)  //원래 값이 없으면 그냥 넣기
            dp[i][j + val1] = dp[i - 1][j] + val2;
          
          else  //없었다면 둘중 작은값 가져가기
            dp[i][j + val1] = min(dp[i][j + val1], dp[i - 1][j] + val2);
        }
      }

      //뒤집어서 넣는경우
      for(int j = 1000; j >= 0; j--){
        if(dp[i - 1][j] != -1){  // 값이 있다면
          
          if(dp[i][j + val2] == -1)  //원래 값이 없으면 그냥 넣기
            dp[i][j + val2] = dp[i - 1][j] + val1;
          
          else  //없었다면 둘중 작은값 가져가기
            dp[i][j + val2] = min(dp[i][j + val2], dp[i - 1][j] + val1);
        }
      }
    }

    //마지막 배열을 순회하며 최적해 구하기
    int ans = 99999999;
    for(int i = 0; i < 1001; i++){
      if(dp[v.size()-1][i] != -1)
        ans = min(ans, max(dp[v.size()-1][i], i));
    }
    
    // 이분 그래프 가능성 판별
    bool isCorrect = true;
    
    for(int i = 1; i <= vNum; i++){
      
      for(int j = 0; j < map[i].size(); j++){
        if(color[i] == color[map[i][j]])
          isCorrect = false;
      }
    }

    if(isCorrect) 
      cout << ans << "\n";
    else 
      cout << "-1\n";
  }
}

void BFS(int x){
  queue<int> q;
  int group1 = 1, group2 = 0;
  color[x] = 1; //처음 노드를 1로 칠하기
  q.push(x);
  
  while(!q.empty()){
    int curNode = q.front();
    int curColor = color[curNode];
    q.pop();
  
    //연결된 노드 탐색
    for(int j = 0; j < map[curNode].size(); j++){

      //방문하지 않았다면 앞 노드와 다른 색으로 칠하기
      if(color[map[curNode][j]] == 0){
        if(curColor == 1){
          color[map[curNode][j]] = 2;
          group2++;
        } 
        if(curColor == 2){
          color[map[curNode][j]] = 1;
          group1++;
        } 
        q.push(map[curNode][j]);
      }
    }
  }

  v.push_back({group1, group2});
}