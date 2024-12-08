#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>


void solve(){
    int K, M, N;
    char board[1005][1005];
    bool visited[1005][1005];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    pii start;
    unordered_map<char, int> mp; // 전투선 무력화 걸리는 시간

    memset(visited, false, sizeof(visited));

    cin >> K >> M >> N;
    for(int i = 0; i < K; i++) {
        char x; int y;
        cin >> x >> y;
        mp.insert({x, y});
    }

    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < M; j++) {
            board[i][j] = s[j];
            if(board[i][j] =='E') {
                start = {i, j};
            }
        }
    }

    priority_queue<pair<int, pii>> pq;
    pq.push({0, start});
    visited[start.X][start.Y] = true;

    int ans = INT_MAX;
    while(!pq.empty()) {
        int cost = -pq.top().X;
        int x = pq.top().Y.X;
        int y = pq.top().Y.Y;
        pq.pop();

        // cout << x << ' ' << y << ' ' << cost << '\n'; 

        if(x == 0 || x == N - 1 || y == 0 || y == M - 1) {
            ans = min(ans, cost);
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nxtCost = cost + mp[board[nx][ny]];

            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            pq.push({-nxtCost, {nx, ny}});
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc; cin >> Tc;
    while(Tc--) {
        solve();
    }

    return 0;
}