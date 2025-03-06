#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

int N;
char board[1005][1005];
// R L D U
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isIn(int a, int b) {
    return (a >= 0 && a < N && b >= 0 && b < N);
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < N; j++) {
            board[i][j] = s[j];
        }
    }

    pii heart;
    bool flag = false;
    for(int i = 1; i < N - 1; i++) {
        if(flag) break;
        for(int j = 1; j < N - 1; j++) {
            if(board[i][j] == '*' && board[i - 1][j] == '*' && board[i][j - 1] == '*' && board[i][j + 1] == '*' && board[i + 1][j] == '*') {
                heart = {i, j};
                flag = true;
                break;
            }
        }
    }

    cout << heart.X + 1 << ' ' << heart.Y + 1 << '\n';
    
    int leftArm = 0, rightArm = 0, waist = 0, leftLeg = 0, rightLeg = 0;
    
    // 왼쪽 팔
    for (int j = heart.Y - 1; j >= 0 && board[heart.X][j] == '*'; j--) leftArm++;
    
    // 오른쪽 팔
    for (int j = heart.Y + 1; j < N && board[heart.X][j] == '*'; j++) rightArm++;
    
    // 허리
    for (int i = heart.X + 1; i < N && board[i][heart.Y] == '*'; i++) waist++;
    
    int waistEnd = heart.X + waist;
    
    // 왼쪽 다리
    for (int i = waistEnd + 1; i < N && board[i][heart.Y - 1] == '*'; i++) leftLeg++;
    
    // 오른쪽 다리
    for (int i = waistEnd + 1; i < N && board[i][heart.Y + 1] == '*'; i++) rightLeg++;
    
    cout << leftArm << ' ' << rightArm << ' ' << waist << ' ' << leftLeg << ' ' << rightLeg << '\n';
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
