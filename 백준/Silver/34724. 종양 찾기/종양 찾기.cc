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
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < M - 1; j++) {
            if(board[i][j] == 1 && board[i+1][j] == 1 && board[i][j+1] == 1 && board[i+1][j+1] == 1) {
                cout << "1";
                return;
            }
        }
    }
    cout << "0";
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