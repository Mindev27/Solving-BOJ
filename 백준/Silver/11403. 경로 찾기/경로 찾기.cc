#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  const int INF = 9999999;
  int map[101][101] = {};
  int dist[101][101] = {};
  int n;
  cin >> n;

  //입력
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> map[i][j];
    }
  }

  //dist 배열 초기화
  for(int i = 1; i <= n; i++){
    for(int j =1; j <= n; j++){
      if (map[i][j]) dist[i][j] = map[i][j];
      else dist[i][j] = INF;
    }
  }
  
  // 플로이드-워셜
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(dist[i][j] == INF) 
        cout << 0 << ' ';
      else 
        cout << 1 << ' ';
    }
    cout << "\n";
  }
}