#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

const int MAXN = 25;

int N, M;
string board[MAXN];
int ax, ay, bx, by;
bool vis[MAXN][MAXN][MAXN][MAXN];

int dx[9] = {0, -1,-1,-1, 0, 1, 1, 1, 0};
int dy[9] = {0, -1, 0, 1, 1, 1, 0,-1,-1};

bool in(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void solve() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> board[i];
        for(int j = 0; j < M; j++){
            if(board[i][j] == 'A'){
                ax = i;
                ay = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'B'){
                bx = i; 
                by = j; 
                board[i][j] = '.';
            }
        }
    }

    int tx = bx, ty = by;
    int sx = ax, sy = ay;

    queue<tuple<int,int,int,int,int>> q;
    vis[ax][ay][bx][by] = true;
    q.push({ax, ay, bx, by, 0});

    while(!q.empty()){
        auto [x1,y1,x2,y2,t] = q.front();
        q.pop();

        if(x1 == tx && y1 == ty && x2 == sx && y2 == sy){
            cout << t << '\n';
            return;
        }

        for(int da = 0; da < 9; da++){
            int nx1 = x1 + dx[da];
            int ny1 = y1 + dy[da];

            if(!(da == 0 || (in(nx1,ny1) && board[nx1][ny1] != 'X'))){
                continue;
            }

            if(da == 0){ nx1 = x1; ny1 = y1; }

            for(int db = 0; db < 9; db++){
                if(da == 0 && db == 0) continue; // 하나는 움직이기

                int nx2 = x2 + dx[db];
                int ny2 = y2 + dy[db];

                if(!(db == 0 || (in(nx2,ny2) && board[nx2][ny2] != 'X'))){
                    continue;
                }
                if(db == 0){ nx2 = x2; ny2 = y2; }

                // 같은 칸에서 끝나면 안됨
                if(nx1 == nx2 && ny1 == ny2) continue;

                // 한 턴에 서로의 위치를 바꾸는것은 금지
                if(nx1 == x2 && ny1 == y2 && nx2 == x1 && ny2 == y1) continue;

                if(vis[nx1][ny1][nx2][ny2]) continue;

                vis[nx1][ny1][nx2][ny2] = true;
                q.push({nx1, ny1, nx2, ny2, t+1});
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve();
    }
    return 0;
}