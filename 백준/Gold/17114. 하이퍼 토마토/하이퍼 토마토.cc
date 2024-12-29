#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
  int tomato = 0;
  int m, n, o, p, q, r, s, t, u, v, w;
  cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;

  int box[m][n][o][p][q][r][s][t][u][v][w] = {};
  bool visited[m][n][o][p][q][r][s][t][u][v][w] = {};
    
  queue<tuple<int, int, int, int, int, int, int, int, int, int, int>> que;

  // 입력을 받아서 창고 내의 토마토 정보 초기화
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < v; ++j) {
      for (int k = 0; k < u; ++k) {
        for (int l = 0; l < t; ++l) {
          for (int x = 0; x < s; ++x) {
            for (int y = 0; y < r; ++y) {
              for (int z = 0; z < q; ++z) {
                for (int a = 0; a < p; ++a) {
                  for (int b = 0; b < o; ++b) {
                    for (int c = 0; c < n; ++c) {
                      for (int d = 0; d < m; ++d) {
                        int temp; cin >> temp;
                        box[d][c][b][a][z][y][x][l][k][j][i] = temp;

                        if(temp == 1) // 토마토의 위치를 미리 큐에 저장
                          que.push({d,c,b,a,z,y,x,l,k,j,i});
                        
                        if(temp == -1) // 없는자리 방문표시
                          visited[d][c][b][a][z][y][x][l][k][j][i] = true;
                        
                        if(temp == 0) // 몇개가 익어야하는지 저장
                          tomato++; 
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  int maxDate = 0; // 걸린 날짜
  int count = 0; // 익은 토마토 개수
  
  int da[22] = {1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int db[22] = {0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int dc[22] = {0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int dd[22] = {0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int de[22] = {0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int df[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int dg[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0};
  int dh[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0};
  int di[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0};
  int dj[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0};
  int dk[22] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1};

  while (!que.empty()) {
    int a1 = get<0>(que.front());
    int b1 = get<1>(que.front());
    int c1 = get<2>(que.front());
    int d1 = get<3>(que.front());
    int e1 = get<4>(que.front());
    int f1 = get<5>(que.front());
    int g1 = get<6>(que.front());
    int h1 = get<7>(que.front());
    int i1 = get<8>(que.front());
    int j1 = get<9>(que.front());
    int k1 = get<10>(que.front());
    visited[a1][b1][c1][d1][e1][f1][g1][h1][i1][j1][k1] = true;
    que.pop();
    
    for(int i = 0; i < 22; i++){
      int na = a1 + da[i];
      int nb = b1 + db[i];
      int nc = c1 + dc[i];
      int nd = d1 + dd[i];
      int ne = e1 + de[i];
      int nf = f1 + df[i];
      int ng = g1 + dg[i];
      int nh = h1 + dh[i];
      int ni = i1 + di[i];
      int nj = j1 + dj[i];
      int nk = k1 + dk[i];
      
      // 범위내인지 확인
      if(0 <= na && na < m && 0 <= nb && nb < n && 0 <= nc && nc < o && 0 <= nd && nd < p && 0 <= ne && ne < q && 0 <= nf && nf < r && 0 <= ng && ng < s && 0 <= nh && nh < t && 0 <= ni && ni < u  && 0 <= nj && nj < v && 0 <= nk && nk < w){

        // 토마토가 있고 방문하지 않았다면
        if(box[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk] == 0 && !visited[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk]){
          box[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk] = box[a1][b1][c1][d1][e1][f1][g1][h1][i1][j1][k1] + 1;
          que.push({na, nb, nc, nd, ne, nf,ng, nh, ni, nj, nk});
          count++;
          maxDate = max(maxDate, box[na][nb][nc][nd][ne][nf][ng][nh][ni][nj][nk]);
        }
      }
    }
  }

  //정답 출력
  if(tomato == 0) // 이미 다 익었다면
    cout << 0;
  else{ 
    if(count != tomato) // 전부 익지 못했다면
      cout << -1;
    else
      cout << maxDate - 1;
  }
}