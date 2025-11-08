#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

/*


*/

int N, M;
char board[20][20];
vector<pii> target;
pii player;
// D U R L
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void move(int x) {
    // 플레이어가 이동이 가능한가를 보기
    // 벽이거나 박스박스거나 박스벽이면 불가능
    int nx = player.X + dx[x];
    int ny = player.Y + dy[x];

    if(board[nx][ny] == '#') return;
    if(board[nx][ny] == 'b') {
        // 박스 다음칸이 벽이거나 박스면 안됨
        int nnx = nx + dx[x];
        int nny = ny + dy[x];
        if(board[nnx][nny] == 'b' || board[nnx][nny] == '#') return;

        board[player.X][player.Y] = '.';
        board[nx][ny] = 'w';
        player = {nx, ny};
        board[nnx][nny] = 'b';
        return;
    }
    
    board[player.X][player.Y] = '.';
    board[nx][ny] = 'w';
    player = {nx, ny};
}

// 게임이 끝났는가
bool check() {
    for(auto &[x, y] : target) {
        if(board[x][y] != 'b') {
            return false;
        }
    }
    return true;
}


void solve() {
    target.clear();
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < M; j++) {
            if(s[j] == 'W') {
                board[i][j] = 'w';
                player = {i, j};
                target.push_back({i,j});
            }
            else if(s[j] == 'w') {
                player = {i, j};
            }
            else if(s[j] == 'B') {
                board[i][j] = 'b';
                target.push_back({i, j});
            }
            else if(s[j] == '+') {
                board[i][j] = '.';
                target.push_back({i, j});
            }
            else board[i][j] = s[j];
        }
    }

    string cmd; cin >> cmd;
    for(char &c : cmd) {
        if(c == 'D') move(0);
        else if(c == 'U') move(1);
        else if(c == 'R') move(2);
        else move(3);

        
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < M; j++) {
        //         cout << board[i][j];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        if(check()) break;
    }

    bool isOk = true;
    for(auto &[x, y] : target) {
        if(board[x][y] == '.') {
            isOk =false;
            board[x][y] = '+';
        }
        else if(board[x][y] == 'w') {
            isOk = false;
            board[x][y] = 'W';
        }
        else if(board[x][y] == 'b') {
            board[x][y] = 'B';
        }
    }

    cout << (isOk ? "complete" : "incomplete") << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // int Tc=1;
    // cin >> Tc;
    // while (Tc--) solve();

    int x = 1;
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cout << "Game " << x++ << ": ";
        solve();
    }
    return 0;
}