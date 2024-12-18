#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[55][55];
bool visited[55][55];
priority_queue<pair<int, pii>> pq;

void solve(int t) {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0 ; j < M; j++) {
            if(i == 0 || j == 0 || i == N - 1 || j == N - 1) {
                pq.push({-board[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }

    int ans = 0;
    while(!pq.empty()) {
        int h = pq.top().X;
        int x = pq.top().Y.X;
        int y = pq.top().Y.Y;
        pq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            ans += max(0, -(h + board[nx][ny]));
            pq.push({-max(-h, board[nx][ny]), {nx, ny}});
        }
    }

    cout << "Case #" << t << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc; cin >> Tc;
    for(int tt = 1; tt <= Tc; tt++) {
        solve(tt);
    }

    return 0;   
}