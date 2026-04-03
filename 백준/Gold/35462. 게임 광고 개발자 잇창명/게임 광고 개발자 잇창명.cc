// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
모든 상황에서 항상 1-based로 통일
*/

pii board[205][205]; // := x, y에 i번째 화살표의 j번째 위치가 있음 1-based
vector<pair<pii, int>> last; // i번째의 마지막 위치, 방향
vector<set<int>> indeg; // 여러번 겹칠 수 있기 때문에 set으로 관리
vector<set<int>> adj;  // 빼고 연결된 놈들 지우기 위함
queue<int> q; // indeg가 0인 놈들
// D R U L
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int makeDirIdx(char c) {
    if(c == 'D') return 0;
    else if(c == 'R') return 1;
    else if(c == 'U') return 2;
    else return 3;
}

void solve() {
    int N, M, K; cin >> N >> M >> K;

    // init
    last.resize(K + 1);
    indeg.resize(K + 1);
    adj.resize(K + 1);
    for(int i = 1; i <= K; i++) {
        indeg[i].clear();
        adj[i].clear();
    }
    while(!q.empty()) q.pop();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            board[i][j] = {-1, -1};
        }
    }

    for(int i = 1; i <= K; i++) {
        int r, c, l; string s;
        cin >> r >> c >> l;
        cin >> s;

        int curX = r, curY = c;
        int cnt = 1;
        // 찍고 이동하기
        for(char &c : s) {
            board[curX][curY] = {i, cnt++};

            int dirIdx = makeDirIdx(c);

            curX += dx[dirIdx];
            curY += dy[dirIdx];
        }

        // 마지막 찍기
        last[i] = {{curX, curY}, makeDirIdx(s.back())};
        board[curX][curY] = {i, cnt};
    }

    // // debug
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= M; j++) {
    //         cout << '(' << board[i][j].X << ", " << board[i][j].Y << ") ";
    //     }
    //     cout << '\n';
    // }

    // for(int i = 1; i <= K; i++) {
    //     cout << last[i].X.X << ' ' << last[i].X.Y << ' ' << last[i].Y << '\n';
    // }

    // 이제 DAG를 구성하면서 하나씩 뺄거임
    // last기준 뻗으면서 만나는거 indeg더하고
    // 본인이라면 나갈 수 있는지만 체크하고 넘어가기 본인을 못 넘으면 무조건 실패
    for(int i = 1; i <= K; i++) {
        int x = last[i].X.X;
        int y = last[i].X.Y;
        int dir = last[i].Y;
        int moveCnt = 0;

        // dir로 벗어날때까지 반복
        while(true) {
            x += dx[dir];
            y += dy[dir];
            moveCnt++;

            if(x < 1 || x > N || y < 1 || y > M) break;
            
            if(board[x][y].X == -1) continue;

            // 같은 선
            if(board[x][y].X == i) {
                if(moveCnt <= board[x][y].Y) { // 못넘음
                    cout << "No\n";
                    return;
                }
            }
            else { // 다른선
                int otherLineIdx = board[x][y].X;
                if(indeg[i].insert(otherLineIdx).Y) adj[otherLineIdx].insert(i);
            }
        }
    }

    // //debug
    // cout << "indeg\n";
    // for(int i = 1; i <= K; i++) {
    //     cout << i << ": ";
    //     for(auto iter = indeg[i].begin(); iter != indeg[i].end(); iter++) {
    //         cout << *iter << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << "adj\n";
    // for(int i = 1; i <= K; i++) {
    //     cout << i << ": ";
    //     for(int j = 1; j <= K; j++) {
    //         if(adj[i][j]) cout << j << ' ';
    //     }
    //     cout << '\n';
    // }

    // 여기까지 DAG가 구성됨 이제 위상정렬
    for(int i = 1; i <= K; i++) {
        if(indeg[i].size() == 0) q.push(i);
    }

    int popCnt = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        popCnt++;

        // cout << "cur : " << cur << '\n';

        // 지금뺀놈기준 adj보고 없애면서 큐에넣기
        for(int i : adj[cur]) {
            // cout << "i : " << i << ' ';
            indeg[i].erase(cur);

            // cout << indeg[i].size() << '\n';
            if(indeg[i].size() == 0) q.push(i);
        }
    }

    cout << (popCnt == K ? "Yes" : "No") << '\n'; 

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}