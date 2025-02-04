#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first 
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
int board[25][25];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool L[405][405];

void solve() {
    cin >> N;
    memset(board, -1, sizeof(board));

    for (int i = 1; i <= N * N; i++) {
        int cur; cin >> cur;

        for (int j = 0; j < 4; j++) {
            int x; cin >> x;
            L[cur][x] = true;
        }

        int posX = -1, posY = -1;
        int maxLike = -1, maxVacant = -1;

        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                if (board[x][y] != -1) continue;
                int curVac = 0, curLike = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx <= 0 || nx > N || ny <= 0 || ny > N)
                        continue;

                    if (board[nx][ny] == -1) curVac++;
                    else if (L[cur][board[nx][ny]]) curLike++;
                }

                if (maxLike < curLike) {
                    posX = x; posY = y; maxLike = curLike; maxVacant = curVac;
                }
                else if (maxLike == curLike && maxVacant < curVac) {
                    posX = x; posY = y; maxLike = curLike; maxVacant = curVac;
                }
                else if (maxLike == curLike && maxVacant == curVac) {
                    if (posX > x) { posX = x; posY = y; maxLike = curLike; maxVacant = curVac; }
                    else if (posX == x && posY > y) { posX = x; posY = y; maxLike = curLike; maxVacant = curVac; }
                }
            }
        }
        board[posX][posY] = cur;
    }

    int ans = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            int cur = board[x][y];
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;

                if (L[cur][board[nx][ny]]) cnt++;
            }
            if (cnt > 0) ans += pow(10, cnt - 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }

    return 0;
}
