// Writer : exzile_27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define pll pair<ll, ll>

/*
일단 마지막 행 두개가 비어있으면 교환이 성립한다
그러면 N^2*(N^2-2) 개는 채워도 됨
이후에 어떻게 채울까가 문제인데

최대 1600칸
일단 800개로 생각해도 2^800이면 터지고
백트가 안된다
흐응으으으으ㅡㅇ

6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1

마지막 두줄이고

6으로 넣으면 2는 확정임 사실
그러면 2로 인해서 다른칸에 2가 확정됨
그러면 1확정되고 4가 확정 5가확정 5로인해 6이 확정

그러면 살짝 순싸분인데 이거

pos로 위치 저장해두고 넘어가면 될듯


*/

int N, ans;
int board[1605][1605];
int uPos[1605]; // 마지막 두줄중에 위에꺼 위치

void solve() {
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        for (int j = 0; j < N * N; j++) {
            cin >> board[i][j];
        }
    }

    ans = N * N * (N * N - 2); // 마지막 두줄 빼고

    for (int j = 0; j < N * N; j++) {
        int curU = board[N*N-2][j];
        uPos[curU] = j;
    }

    int cnt = 0; // 채워진 개수 N^2개면 확정
    bool visited[1605]{};

    for(int j = 0; j < N*N; j++) {
        ans++;
        if(visited[j]) continue;
        visited[j] = true;
        
        int curU = board[N*N-2][j];
        int x = board[N*N-1][j];
        int cycleCnt = 1;

        // cout << "curU : " << curU << " x : " << x << '\n';

        while(true) {
            int nx = uPos[x];
            visited[nx] = true;
            x = board[N*N-1][nx];
            cycleCnt++;

            if(curU == x) break;
        }

        cnt += cycleCnt;
        // cout << cnt << '\n';

        if(cnt == N*N) {
            break;
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
