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

/*

*/


void solve(){
    int N, M; cin >> N >> M;
    int board[1005][1005];

    int x = 1;
    for(int i = 0; i < N/2; i++) {
        for(int j = 0; j < M/2; j++) {
            board[i][j] = board[i+N/2][j] = board[i][j+M/2] = board[i+N/2][j+M/2] = x;
            x++;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
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