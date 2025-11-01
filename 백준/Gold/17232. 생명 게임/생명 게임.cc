/*
writter : exzile_27
*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ld long double

int N, M, T;
int K, a, b;
int board[105][105];
int ps[105][105];

int get(pii a, pii b) {
    int result = ps[b.X][b.Y];
    result -= ps[a.X - 1][b.Y];
    result -= ps[b.X][a.Y - 1];
    result += ps[a.X - 1][a.Y - 1];
    return result;
}

void solve(){
    cin >> N >> M >> T;
    cin >> K >> a >> b;

    for(int i = 1; i <= N; i++) {
        string s; cin >> s;
        for(int j = 1; j <= M; j++) {
            board[i][j] = (s[j - 1] == '*' ? 1 : 0);
        }
    }

    // 매턴마다 누적합 구하기 각 점마다 쿼리 10000개고
    // 2NM만에 다음턴 구하기 끝
    int nBoard[105][105];
    for(int i = 0; i < T; i++) {

        // 누적합
        for(int i = 0; i <= N; i++) ps[i][0]=0;
        for(int j = 0; j <= M; j++) ps[0][j]=0;
        for(int i = 1; i <= N; i++){
            int rowSum = 0;
            for(int j = 1; j <= M; j++){
                rowSum += board[i][j];
                ps[i][j] = ps[i-1][j] + rowSum;
            }
        }
        
        // 각 점에서 O(1)로 주위 개수 찾기
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                pii st = {max(i-K, 1), max(j-K, 1)};
                pii ed = {min(i+K, N), min(j+K, M)};
    
                int curCnt = get(st, ed) - (board[i][j]);

                if(board[i][j] == 1) {
                    if(a <= curCnt && curCnt <= b) nBoard[i][j] = 1;
                    else nBoard[i][j] = 0;
                }
                else {
                    if(a < curCnt && curCnt <= b) nBoard[i][j] = 1;
                    else nBoard[i][j] = 0;
                }
            }
        }

        // 붙여넣기
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                board[i][j] = nBoard[i][j];
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << (board[i][j] == 1 ? '*' : '.');
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    for (int tt = 1; tt <= Tc; tt++) {
        solve();
    }
 
    return 0;
}