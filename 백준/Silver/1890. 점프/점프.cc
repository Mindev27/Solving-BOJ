#include <iostream>

using namespace std;

int main() {
  const int SIZE = 101;
  int map[SIZE][SIZE] = {};
  long long int dist[SIZE][SIZE] = {};
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> map[i][j];
    }
  }

  dist[1][1] = 1;
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == n && j ==n) break;
      
      if(dist[i][j] != 0){
        // 현재 좌표에서 움직일때 x, y 좌표
        int jumpX = j + map[i][j];
        int jumpY = i + map[i][j];

        if(jumpX <= n) dist[i][jumpX] += dist[i][j];
        if(jumpY <= n) dist[jumpY][j] += dist[i][j];
      }
    }
  }

  cout << dist[n][n];
}
